#include <stdio.h>

int main(void)
{
    FILE *file = fopen("d2.txt","r");
    int score = 0;
    char player1,player2;
    int p1,p2;
    while (!feof(file))
    {
        fscanf(file,"%c %c",player1,player2);
        
        
    }

    printf("%d",score);
    
}