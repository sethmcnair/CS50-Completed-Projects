#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count_letters(char sentence[])
{
    int l = strlen(sentence);
    int nn = 0;
    for (int i = 0; i < l; i++)
    {
        int j = isalpha(sentence[i]);
        if (j == 0)
        {
            nn++;
        }
    }
    return l - nn;
}

int count_words(char sentence[])    //Function counts words of given input
{
    int g = strlen(sentence);
    int k;
    int count1 = 0;
    for (k = 0; k < g; k++)
    {
        if (sentence[k] == ',') //  counts commas
        {
            count1++;
            k++;
        }
        else if (sentence[k] == '.') //  counts periods
        {
            count1++;
            k++;
        }
        else if (sentence[k] == '?') //  counts questionmarks
        {
            count1++;
            k++;
        }
        else if (sentence[k] == '!') //  counts exclamation points
        {
            count1++;
            k++;
        }
        else if (sentence[k] == ' ') //  counts spaaces
        {
            count1++;
            k++;
        }
        else if (sentence[k] == '\0') // counts null characters
        {
            count1++;
            k++;
        }
    }
    return count1;
}

int count_sentence(char sentence[]) //function counts sentences of given input
{
    int a = strlen(sentence);
    int b;
    int count2 = 0;
    for (b = 0; b < a; b++)
    {
        if (sentence[b] == '.') // counts periods
        {
            count2++;
        }
        else if (sentence[b] == '!') // counts exclamation points
        {
            count2++;
        }
        else if (sentence[b] == '?') // counts question marks
        {
            count2++;
        }
    }
    return count2;
}

double colemanIndex(char sentence[]) // calculates coleman index
{
    float words = count_words(sentence);
    float sens = count_sentence(sentence);
    float lets = count_letters(sentence);;
    float avgSens = (sens * 100) / words;
    float avgLets = (lets * 100) / words;
    float sensf = avgSens * 0.296;
    float letsf = avgLets * 0.0588;
    double index = (letsf - sensf) - 15.8;
    return index;
}

int main(void)  //Main FUNCTION
{
    char str[1000];
    printf("Enter Text: ");
    scanf(" %[^\n]", str);
    int z = round(colemanIndex(str));
    if (z < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (z <= 16)
    {
        printf("Grade %i\n", z);
    }
    else if (z > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("It didn't work");
    }
}