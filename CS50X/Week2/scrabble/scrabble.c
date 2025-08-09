#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int total_scores(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = total_scores(word1);
    int score2 = total_scores(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// 计算每个字母的得分然后获取总得分
int total_scores(string word)
{
    int scores = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        scores += POINTS[toupper(word[i]) - 'A'];
    }
    return scores;
}
