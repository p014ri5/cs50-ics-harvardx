#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for two arguments
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }
    
    // Open file in read mode
    FILE *file = fopen(argv[1], "r");
    
    // Check if unable to open file
    if (file == NULL)
    {
        printf("Unable to open image :(\n");
        return 1;
    }
    
    unsigned char buffer[512]; // Buffer two store data
    int count = 0; // Counter to name file
    FILE *image = NULL; // Initialize JPEG file
    int found = 0; // Boolean to store if file is found
    
    // Read until EOF is found
    while (fread(buffer, 512, 1, file) == 1)
    {
        // Check for JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If file is found and stored, close the image else close the file
            if (found == 1)
            {
                fclose(image);
            }
            else
            {
                found = 1;
            }
            
            char filename[8]; // Filename Size = 3 Numbers + .jpg + \0  
            sprintf(filename, "%03d.jpg", count); // Create and JPEG file
            image = fopen(filename, "a"); // Open file in append mode
            count++; // Increase image count
        }
        
        if (found == 1)
        {
            fwrite(&buffer, 512, 1, image); // Append chunk of data in JPEG file
        }
    }
    
    fclose(file); // Close the forensic image file
    fclose(image); // Close the JPEG file
}