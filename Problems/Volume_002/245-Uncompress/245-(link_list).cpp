#include <cstdio>
#include <cstring>
#include <cctype>

// Word stack with linked list
struct Node
{
    char word[50];
    int next;
} words[10000];

int word_cnt = 0;
int head = -1;  // -1 means empty list

void Extract_and_Restack(int n)
{
    // Find the node at position n from top
    int cur = head, prev = -1;
    for (int i = 1; i < n; i++)
    {
        prev = cur;
        cur = words[cur].next;
    }

    // Output the word
    printf("%s", words[cur].word);

    // Restack to top (only if not already at head)
    if (cur != head)
    {
        // Unlink from current position
        words[prev].next = words[cur].next;
        
        // Link to head
        words[cur].next = head;
        head = cur;
    }
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
                
                // Add to linked list at head
                strcpy(words[word_cnt].word, current_word);
                words[word_cnt].next = head;
                head = word_cnt;
                word_cnt++;
                
                word_len = 0;
            }

            // Process number
            if (is_number)
            {
                if (num == 0) return 0;
                
                Extract_and_Restack(num);
                num = 0;
                is_number = false;
            }

            // Output non-alphanumeric character
            putchar(ch);
        }
    }

    return 0;
}