#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; //initializes var height
    
    do
    {
        height = get_int("how tall?\n");  //asks for positive input into height variable
    }
    while (height < 1);   // requires positive input
    
    for (int i = 0; i < height; i++)    //increments hashes Y
    {
        for (int p = height - 1; p > i; p--)   //increments spaces
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++)   //increments hashes X
        {
            printf("#");
        }
        printf("\n");
    }
}