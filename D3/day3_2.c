#include <stdio.h>
#include <string.h>


int main(void)
{
    FILE *file = fopen("d3.txt","r");

    char input1[50],input2[50],input3[50];
    int score = 0;
    int flag = 0;

    while (!feof(file))
    {
        fscanf(file,"%s",input1);
        fscanf(file,"%s",input2);
        fscanf(file,"%s",input3);

        for(int i=0; i<strlen(input1);i++)
        {
            for(int j=0; j<strlen(input2);j++)
            {
                for(int k=0; k<strlen(input3);k++)
                {
                    if(input1[i] == input2[j] && input2[j] == input3[k])
                    {
                        if(input1[i]>= 97 && input1[i]<=122)
                        {
                            score += input1[i] - 96;
                            printf("%d\n",input1[i] - 96);
                            flag = 1;
                            break;
                        }
                        else
                        {
                            score += input1[i] - 38;
                            printf("%d\n",input1[i] - 38);
                            flag = 1;
                            break;
                        }
                    }
                }

                if(flag == 1)
                {
                    break;
                }

            }

            if(flag == 1)
            {
                flag = 0;
                break;
            }

        }

        memset(input1,0,50);
        memset(input2,0,50);
        memset(input3,0,50);    
    }


    
    printf("%d",score);
    

}