#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // 接受用户输入文本
    string text = get_string("Text: ");

    // 计算文本的字母数量、单词数量和句子数量
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // 打印参数观察结果与调试
    printf("letters = %i\n", letters);
    printf("words= %i\n", words);
    printf("sentences = %i\n", sentences);

    // 将参数应用于阅读水平计算公式
    int index = round(0.0588 * ((float) letters / words * 100) -
                      0.296 * ((float) sentences / words * 100) - 15.8);

    // 打印最终结果
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // 返回文本中字母的数量
    int total = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            total += 1;
        }
    }
    return total;
}

int count_words(string text)
{
    // 返回文本中单词的数量
    // 由于每段文本最后一个单词会少计算一次空格
    // 所以这里初始化为的值为一
    int total = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]) != 0)
        {
            total += 1;
        }
    }
    return total;
}

int count_sentences(string text)
{
    // 返回文本中句子的数量
    int total = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            total += 1;
        }
    }
    return total;
}
