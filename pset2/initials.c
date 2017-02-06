#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

void computeInitials(string s);

int main(void){
    
    //Get the name from the user
    string name=get_string();
    computeInitials(name);
   
}

//This method given the string computes the initials and return them
void computeInitials(string s){
     printf("%c",toupper(s[0]));
    for(int i=0,n=strlen(s);i<n;i++){
         if((int)s[i]==32){
                printf("%c",toupper(s[i+1]));
        }
        
    }printf("\n");
    
   
    
}