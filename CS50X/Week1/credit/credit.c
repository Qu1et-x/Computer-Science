#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 判断输入是否合法
    long long n = 0;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);

    // 初始化变量
    // fir为每第一位数字计算累加结果
    // sec为每第二位数字计算累加结果
    int fir = 0;
    int sec = 0;
    string type = "";

    // 循环处理n的每一位，变量i初始值为2是因为：
    // 1.要通过判断n的前两位数字
    // 2.获取去掉前两位数字后n的总位数
    // 由n的前两位数字和n的总位数来决定卡是什么类型
    for (int i = 2; n > 0; i++)
    {
        // 初始化变量
        // m为每第二位数字乘二后的结果
        int m = 0;
        if (i % 2 == 0)
        {
            fir += n % 10;
        }
        else
        {
            m = n % 10 * 2;
            if (m < 10)
            {
                sec += m;
            }
            else
            {
                sec += m / 10;
                sec += m % 10;
            }
        }

        // 判断卡的类型
        if (10 < n && n < 100)
        {
            if ((n == 34 || n == 37) && i == 15)
            {
                type = "AMEX";
            }
            else if (50 < n && n < 56 && i == 16)
            {
                type = "MASTERCARD";
            }
            else if (n / 10 == 4 && (i == 13 || i == 16))
            {
                type = "VISA";
            }
            else
            {
                type = "INVALID";
            }
        }
        n /= 10;
    }

    // 打印参数进行调试
    printf("sec = %i, fir = %i", sec, fir);

    // 确认无误后最终输出
    if ((sec + fir) % 10 == 0)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}
