#include <stdio.h>
#include <stdlib.h>

#define M 400
#define N 600

//TODO: Add a function to find the lowest energy seam and remove it

int image[M][N];
int energy[M][N];

int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

void compute_energy(void)
{
    int i, j;
    int mid;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            int left, right, top, bottom;
            if (j == 0)
                left = 0x3f3f3f3f;
            else
                left = abs(image[i][j - 1] - image[i][j]);
            if (j == N - 1)
                right = 0x3f3f3f3f;
            else
                right = abs(image[i][j + 1] - image[i][j]);
            if (i == 0)
                top = 0x3f3f3f3f;
            else
                top = abs(image[i - 1][j] - image[i][j]);
            if (i == M - 1)
                bottom = 0x3f3f3f3f;
            else
                bottom = abs(image[i + 1][j] - image[i][j]);
            mid = minimum(top, bottom);
            energy[i][j] = mininum(left, right, mid);
        }
    }
}

int main(int argc, char *argv[])
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            // Read in image data
            scanf("%d", &image[i][j]);
        }
    }
    compute_energy();
    // Seam carving logic goes here
    return 0;
}
