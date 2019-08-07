#include"hsh_solution.h"

int judge_man(int a,int b)      //a means vertice b means color
{                           //correct
    int rival_num;
    int i;
    for(i=0,rival_num=0;i<Vertices_Num;i++)
    {
        if(graph[a][i]&&(vertice_color[i]==b))
        {
            rival_num++;
        }
    }
    return rival_num;
}


int judge(void)         //if it is legal return 1, else return 0
{
    int flag;
    int i,j;
    for(flag=0,i=0;i<Vertices_Num-1;i++)
    {
        for(j=i+1;j<Vertices_Num;j++)
        {
            if((graph[i][j])&&(vertice_color[i]=vertice_color[j]))
            flag++;
        }
    }
    if(flag==0)
        return 1;
    else
        return 0;
}
