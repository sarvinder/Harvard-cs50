#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void initials(string input);

int main(void)
{
    //promt the user for the input
    printf();
    
    //get the input from the user
    string input=get_string();
    
    char initial;
    
    //next go find the first char
    //check if the first char is alpha or not
    if(isalpha(input[0]))
    {
        //the first char is alpha
        initial=input[0] & ~('a'-'A');
        printf("%c",initial);
        initials(input);
    }
    else
    {
        //start from the front to find the initials
        initials(input);
    }
    
}

//This method go from char to char to find the first char in a string
//and print it in capital if it is not already in capital
void initials(string input)
{
    char initial;
    //check for the first char after space
        for(int i=0,j=strlen(input);i<j;i++)
        {
            //check if the char at i is a space
            if(input[i]==32)
            {
                //check if the next char is alpha
                if(isalpha(input[i+1]))
                {
                    //computes the "bitwise and"between the input and ~32
                    //eg: the binary for 'A' is 00100001,doing bitwise and 
                    //with ~32(wich just reverse the bits of 32) gives 
                    //00100001 and doing it with 'a' gives 00100001 which
                    //is 'A'
                    initial=input[i+1] & ~('a'-'A');
                    printf("%c",initial);
                    
                }
            }
        }
        printf("\n");
}