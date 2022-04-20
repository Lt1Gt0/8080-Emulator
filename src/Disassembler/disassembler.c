#include "disassembler.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("Invalid Argument Count\n");
        return -1;
    }

    FILE* fp = fopen(argv[1], "r+b");
    
    if (fp == NULL) {
        printf("Invalid File Input\n");
        fclose(fp);
        return -1;
    }
    
    size_t fileSize, i;
    int c;

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    char* buffer = (char*)malloc(sizeof(char) * fileSize);
    printf("sizeof buffer: %d\n", sizeof(buffer));
    printf("filesize: %d\n", fileSize);

    for (i = 0; i < fileSize && (c = fgetc(fp)) != EOF ; i++) {
        printf("%02x", c);
        if (i % 16 == 15)
            putchar('\n');
        else if (i % 2 == 1)
            putchar(' ');
    }

    if (i % 16 == 0)
        putchar('\n');
        
    fclose(fp);
    return 0;
}

// int main ()
// {
//   int n;
//   FILE * pFile;
//   char buffer [27];

//   pFile = fopen ("myfile.txt","w+");
//   for ( n='A' ; n<='Z' ; n++)
//     fputc ( n, pFile);
//   rewind (pFile);
//   fread (buffer,1,26,pFile);
//   fclose (pFile);
//   buffer[26]='\0';
//   puts (buffer);
//   return 0;
// }