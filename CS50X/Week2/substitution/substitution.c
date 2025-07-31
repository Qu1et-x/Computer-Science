#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void printf_output(string plaintext, string key);

int main(int argc, string key[])
{
    // 判断参数数量是否正确
    // 判断key长度是否为26
    if (argc != 2)
    {
        printf("Error: argc should be 2\n");
        return 1;
    }
    else if (strlen(key[1]) != 26)
    {
        printf("Error: counts should be 26\n");
        return 1;
    }

    // 判断key是否重复以及是否为字母
    for (int i = 0, len = strlen(key[1]); i < len; i++)
    {
        if (isalpha(key[1][i]) == 0)
        {
            printf("Error: key should be letter");
            return 1;
        }

        for (int j = 0, same = 0; j < len; j++)
        {
            if (tolower(key[1][i]) == tolower(key[1][j]))
            {
                same += 1;
            }
            if (same == 2)
            {
                printf("Error: key should not have same");
                return 1;
            }
        }
    }

    // 接受用户输入明文
    string plaintext = get_string("plaintext: ");

    // 将明文转换成密文并打印
    printf_output(plaintext, key[1]);
    return 0;
}

// 对每个字符进行判断
// 1.判断是否为非字母并打印
// 2.判断字母大小写并打印
void printf_output(string plaintext, string key)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        int index = tolower(plaintext[i]) - 'a';
        if (isalpha(plaintext[i]) == 0)
        {
            printf("%c", plaintext[i]);
        }
        else if (islower(plaintext[i]) != 0)
        {
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", toupper(key[index]));
        }
    }
    printf("\n");
}
