#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


string userInput(void);
void shiftText(int shift,string input);

int main(int argc,string argv[]){
    if(argc==2){
      
        int shift=atoi(argv[1]);
 
        string input=userInput();
         
        shiftText(shift,input);
      
    }else{
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    
    
}
string userInput(void){
    printf("plaintext: ");
    string result=get_string();
    return result;
}



void shiftText(int shift,string input){
    printf("ciphertext: ");
    for(int i=0,n=strlen(input);i<n;i++){
        if(isalpha(input[i])){
          if(isupper(input[i])){
                //printf("Its uppercase");
                int pi=input[i]-65;
                int ci=(pi+shift)%26;
                printf("%c",65+ci);
            
            }
            else{
                int pi=input[i]-97;
                int ci=(pi+shift)%26;
                printf("%c",97+ci);
                //printf("is lower");
            }
        }else{
            printf("%c",input[i]);
        }
        
        
    }
    printf("\n");
    
}

