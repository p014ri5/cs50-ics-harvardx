#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Prototyping Functions
int count_letters(int length, string text);
int count_words(int length, string text);
int count_sents(int length, string text);

// Main Function
int main(void)
{
    // Gets Text from user
    string text = get_string("Text: ");
    // Length of given text
    int length = strlen(text);
    
    // Getting Letters, Words and Sentences
    int letters = count_letters(length, text);
    int words = count_words(length, text);
    int sentences = count_sents(length, text);
    
    // Calculating `l` and 's' for formula substitution
    float l = (float)letters / (float)words * 100;
    float s = (float)sentences / (float)words * 100;
    
    // Calculating Coleman-Liau Index
    float index = 0.0588 * l - 0.296 * s - 15.8;
    // Rounding the Grade
    int grade = round(index);

    // Using conditionals to determine output
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Function to count letters in a sentence
int count_letters(int length, string text)
{
    int l = 0;
    for (int c = 0; c < length; c++)
    {
        if (isalpha(text[c]))
        {
            l++;
        }
    }
    return l;
}

// Function to count words
int count_words(int length, string text)
{
    int s = 0;
    for (int c = 0; c < length; c++)
    {
        if (isspace(text[c]))
        {
            s++;
        }
    }
    return s + 1;
}

// Function to count sentences
int count_sents(int length, string text)
{
    int sents = 0;
    for (int c = 0; c < length; c++)
    {
        if (text[c] == '.' || text[c] == '!' || text[c] == '?')
        {
            sents++;
        }
    }
    return sents;
}