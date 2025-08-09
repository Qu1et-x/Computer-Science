#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int JPEG = 512;

int main(int argc, char *argv[])
{
    // 接受一个命令行参数
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // 打开储存卡
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Unable to open file!");
        return 2;
    }

    uint8_t buffer[JPEG];
    FILE *img = NULL;
    int times = 0;
    while (fread(buffer, 1, JPEG, card) == JPEG)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            if (img != NULL)
            {
                fclose(img);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", times++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fprintf(stderr, "无法创建文件 %s\n", filename);
                fclose(card);
                return 3;
            }
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, JPEG, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}
