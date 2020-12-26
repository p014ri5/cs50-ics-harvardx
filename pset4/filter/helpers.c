#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Variable to store average pixel color value
    int avg = 0;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Fetching and storing the color values 
            // To make code look more clean lol
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
        
            // Calculating average pixel color value
            avg = round((r + g + b) / 3.0);
            
            // Applying average pixel color value to each channel
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
}

// Function to cap color values greater than 255
int cap(int value)
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
}

/* Functions for converting color to sepia tone colors using
formula recommended by Microsoft */

int sepia_red(int r, int g, int b)
{
    return cap(round(0.393 * r + 0.769 * g + 0.189 * b));
}

int sepia_green(int r, int g, int b)
{
    return cap(round(0.349 * r + 0.686 * g + 0.168 * b));
}

int sepia_blue(int r, int g, int b)
{
    return cap(round(0.272 * r + 0.534 * g + 0.131 * b));
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Fetching original values
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            
            // Setting sepia tone values
            image[i][j].rgbtRed = sepia_red(r, g, b);
            image[i][j].rgbtGreen = sepia_green(r, g, b);
            image[i][j].rgbtBlue =  sepia_blue(r, g, b);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Initialize temporary variables to store 3 colors
    int tr = 0;
    int tg = 0;
    int tb = 0;
    
    int n = width / 2;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Store original colors in temp variables
            tr = image[i][j].rgbtRed;
            tg = image[i][j].rgbtGreen;
            tb = image[i][j].rgbtBlue;
            
            // Change color of original pixel to that of complementary pixel
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed; // -1 Because Arrays start with 0
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            
            // Change color of complementary pixel to that of original pixel
            image[i][width - j - 1].rgbtRed = tr;
            image[i][width - j - 1].rgbtGreen = tg;
            image[i][width - j - 1].rgbtBlue = tb;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    int tr = 0;
    int tg = 0;
    int tb = 0;
    float c = 0;
    // Temporary table of colors
    RGBTRIPLE table[height][width];
    
    for (int i = 0; i < height; i++)
    {
        // Temporary variables to store total of colors to calculate average
        
        for (int j = 0; j < width; j++)
        {
            tr = 0;
            tg = 0;
            tb = 0;
            c = 0.00;
            
            for (int k = -1; k < 2; k++)
            {
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }
                
                for (int l = -1; l < 2; l++)
                {
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }
                    
                    tr += image[i + k][j + l].rgbtRed;
                    tg += image[i + k][j + l].rgbtGreen;
                    tb += image[i + k][j + l].rgbtBlue;
                    c++;
                }
            }
            table[i][j].rgbtRed = round(tr / c);
            table[i][j].rgbtGreen = round(tg / c);
            table [i][j].rgbtBlue = round(tb / c);
        }
        
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = table[i][j].rgbtRed;
            image[i][j].rgbtGreen = table[i][j].rgbtGreen;
            image[i][j].rgbtBlue = table[i][j].rgbtBlue;
        }
    }
}
