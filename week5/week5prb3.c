#include <stdio.h>
#include <math.h>

double distance(int x1, int y1, int x2, int y2){
    double dist;

    dist = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));

    return dist;
}

int main(){

    int n;
    int x[20] = {0,};
    int y[20] = {0,};
    double mindist = 200000;


    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j) continue;
            else
            {
                double a = distance(x[i], y[i], x[j], y[j]);
                if(mindist > a)
                {
                    mindist = a;
                }
            }
        }
    }

    printf("%.6lf", mindist);

    return 0;
}