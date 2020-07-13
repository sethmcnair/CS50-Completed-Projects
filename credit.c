#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    string ae = "American Express";
    string m = "Mastercard";
    string v = "Visa";
    long num;
    do
    {
    num = get_long("CC Number: ");
    }
    while(num < 1000000000000);
    
    int test = num % 100;
    printf(test[1]);
}