#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 1);

    // 如果总数大于某一面额，则将总数和该面额取余并重新赋值给总数。
    // 意为总数已经减去了该面额，余下来的数为新的总数。
    // 然后将硬币数加等于总数和该面额的商。
    int coins = 0;
    while (n > 0)
    {
        if (0 < n / 25)
        {
            coins += n / 25;
            n %= 25;
        }
        else if (0 < n / 10)
        {
            coins += n / 10;
            n %= 10;
        }
        else if (0 < n / 5)
        {
            coins += n / 5;
            n %= 5;
        }
        else if (0 < n / 1)
        {
            coins += n / 1;
            n %= 1;
        }
    }

    printf("%i\n", coins);
}
