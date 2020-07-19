#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    char filename[8];
    BYTE data[512];
    int count = 0;
    if (argc > 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    FILE *newImage;
    if (file == NULL)
    {
        fclose(file);
        printf("Could not open file\n");
        return 1;
    }
    while (feof(file) == 0)
    {
        fread(&data, sizeof(data), 1, file);
        if ((data[0] == 0xff) && (data[1] == 0xd8) && (data[2] == 0xff) && ((data[3] & 0xf0) == 0xe0))
        {
            sprintf(filename, "%03d.jpg", count);
            newImage = fopen(filename, "w");
            count++;
        }
        if (count > 0)
        {
            fwrite(&data, sizeof(data), 1, newImage);
        }
    }
    fclose(file);
    fclose(newImage);
}