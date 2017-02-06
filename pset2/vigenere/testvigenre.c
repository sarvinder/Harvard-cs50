#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(void)
{/*
    string s="hello";
    printf("%lu\n",strlen(s));*/
    int counter=1;
    string key="AbC";
     char key1=toupper(key[counter]);
     int key2=key1-65;
     printf("%i\n" ,key2);    
}