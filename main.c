#include<stdio.h>
#include<stdlib.h>
#include"hsh_solution.h"
//colors and vertices are represented by number
//color can be 0 to color_num-1
//vertice can be 0 to vertice_num-1

int critical_vertice[Max_Vertice_Num];  //store the critical vertice

int ** graph; //store the graph
int ** C_Matrix;  //store color matrix
int ** Tabu_list; //store the Tabu_list
int *vertice_color; //store vertice_color
int color_num;      //color num that is been use
int init_color_num; //first  color_num
int optimize_num;   //store f(s)
int Critical_v_p;   //point to the next critical vertice
int Neigh_p;     //point the next neighbour move
int step;        //store the step of move
int jishuqi;     //store the calculate num
int best_ever;      //store the best f(s)
int depth;            //store the time of changing number of color
int Vertices_Num;
int Tabu_Length;
int flag1;

move_node best;
move_node * Neighbourhood; //store the neighbourhood move

FILE * fp,*f_log;

int main()
{
    int note=0;   //survalance solution
    f_log=fopen("./log.txt","w");
    input();
    depth=0;
    jishuqi=0;
    color_num=Vertices_Num;
    srand(time(NULL));
    print_graph();
    define_critical_array();
    C_Matrix=(int **)malloc(Vertices_Num*sizeof(int *));
    Tabu_list=(int **)malloc(Vertices_Num*sizeof(int *));
    int i;
    for(i=0;i<10;i++)
    {
        fprintf(f_log,"***********new turn:\n");
        note=solution(note);
    }
    free_matrix();
    free_tabu_list();
    free(C_Matrix);
    free(Tabu_list);
    free(Neighbourhood);
    fclose(f_log);
    return 0;
}


int calculate(void)         //correct
{
    //++jishuqi;
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

int solution(int a)
{
    if(!a)
    {
        int up,low;
        up=Vertices_Num;
        low=0;
        //Tabu_Length=10;
        while(low<up)
        {
            color_num=(low+up)/2+1;
            Tabu_Length=((Vertices_Num/10)>10)?((color_num<(Vertices_Num/4))?(Vertices_Num/5):Vertices_Num/10):10;
            if(test())
            {
                up=color_num;
            }
            else
            {
                low=color_num;
            }
            depth++;
        }
        flag1=color_num;
        while(test())
        {
            flag1=color_num;
            depth++;
            color_num--;
        }
        return flag1;
    }
    else
    {
        Tabu_Length=((Vertices_Num/10)>10)?((color_num<(Vertices_Num/4))?(Vertices_Num/5):Vertices_Num/10):10;
        color_num=a;
        flag1=color_num;
        while(test())
        {
            flag1=color_num;
            depth++;
            color_num--;
        }
        return flag1;
    }
}

//there is quicker way

