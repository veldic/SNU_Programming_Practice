#include <stdio.h>

int a[110][110], b[110][110];
int result[110][110];

int main(){

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int c = 0; c < m; c++)
            {
                result[i][j] += a[i][c]*b[c][j];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}