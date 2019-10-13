#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    // Your code here!
    const char *filename = "./PE-1.txt";
    const char *str1 = "I want to learn PE file format!\n";
    char *buf = (char*) calloc(strlen(str1), 1);
    int bufsize = strlen(str1);
    
    FILE* fpr = fopen(filename, "r");
    if(fpr)
	{
        fread(buf, 1, bufsize, fpr);
        fclose(fpr);
        
        if(strcmp(str1, buf) == 0)
        {
            printf("%s", buf);
        }
        else
        {
            FILE* fpw = fopen(filename, "a");
            fwrite(str1, 1, bufsize, fpw);                
            fclose(fpw);
        }
    }
	else
	{
        FILE* fpw = fopen(filename, "w");
        fwrite(str1, 1, bufsize, fpw);
        fclose(fpw);
    }
    return 0; 
}

