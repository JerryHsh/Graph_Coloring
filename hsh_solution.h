#ifndef HSH_SOLUTION_H_INCLUDED
#define HSH_SOLUTION_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

#define Vertices_Num 9
#define Max_Vertice_Num 100
#define Max_Step 50
#define Tabu_Length 10

typedef struct move_neighbour   //store the neighbour move
{
    int v;  //represent vertice
    int c;  //represent color
    int fs; //represent fs
}move_node;

extern int graph[Vertices_Num][Vertices_Num];  //store the graph
extern int vertice_color[Vertices_Num];       //distribution color
extern int critical_vertice[Max_Vertice_Num];
extern int ** C_Matrix;  //store color matrix
extern int ** Tabu_list; //store the Tabu_list

extern int best_ever;   //store the best f(s)
extern int color_num;      //color num that is been used
extern int step;
extern int init_color_num; //first  color_num
extern int optimize_num;   //store f(s)
extern int Critical_v_p;   //point to the next critical vertice
extern int Neigh_p;     //point the next neighbour move
extern int jishuqi;

extern move_node * Neighbourhood; //store the neighbourhood move
extern move_node best; //store the best move

extern FILE * fp;

void init_tabu_list(void);
//initialize tabu list
void reduce_tabu_list(void);
//reduce the no_zero number
int judge(void);
//judge that if the graph coloring is legal
int judge_man(int,int);
//calculate the number of the color matrix
int move(int,int,int);
//move a vertice to another color and move it back and give the f(s) depend on the last int and remake the color matrix
int calculate(void);
//calculate f(s)
void solution(void);
void generate_init_color_num(void);
void color_matrix(void);
//make vajacent color matrix
void re_color_matrix(int,int);
//remake colormatrix depend on the move
void free_matrix(void);
//free the second array
void make_graph(void);
//make the test graph
void test(void);
//test each function
void judge_neighbourhood(void);
//find the best neighbourhood
void free_critical_vertice(void);
//free the arry that store the critical vertice
void define_critical_array(void);
//store every critical array max
void make_critical_vertice(void);
//make the array store critical vertice
void make_neighbourhood_move(void);
//make neighboorhood
void free_neighbour(void);
//free the neighbourhood
void print_graph(void);
//print the test graph
void print_matrix(void);
//print the test matrix
void print_color(void);
//print color
void print_critical_vertice(void);
//print those critical vertice
void print_neibourhood(void);
//print the neiborhood
void print_answer(void);
//print the answer of the graph

#endif // HSH_SOLUTION_H_INCLUDED
