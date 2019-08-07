#include<stdio.h>
#include<stdlib.h>
#include"hsh_solution.h"
//colors and vertices are represented by number
//color can be 0 to color_num-1
//vertice can be 0 to vertice_num-1

int graph[Vertices_Num][Vertices_Num];  //store the graph
int vertice_color[Vertices_Num];       //distribution color
int critical_vertice[Max_Vertice_Num];  //store the critical vertice

int ** C_Matrix;  //store color matrix
int ** Tabu_list; //store the Tabu_list
int color_num;      //color num that is been used
int init_color_num; //first  color_num
int optimize_num;   //store f(s)
int Critical_v_p;   //point to the next critical vertice
int Neigh_p;     //point the next neighbour move
int step;        //store the step of move
int jishuqi;     //store the calculate num
int best_ever;      //store the best f(s)
int depth;            //store the time of changing number of color

move_node best;
move_node best_nt;   //out of tabu_list
move_node best_t;    //inside tabu list
move_node * Neighbourhood; //store the neighbourhood move

FILE * fp;

int main()
{
    depth=0;
    jishuqi=0;
    color_num=Vertices_Num;
    rand_color();
    print_color();
    srand(time(NULL));
    fp=fopen("./graph.txt","r");
    make_graph();
    fclose(fp);
    print_graph();
    define_critical_array();
    C_Matrix=(int **)malloc(Vertices_Num*sizeof(int *));
    Tabu_list=(int **)malloc(Vertices_Num*sizeof(int *));
    while(test())
    {
        depth++;
        color_num--;
    }
    /*
    Critical_v_p=0;
    Neigh_p=0;
    generate_init_color_num();
    do
    {
        color_num--;
        solution();
    } while (judge());
    printf("The needed num is %d",++color_num);
    */
    return 0;
}

void solution(void)
{
    free_matrix();              //clear the last array
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        vertice_color[i]=rand()%color_num;    //give color randomly
    }
    for(i=0;i<color_num;i++)
    {
        C_Matrix[i]=(int *)malloc(color_num*sizeof(int));     //reproduce the array
    }
    color_matrix();
}

int calculate(void)         //correct
{
    //printf("The calculator is been used for the %d times\n",++jishuqi);
    int i,j;
    for(i=0,optimize_num=0;i<Vertices_Num-1;i++)
    {
        for(j=i+1;j<Vertices_Num;j++)
        {
            if(graph[i][j]&&(vertice_color[i]==vertice_color[j]))
            optimize_num++;
        }
    }
    return optimize_num;
}

