#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverseWords(char* s) 
{
    // Step 1: Tokenize the input string
    char* words[1000]; // Assuming there are at most 1000 words
    int numWords = 0;

    char* token = strtok(s, " ");
    for (; token != NULL; token = strtok(NULL, " ")) 
    {
        words[numWords++] = token;
    }

    // Step 2: Reverse the order of words
    int left = 0;
    int right = numWords - 1;

    for (; left < right; left++, right--) 
    {
        char* temp = words[left];
        words[left] = words[right];
        words[right] = temp;
    }

    // Step 3: Concatenate words with a single space
    int resultLength = 0;
    for (int i = 0; i < numWords; i++) 
    {
        resultLength += strlen(words[i]) + 1; // +1 for the space between words
    }

    char* result = (char*)malloc(resultLength);
    int currentIndex = 0;
    for (int i = 0; i < numWords; i++) 
    {
        strcpy(&result[currentIndex], words[i]);
        currentIndex += strlen(words[i]);
        if (i < numWords - 1) 
        {
            result[currentIndex++] = ' '; // Add a space between words
        }
    }

    return result;
}
int main()
{
    char s1[] = "the sky is blue";
    char* result1 = reverseWords(s1);
    printf("Output: \"%s\"\n\n", result1);
    free(result1);

    char s2[] = "  hello world  ";
    char* result2 = reverseWords(s2);
    printf("Output: \"%s\"\n\n", result2);
    free(result2);

    char s3[] = "a good   example";
    char* result3 = reverseWords(s3);
    printf("Output: \"%s\"\n", result3);
    free(result3);
    return 0;
}
