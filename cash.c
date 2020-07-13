#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float a;  //initializes float
    int count = 0;
    
    do
    {
        a = get_float("Change owed:\n");  //requires valid user input
    }
    while (a <= 0);
    
    int r = round(a * 100);  //rounds change
   
    while (r != 0)
    {
        if (r % 25 >= 0)  //checks against quarters
        {
            count = count + r / 25;
            r = round(r % 25);
            if (r % 10 >= 0)  //checks against dimes
            {
                count = count + r / 10;
                r = round(r % 10);
                if (r % 5 >= 0)  //checks against nickels
                {
                    count = count + r / 5;
                    r = round(r % 5);
                    if (r % 1 >= 0) //cheks against pennies
                    {
                        count = count + r / 1;
                        r = round(r % 1);
                    }
                }
            }
        }
        

        else
        {
            printf("It didn't work"); //basic troubleshooter
        }
    }
   
    printf("%i \n", count);  //prints change
    
}