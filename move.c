#include"hsh_solution.h"

int move(int v,int a,int x) //v->vertice a->future color x->mode
{
    int color_store;
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
            color_store=vertice_color[v];
            vertice_color[v]=a;
            calculate();
            Fs_store=optimize_num;
            move(v,color_store,0);
            return Fs_store;
        }
        case 2:         //reproduce the color matrix
        {
            re_color_matrix(v,a);
            vertice_color[v]=a;
            return 0;
        }
    }
}

