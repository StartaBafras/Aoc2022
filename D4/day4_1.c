#include <stdio.h>

int main(void)
{
    FILE *file = fopen("d4.txt","r");
    int score = 0;
    int start1,stop1,start2,stop2;
    while (!feof(file))
    {
        fscanf(file,"%d-%d,%d-%d",&start1,&stop1,&start2,&stop2);

        if(start1 <= start2 && stop1 >= stop2)
        {
            score++;
        }

        else if(start1 >= start2 && stop1 <= stop2)
        {
            score++;
        }
        
    }

    printf("%d",score);
    
}