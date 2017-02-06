#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>


void shiftText(int shift,string input);

int main(void){
    
    string input="camel";
    int shift=2;

    shiftText(shift,input);    
    
    
    
}
void shiftText(int shift,string input){
    
    for(int i=0,n=strlen(input);i<n;i++){
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
    }printf("\n");
   
    
}