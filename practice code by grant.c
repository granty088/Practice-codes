#include <stdio.h>

int main() 
{


    // arrays

 double prices[] //princes can be anything = { 1.99, 2.99, 3.99, 4.99, 5.99, 22 };

    for(int i = 0; i < 5; i++)
    {
        printf("Price of item %d: $%.2lf\n", i+1, prices[i]);
    }

    /*printf("%d bytes\n", sizeof(prices));*/

     for(int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++)
    {
        printf("Price of item %d: $%.2f\n", i+1, prices[i]);
    }
   printf("\n");
   


   //im also mastering the for loop
   

   for(int i = 0 /*whats the starting number*/; i < 10 /*whats the ending number*/;
    i++ //increment
    )
{
    printf("%d\n", i);
}
 /* <windows.h>

Sleep(1000); //sleep for 1 second
*/
   
//while loop



    return 0;
}

