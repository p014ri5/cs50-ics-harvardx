#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // init cardnum
    long cardnum = 0;
 
    // get number

    do
    {
        cardnum = get_long("Number: ");
    }
    while (cardnum < 0);

    // check for valid digits
    int counter = 0;
    long digits = cardnum;
    while (digits > 0)
    {
        digits = digits / 10;
        counter++;
    }
    // validate length
    if ((counter != 13) && (counter != 15) && (counter != 16))
    {
        printf("INVALID\n");
    }
    int number[counter];
   
    
    for (int i = 0; i < counter; i++)
    {
        number[i] = cardnum % 10;
        cardnum = cardnum / 10;
    }
    
    int originalnumber[counter];
    for (int i = 1; i < counter; i++)
    {
        originalnumber[i] = number[i];
    }
    
    for (int i = 1; i < counter; i += 2)
    {
        number[i] = number[i] * 2;
    }
    
    int v = 0;
    int temp;
    
    // Guess the card
    if (counter == 13)
    {
        for (int i = 0; i < counter; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalnumber[12] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (counter == 15)
    {
        for (int i = 0; i < counter; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalnumber[14] == 3 && v % 10 == 0 && (originalnumber[13] == 4 || originalnumber[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (counter == 16)
    {
        for (int i = 0; i < counter; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalnumber[15] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else if (originalnumber[15] == 5 && v % 10 == 0 && (originalnumber[14] == 1 || originalnumber[14] == 2 || originalnumber[14] == 3
                 || originalnumber[14] == 4 || originalnumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
  
    return 0;
}    