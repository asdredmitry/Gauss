#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
void printMatrix(double * matrix,int x,int y)
{
    printf("x = %d, y = %d \n",x,y);
    for(int i = 0; i < y; i++)
    {
        printf("\n");
        for(int j = 0; j < x; j++)
            printf("%lf  ",matrix[i*x + j]);
    }
}
void swapStr(double * matrix,int i,int j,int x)
{
    for(int s = 0; s < x; s++)
    {
        double tmp = matrix[x*i + s];
        matrix[x*i + s] = matrix[x*j + s];
        matrix[x*j + s] = tmp;
    }
}
void gauss(double * matrix,int x,int y)
{
    int theLastPositive = -1;
    for(int i = 0; i < y; i++)
    {
        if(matrix[i*x + i] == 0)
        {
            for(int p = i; p < y; p++)
            {
                if(matrix[p*x + i] != 0)
                {
                    swapStr(matrix,p,i,x);
                    break;
                }
            }
        }
        if(matrix[i*x + i] != 0)
        {
            theLastPositive = i;
            for(int t = i + 1; t < y; t++)
            {
                double mult = matrix[t*x + i]/matrix[i*x + i];
                for(int s = i; s < x; s++)
                    matrix[t*x + s] -= matrix[i*x + s]*mult;
            }
        }
        if(theLastPositive > 0)
        {
            for(int s = theLastPositive; s >= 0; s--)
            {
                for(int t = s - 1; t >= 0; t--)
                {
                    double mult = matrix[t*x + s]/matrix[s*x + s];
                    for(int m = s; m < x; m++)
                        matrix[t*x + m] -= matrix[s*x + m]*mult;
                }
            }
        }
        //std :: cout << " the last positive " << theLastPositive << std :: endl;
    }
}
int main(int argc, char ** argv)
{
    if(argc < 2)
    {
        perror("invalid argumetn");
        exit(EXIT_FAILURE);
    }
    FILE * file = fopen(argv[1],"r");
    if(!file)
    {
        perror("cannot open file to read");
        exit(EXIT_FAILURE);
    }
    int x,y;
    int amount = fscanf(file,"%d %d",&x,&y);
    if(amount < 2)
    {
        perror("cannot read data from file");
        exit(EXIT_FAILURE);
    }
    double * matrix = (double *)malloc(sizeof(double)*x*y);
    memset(matrix,0,x*y*sizeof(double));
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
            fscanf(file,"%lf",matrix + i*x + j);
    }

    gauss(matrix,x,y);
    printMatrix(matrix,x,y);
    return 0;
}
