#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseWords(char* w) 
{
    int i, j, b = 0, len;
    len = strlen(w);
    char* new = (char*)malloc(sizeof(char) * (len + 1));
    char* w1 = (char*)malloc(sizeof(char) * (len + 1));
    const char delimeter[] = " ";
    i = len - 1;

    for (; i >= 0; i--) 
    {
        if (w[i] == ' ') 
        {
            j = i + 1;
            for (; j < len; j++) 
            {
                new[b] = w[j];
                b++;
            }
            new[b] = ' ';
            b++;
            len = i;
        }
    }

    j = 0;
    for (; j < len; j++) 
    {
        new[b] = w[j];
        b++;
    }
    new[b] = '\0';

    int k = 0;
    char* token = strtok(new, delimeter);
    for (; token != NULL; token = strtok(NULL, delimeter)) 
    {
        for (int idx = 0; token[idx] != '\0'; idx++) 
        {
            w1[k] = token[idx];
            k++;
        }
        w1[k] = ' '; 
        k++;
    }
    k--; 
    w1[k] = '\0';

    free(new);
    return w1;
}

int main() 
{
    char w[100] = "the sky is    blue";
    char* rev = reverseWords(w);
    printf("%s\n", rev);
    free(rev);
    return 0;
}

