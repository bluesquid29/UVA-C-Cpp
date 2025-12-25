#include <iostream>
using namespace std;
 
int main()
{
    string text_line;
 
    while (getline(cin, text_line))
    {
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