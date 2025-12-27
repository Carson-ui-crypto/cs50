#include <cs50.h>
#include <stdio.h>

int positive_times(void);
void bricks(int n);

int main(void)
{
    int heights;
    heights = positive_times();
    bricks(heights);
}

int positive_times(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    return n;
}

void bricks(int n)
{
    for (int rows = 0; rows < n; rows++)
    {
        for (int spaces = 0; spaces < (n - rows - 1); spaces++)
        {
            printf(" ");
        }
        for (int hashes = 0; hashes < (rows + 1); hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
