#include "helpers.h"
#include <math.h>

void swap_images(int height, int width, RGBTRIPLE image[height][width],
                 RGBTRIPLE new_image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = round(
                ((float) image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, gray = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < (width / 2); j++, k--)
        {
            RGBTRIPLE new_image = image[i][j];

            image[i][j] = image[i][k];

            image[i][k] = new_image;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total[3] = {0, 0, 0};

            // 变量n用来计算总次数
            int times = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int n = k + i, m = l + j;

                    // 满足条件（即在边界内）时增加总数
                    if (n >= 0 && n < height && m >= 0 && m < width)
                    {
                        total[0] += image[n][m].rgbtBlue;
                        total[1] += image[n][m].rgbtGreen;
                        total[2] += image[n][m].rgbtRed;
                        times++;
                    }
                }
            }

            new_image[i][j].rgbtBlue = round((float) total[0] / times);
            new_image[i][j].rgbtGreen = round((float) total[1] / times);
            new_image[i][j].rgbtRed = round((float) total[2] / times);
        }
    }
    swap_images(height, width, image, new_image);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
            int x[3] = {0, 0, 0};
            int y[3] = {0, 0, 0};

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // Gx       | Gy
                    // -1  0  1 | -1 -2 -1
                    // -2  0  2 |  0  0  0
                    // -1  0  1 |  1  2  1
                    int n = k + i;
                    int m = l + j;

                    if (n >= 0 && n < height && m >= 0 && m < width)
                    {
                        // 计算各通道的Gx和Gy
                        x[0] += image[n][m].rgbtBlue * Gx[k + 1][l + 1];
                        x[1] += image[n][m].rgbtGreen * Gx[k + 1][l + 1];
                        x[2] += image[n][m].rgbtRed * Gx[k + 1][l + 1];

                        y[0] += image[n][m].rgbtBlue * Gy[k + 1][l + 1];
                        y[1] += image[n][m].rgbtGreen * Gy[k + 1][l + 1];
                        y[2] += image[n][m].rgbtRed * Gy[k + 1][l + 1];
                    }
                }
            }

            // 最终计算
            int end[3] = {round(sqrt(pow(x[0], 2) + pow(y[0], 2))),
                          round(sqrt(pow(x[1], 2) + pow(y[1], 2))),
                          round(sqrt(pow(x[2], 2) + pow(y[2], 2)))};
            for (int p = 0; p < 3; p++)
            {
                if (end[p] > 255)
                {
                    end[p] = 255;
                }
            }
            new_image[i][j].rgbtBlue = end[0];
            new_image[i][j].rgbtGreen = end[1];
            new_image[i][j].rgbtRed = end[2];
        }
    }
    swap_images(height, width, image, new_image);
    return;
}

void swap_images(int height, int width, RGBTRIPLE image[height][width],
                 RGBTRIPLE new_image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 交换单个像素
            RGBTRIPLE temp = image[i][j];
            image[i][j] = new_image[i][j];
            new_image[i][j] = temp;
        }
    }
}
