/**
 * This is the stanford practice of the BYTES
 * Lecture 2
 */ 
 #include<stdio.h>
 
//void foo(int *p);
 int main(void)
 {
     /*//2's compliment--->WRONG Doesnot WORK
    int x=15 ;
    x=x
     */
     
    /*short s=67;
    char ch=s;
    printf("%c\n",ch);
    */ 
    
    //This is the Kind of example of (INTEGER OVERFLOW)
    /*int i=262144+32768+7;
    printf("%i\n",i);
    short s=i;
    printf("%i\n",s);*/
    
    //after 1 byte (char size) the rest of the bytes are thrown
    //SPOILER ALLERT---> this does not prints Anything
    /* double d=3.1416;
    char ch=*(char *)&d;
    printf("%c\n",ch);*/
    
    //like if i am trying to put 0zzzz after the short is alocated the memory
/*    short s=45;
    double dd=*(double *)&s;
    printf("%f\n",dd);*/
    
    //Size of the void is same as the char
//    printf("%lu\n",sizeof(void));
  
  
  //Array as pointers
 /*  int array[4];
   for(int i=0;i<4;i++)
   {
    array[i]=i;
   }
    foo(array);*/ 
    
    
    printf("Hello World !\n");
    
     return 0;
 }
 
 
 
/* void foo(int *p)
 {
  for(int i=0;i<4;i++)
  {
   printf("%i\n",*p++);
   
  }
 }*/
 