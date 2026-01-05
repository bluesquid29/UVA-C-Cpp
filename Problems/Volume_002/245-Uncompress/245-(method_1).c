#include <stdio.h>
#include <string.h>  // strcpy
#include <ctype.h>   // isalpha, isdigit
#include <stdbool.h> // bool

// Word stack (like a Jenga tower)
char words[10000][50];
int word_cnt = 0;

void Extract_and_Restack(int n)
{
    int extracted_idx = word_cnt - n;
    int top_idx = word_cnt - 1;

    char extracted[50];
    strcpy(extracted, words[extracted_idx]);

    // Remove from original position (shift elements forward)
    for (int i = extracted_idx; i < top_idx; i++) 
    {
        strcpy(words[i], words[i + 1]);
    }

    // Restack to top
    strcpy(words[top_idx], extracted);

    // Output the word
    printf("%s", extracted);
}

int main(void)
{
    int ch;
    char current_word[50];
    int word_len = 0;
    int num = 0;
    bool is_number = false;

    while ((ch = getchar()) != EOF) 
    {

        if (isalpha(ch)) 
        {
			current_word[word_len++] = ch;   
        }
        else if (isdigit(ch)) 
        {
            num = num * 10 + (ch - '0');
            is_number = true;
        }
        else 
        {
            // Finish a word if we were building one
            if (word_len > 0) 
            {
                current_word[word_len] = '\0';
                printf("%s", current_word);
                strcpy(words[word_cnt++], current_word);
                word_len = 0;
            }

            // Process number
            if (is_number) 
            {
                if (num == 0) break;
            
                Extract_and_Restack(num);
                num = 0;
                is_number = false;
            }

            // Output non-alphanumeric character
            printf("%c", ch);
        }
    }

    return 0;
}
