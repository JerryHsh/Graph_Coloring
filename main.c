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

clock_t start,end,mid;

double duration;

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
    int i,j;
    puts("Input the loop times depend on how long you can wait");
    scanf("%d",&j);
    start=clock();
    for(i=0;i<j;i++)
    {
        mid=clock();
        fprintf(f_log,"No %d turn*****************************************************************\n",i+1);
        //note=solution(note);
        if(!i)
        {
            solution(0);
            note=flag1;
        }
        else
        {
            if(solution(note-1))
                note=flag1;
        }
        end=clock();
        duration=(double)(end-mid)/CLK_TCK;
        fprintf(f_log,"No %d turn last %lf****************************************************************\n\n",i+1,duration);
    }
    free_matrix();
    free_tabu_list();
    free(C_Matrix);
    free(Tabu_list);
    free(Neighbourhood);
    fclose(f_log);
    return 0;
}

