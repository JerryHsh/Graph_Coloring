#include<stdio.h>
#include<stdlib.h>

int main()
{
    srand(time(NULL));
    int vertice_num;
    int edge_num=0;
    int i,j;
    puts("Input vertice num:");
    scanf("%d",&vertice_num);
    FILE *fp;
    fp=fopen("./question.txt","w");
    fprintf(fp,"                       ");
    for(i=0;i<vertice_num-1;i++)
    {
        for(j=i+1;j<vertice_num;j++)
        {
            if(rand()%3)
            {
                fprintf(fp," %d %d",i+1,j+1);
                edge_num++;
            }
        }
    }
    rewind(fp);
    fprintf(fp,"%d %d",vertice_num,edge_num);
    fclose(fp);
}