#include<stdio.h>
#include<cs50.h>
#include<stdint.h>

//creating the data type for me called byte which is 1 byte long
//the uint8_t is like unsigned char which is 1 byte long
typedef uint8_t BYTE;

int main(int argc,char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy the name of a forensic image from which to recover JPEGs\n");
        return 1;
    }
    
     char *filename=argv[1];
//    printf("the file name is %s\n",filename);
    
    //check if the file opens or not
     FILE *inptr = fopen(filename, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", filename);
        return 2;
    }
    else
    {
        printf("The file opened :\n ");    
       
    }
    
    //read the bytes from the file and store it in buffer
    BYTE buffer[512];
    
    //track the count of the number of jpeg found
    int count=0;
    
    //for the  write file
    FILE *img=NULL;
    
    char makefile[10] ;
    
    //read the pixel line by line
    while(!feof(inptr))
    {
       // printf("got in loop");
        //go back to the starting point
        //fseek(inptr, -512, SEEK_CUR);
        
        //read the line and store it in buffer
        fread(buffer ,1 ,512 ,inptr);
        
        
        //compare the condition
        //if true that means that we found our jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if(img!=NULL)
            {
                fclose(img);
            }
            //update the filename for the nextfile
            sprintf(makefile,"%03d.jpg",count);
            
            img=fopen(makefile,"w");
            if(img==NULL)
            {
                fclose(inptr);
                fprintf(stderr,"could not open the file %s\n",makefile);
                return 3;
            }
             
            count++;
            fwrite(buffer,sizeof(buffer),1,img);
            
              
        }
         //this means this is the last file that we need to close
        else if(count!=0)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
           
        }
    
    }
    
    if(img!=NULL)
    {
        fclose(img);
    }
    
    fclose(inptr);
    return 0;
}

