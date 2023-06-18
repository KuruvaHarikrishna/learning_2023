#include <stdio.h>  
int main()  
{  
    int arr[] = {1, 2, 3, 4, 5,6,7,8,9};   
    int sum = 0;  
    int length = sizeof(arr)/sizeof(arr[0]);  
    for (int i = 0; i < length; i=i+2) {   
       sum = sum + arr[i];  
    }    
    printf("Sum of all the elements of an array: %d", sum);  
    return 0;  
}  
