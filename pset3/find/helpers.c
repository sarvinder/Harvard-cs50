/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"
#define MAX  65536

bool searchValue(int value, int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n<0){
        return false;
    }
    if(searchValue(value,values,n)==true){
        return true;
    }
    // TODO: implement a searching algorithm
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   int thevalue=0;
   //create the counting array
   int count[MAX];
   for(int i=0;i<MAX;i++){
       count[i]=0;
   }
   
   //put the values elements in the counter 
   //Take the element from the values and at
   //that index in count increment the value
   for(int i=0;i<n;i++){
       thevalue=values[i];
       count[thevalue]++;
   }
   int i=0,k=0;
   //fill the orignal array back with sorted array
   while(i<MAX){
      // printf("%i\n",count[i]);
       if(count[i]==0){
           i++;
       }else{
           for(int j=0;j<count[i];j++){
              values[k]=i;
              k++;
               
           }i++;
       }
   }
    // TODO: implement an O(n^2) sorting algorithm
    return;
}

//My Methods

bool searchValue(int value,int values[],int n){
    
    int lower=0;
    int higher=n-1;
    int mid=0;
    //The middle of the array
    
    if(n<0)
    {
        return false;    
    }
    
    while(n>=0){
         mid=(lower+higher)/2;
    
        if(values[mid]==value){
            return true;
        }else if(values[mid]>value){
            //our number is on the left half
            higher=mid-1;
            n--;
        }else{
            lower=mid+1;
            n--;
        }
        
    }
    
    return false;
}

