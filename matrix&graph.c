#include"hsh_solution.h"

void color_matrix(void)     //make color matrix   //correct
{
    int i,j;
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        {
            C_Matrix[i][j]=judge_man(i,j);
        }
    }
}

void free_matrix(void)
{
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        free(C_Matrix[i]);
    }
}

void generate_init_color_num(void)
{
    color_num=Vertices_Num;
}

void make_graph(void)           //correct
{
    int i,j;
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<Vertices_Num;j++)
        {
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
}



void re_color_matrix(int v,int a)  //remake colormatrix depend on the move
{                        //v means vertice ,a means future color
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        if(graph[v][i])
        {
            C_Matrix[i][vertice_color[v]]--;
            C_Matrix[i][a]++;
            calculate();
            //not complited optimize_num haven't been written
        }
    }
}
