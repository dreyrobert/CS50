#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int isJPEG(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./recover file.raw\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *raw = fopen(infile, "r");
    if (raw == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    char filename[8];
    FILE *image;
    int counter = 0;

    while (fread(buffer, BLOCK_SIZE, 1, raw) == 1)
    {
        if (isJPEG(buffer) == 1)
        {
            if (counter != 0)
            {
                fclose(image);
            }
            // sprintf é para nomear o arquivo que você ta escrevendo.
            sprintf(filename, "%03i.jpg", counter++);
            image = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }

        else if (counter >0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }
}

//Verifica se o que você está lendo é JPEG.
int isJPEG(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}