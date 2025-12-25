#include <stdio.h>
#include <string.h>

int main(void)
{
    char text_line[10000];
    
    while (fgets(text_line, sizeof(text_line), stdin))
    {
        int len = strlen(text_line);
        
        // Remove newline if present
        if (len > 0 && text_line[len - 1] == '\n')
        {
            text_line[len - 1] = '\0';
            len--;
        }
        
        int i;
        int word_start = 0;
        
        for (i = 0; text_line[i] != '\0'; i++)
        {
            if (text_line[i] == ' ')
            {
                for (int j = i - 1; j >= word_start; j--)
                {
                    putchar(text_line[j]);
                }
                putchar(text_line[i]);
                word_start = i + 1;
            }
        }
        
        // The last word
        for (int j = i - 1; j >= word_start; j--)
        {
            putchar(text_line[j]);
        }
        putchar('\n');
    }
    
    return 0;
}