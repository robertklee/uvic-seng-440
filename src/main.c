#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "include/dct.h"

int main(int argc, char** argv)
{
    // Handle command-line arguments
    const char *const invalid_argument = "Requires three arguments: filepath, width, height. Filepath must point to an 8-bit grayscale image.";
    if (argc != 4)
    {
        printf(invalid_argument);
        exit(-1);
    }

    const char * const filepath_arg = argv[1];
    const char * const width_arg = argv[2];
    const char * const height_arg = argv[3];

    long width = strtol(width_arg, NULL, 10);
    if (errno == ERANGE || width <= 0)
    {
        printf(invalid_argument);
        exit(-1);
    }
    long height = strtol(height_arg, NULL, 10);
    if (errno == ERANGE || height <= 0)
    {
        printf(invalid_argument);
        exit(-1);
    }

    if (width % 8 != 0 || height % 8 != 0)
    {
        printf("Width and height of image must both be integer multiples of 8.");
        exit(-1);
    }

    // Open input file
    FILE *image_fptr = fopen(filepath_arg, "r");
    if (image_fptr == NULL)
    {
        printf("Cannot open specified file for reading.");
        exit(-1);
    }

    // Allocate memory for loading file data
    size_t count = width * height;
    void *image_dataptr = malloc(sizeof(int8_t) * count);
    if (image_dataptr == NULL)
    {
        printf("Not enough memory to load image.");
        exit(-1);
    }

    // Load file data
    fread(image_dataptr, sizeof(int8_t), count, image_fptr);

    // Close input file
    fclose(image_fptr);

    // Perform DCT on loaded data
    dct((int8_t*) image_dataptr, width, height);

    // Free memory
    free(image_dataptr);

    // Return success
    return 0;
}