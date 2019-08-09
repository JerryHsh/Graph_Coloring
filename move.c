#include"hsh_solution.h"

int move(int v,int a,int x) //v->vertice a->future color x->mode
{
    int Fs_store;
    switch(x)
    {
        case 0:      // x=0->simply move
        {
            vertice_color[v]=a;
            return 0;
        }
        case 1:          //give the f(s) after move and move back
        {
            Fs_store=optimize_num+C_Matrix[v][a]-C_Matrix[v][vertice_color[v]];
            return Fs_store;
        }
        case 2:         //reproduce the color matrix,make tabulist
        {
            Tabu_list[v][vertice_color[v]]=rand()%Tabu_Length+1;
            //print_tabu_list();
            re_color_matrix(v,a);
            vertice_color[v]=a;
            return 0;
        }
        default:
			break;
    }
}




