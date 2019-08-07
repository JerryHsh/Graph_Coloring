#include"hsh_solution.h"

void print_graph(void)          //correct
{
    int i,j;
    printf("\nGraph:\n");
    for(i=0;i<Vertices_Num;i++)
    {
        putchar('\n');
        for(j=0;j<Vertices_Num;j++)
        {
            printf("%d ",graph[i][j]);
        }
    }
    putchar('\n');
}


void print_matrix(void)         //correct
{
    int i,j;
    printf("\nColor_matrix:\n");
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        {
            printf("%d ",C_Matrix[i][j]);
        }
        putchar('\n');
    }
}

void print_color(void)
{
    int i;
    printf("\ncolor\n");
    for(i=0;i<Vertices_Num;i++)
    {
        printf("%d ",vertice_color[i]);
    }
    putchar('\n');
}

void print_critical_vertice(void)
{
    int i;
    printf("\nThis is the critical vertice\n");
    printf("Number is %d\n",Critical_v_p);
    for(i=0;i<Critical_v_p;i++)
    {
        printf("%d ",critical_vertice[i]+1);
    }
    putchar('\n');
}

void print_neibourhood(void)
{
    int i;
    printf("\nThis is the neiborhood\n");
    for(i=0;i<Critical_v_p*(color_num-1);i++)
    {
        printf("No %d,vertice is %d,color is %d,f(s) is %d\n",i+1,Neighbourhood[i].v,Neighbourhood[i].c,Neighbourhood[i].fs);
    }
    printf("The best move: vertice is %d,color is %d,f(s)is %d\n",best.v,best.c,best.fs);
}

void print_answer(void)
{
    int i,j;
    putchar('\n');
    for(i=0;i<color_num;i++)
    {
        printf("color %d color:",i+1);
        for(j=0;j<Vertices_Num;j++)
        {
            if(vertice_color[j]==i)
            {
                printf("%d;",j+1);
            }
        }
        putchar('\n');
    }
}

void print_tabu_list(void)
{
    int i,j;
    printf("\nThis is Tabu list\n");
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        {
            printf("%d ",Tabu_list[i][j]);
        }
        putchar('\n');
    }
}