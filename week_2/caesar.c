#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool digits(string s);

int main(int argc, string argv[])
{
    // check argunment counts and the first character that is digit
    if (argc == 2 && digits(argv[1]) == 0)
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        // convert string argv[1] into int
        int n = atoi(argv[1]);
        for (int i = 0, k = strlen(plaintext); i < k; i++)
        {
            if (islower(plaintext[i]))
            {
                // In ascii, why we don't use (plaintext[i] + (n%26)). Because if we input 't' in a
                // string and argv=13, it will be (116 + 13 = 129), so it will be overflow and
                // output nonsense
                //. However, if use (((plaintext[i] - 'a') + n) % 26) + 'a') because if we input 't'
                // in a string and
                // argv=13, it will be ((116-97)+13))%26=6, 6+97= 'g'.
                printf("%c", (((plaintext[i] - 'a') + n) % 26) + 'a');
            }
            else if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'A') + n) % 26) + 'A');
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Useage: %s key\n", argv[0]);
        return 1;
    }
}

bool digits(string s)
{
    // int n = strlen(s);
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // check every character that is not digit, and if not, it will return 0
        if (!isdigit(s[i]))
        {
            return 1;
        }
    }
    return 0;
}
