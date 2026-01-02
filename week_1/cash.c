#include <cs50.h>
#include <stdio.h>

int changed_owed(void);

int main(void)
{
    int own;
    int number = 0;
    own = changed_owed();
    while (own > 0)
    {
        if (own >= 25)
        {
            number += 1;
            own -= 25;
        }
        else if (own >= 10)
        {
            number += 1;
            own -= 10;
        }
        else if (own >= 5)
        {
            number += 1;
            own -= 5;
        }
        else
        {
            number += 1;
            own -= 1;
        }
    }
    printf("%i\n", number);
}

int changed_owed(void)
{
    int n;
    do
    {
        n = get_int("changed owed: ");
    }
    while (n < 1);
    return n;
}
