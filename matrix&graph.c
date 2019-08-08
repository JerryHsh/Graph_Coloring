#include"hsh_solution.h"

void color_matrix(void)     //make color matrix   //correct
{
    //++jishuqi;
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
    //printf("The function is been used for the %d times\n",++jishuqi);
    ++jishuqi;
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        if(graph[v][i])
        {
            C_Matrix[i][vertice_color[v]]--;
            C_Matrix[i][a]++;
            //calculate();
            //not complited optimize_num haven't been written
        }
    }
}

void init_tabu_list(void)  
{
    int i,j;
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        Tabu_list[i][j]=0;
    }
}

void reduce_tabu_list(void)
{
    int i,j;
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        {
            if(Tabu_list[i][j]!=0)
                --Tabu_list[i][j];
        }
    }
}

void free_tabu_list(void)
{
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        free(Tabu_list[i]);
    }
}

void rand_color(void)
{
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        vertice_color[i]=rand()%color_num;
    }
}

void init_graph(void)
{
    graph=(int **)malloc(Vertices_Num*sizeof(int *));
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        graph[i]=(int *)malloc(Vertices_Num*sizeof(int));
    }
    int j;
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<Vertices_Num;j++)
        graph[i][j]=0;
    }
}

void init_vertice_color_array(void)
{
    vertice_color=(int *)malloc(Vertices_Num*sizeof(int));
}

void input(void)
{
    int i,p,q,e;
    printf("Input the vertice number:\n");
    scanf("%d",&Vertices_Num);
    printf("Input the edges number:\n");
    scanf("%d",&e);
    init_graph();
    init_vertice_color_array();
    printf("Input the adjacent vertice:\n");
    for(i=0;i<e;i++)
    {
        printf("No%d:\n",i+1);
        scanf("%d%d",&p,&q);
        graph[p-1][q-1]=1;
        graph[q-1][p-1]=1;
    }
}