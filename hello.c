#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n"); //Prompts user for their name
    printf("hello, %s\n", name); //Prints "hello "user""
}