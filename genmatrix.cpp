#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char ** argv)
{
    FILE * file = fopen(argv[1],"w");
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    fprintf(file,"%d %d \n",x,y);
    srand(0);
    for(int i = 0; i < x; i++)
    {
        if(i)
            fprintf(file,"\n");
        for(int j = 0; j< y; j++)
        {
            double d = rand()%10000;
            d /= rand() % 10000 + 1;
            fprintf(file,"%lf ",d);
        }
    }
    return 0;
}
