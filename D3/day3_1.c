#include <stdio.h>
#include <string.h>


int main(void)
{
    FILE *file = fopen("d2.txt","r");

    char input[50];
    int score = 0;
    int flag = 0;
    while (!feof(file))
    {
        fscanf(file,"%s",input);

        for(int i=0; i<strlen(input)/2;i++)
        {
            for(int j=strlen(input)/2;j<strlen(input);j++)
            {
                if(input[i] == input[j])
                {
                    if(input[i]>= 97 && input[i]<=122)
                    {
                        score += input[i] - 96;
                        printf("%d\n",input[i] - 96);
                        flag = 1;
                        break;
                    }
                    else
                    {
                        score += input[i] - 38;
                        printf("%d\n",input[i] - 38);
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1)
            {
                flag = 0;
                break;
            }
            

        }
        memset(input,0,50);
    }
    printf("%d",score);
    

}