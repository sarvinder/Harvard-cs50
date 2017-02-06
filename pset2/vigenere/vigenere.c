#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

//prototype of all methods
bool validKey(string Key);
string getPlainText(void);
void cipherText(string Key,string input);
int getKey(char key);


int main(int argc,string argv[])
{
    //get the input from the command line
    //the input should be exactly two arguments
   //if not then it is an error
    if(argc!=2){
        printf("enter the correct key k\n");
        return 1;
    }
    else
    {
        //check if the (KEY)input is valid or not
        bool result=validKey(argv[1]);
        //test bool
        if(result==true)//if true the the key is valid
        {
             //  printf("true\n");
        
             string plainText=getPlainText();
            // printf("The plaintext is %s\n",plainText);
           
             cipherText(argv[1],plainText);  
            
        }
        else//the key is not valid
        {
         
            printf("false\n");
            return 1;
        }
        
        
    }
        
}

/**
 * Check if the entered key is valid or not
 */
 bool validKey(string Key)
 {
    //Iterate over each character of the Key and check if its valid or not by using (isalpha)
    for(int i=0,n=strlen(Key);i<n;i++){
        if(isalpha(Key[i])==false)
        {
            return false;
        }
    }    
     return true;
     
 }


/**
 *  Get the input from the user 
 */
 string getPlainText(void)
 {
     printf("plaintext: ");
     string message="";
     do
     {
         message=get_string();
     }while(message==NULL);
     
     return message;
 }
 
 /**
  * this cipher the plain text
  */
  void cipherText(string key,string input)
  {
    //the counter will help in moving through the key
    int counter=0;
      
    printf("ciphertext: ");
    for(int i=0,n=strlen(input);i<n;i++){
    
        if(isalpha(input[i])){
    
          if(isupper(input[i])){
                //printf("Its uppercase");
                int pi=input[i]-65;
                int k=getKey(key[counter]);
                int ci=(pi+k)%26;
                printf("%c",65+ci);
                if(counter==strlen(key)-1)
                {
                    counter=0;    
                }
                else
                {
                    counter++;    
                }
            
            }
            else{
                int pi=input[i]-97;
                int k=getKey(key[counter]);
                int ci=(pi+k)%26;
                printf("%c",97+ci);
                //printf("is lower");
                if(counter==strlen(key)-1)
                {
                    counter=0;    
                }
                else
                {
                    counter++;    
                }
            }
        }else{
            printf("%c",input[i]);
        }
        
        
    }
    printf("\n");
      
      
      
  }
/**
 * returns the alphabatical value of the character in key
 * it treats small a and big a as one
 */
 int getKey(char key)
 {
     char key1=toupper(key);
     int key2=key1-65;
     return key2;
     
 }
 
 