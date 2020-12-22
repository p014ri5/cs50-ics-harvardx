#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    int n;
    
    // checks for valid user input 
    
    do 
    {
        n = get_int("Height : ");
    }
    while (n < 1 || n > 8);
    
    // column loop
    
    for (int i = 1; i < n + 1; i++)
    {
        // padding loop
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        
        // head blocks loop
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        
        // the gap
        printf("  ");
        
        // trailing blocks loop
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}

