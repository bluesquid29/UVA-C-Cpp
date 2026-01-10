#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 10000;
const int MAXLEN = 50;

struct Node
{
    char word[MAXLEN];
    int next;
} word[N];

int wcnt = 0, head;

int main()
{
    char c;
    c = getchar();
    for(;;)
    {
        if (c == '0')
        {
            break;
        }
        else if (isdigit(c))
        {
            int num = 0;
            while (isdigit(c))
            {
                num *= 10;
                num += c - '0';
                c = getchar();
            }

            int cur = head, prev;
            for(int i = 1; i < num; i++)
            {
                prev = cur;
                cur = word[cur].next;
            }

            printf("%s", word[cur].word);

            if(cur != head)
            {
                word[prev].next = word[cur].next;
                word[cur].next = head;
                head = cur;
            }
        }
        else if (isalpha(c))
        {
            char t[MAXLEN];
            int len = 0;
            while(isalpha(c))
            {
                t[len++] = c;
                c = getchar();
            }
            t[len] = '\0';
            
            printf("%s", t);
            
            strcpy(word[wcnt].word, t);
            word[wcnt].next = head;
            head = wcnt++;
        }
        else
        {
            putchar(c);
            c = getchar();
        }
    }

    return 0;
}