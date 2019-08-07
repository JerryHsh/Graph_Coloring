#include"hsh_solution.h"

void free_neighbour(void) //free the neighbourhood
{
    free(Neighbourhood);
    Neigh_p=0;
}

void make_neighbourhood_move(void) //make the neighbourhood of it
{
    int i,j;
    Neighbourhood=(move_node *)malloc((color_num-1)*Critical_v_p*sizeof(move_node));
    for(i=0;i<Critical_v_p;i++)
    {
        for(j=0;j<color_num;j++)
        {
            if(j!=vertice_color[critical_vertice[i]])
            {
                Neighbourhood[Neigh_p].fs=move(critical_vertice[i],j,1);
                Neighbourhood[Neigh_p].c=j;
                Neighbourhood[Neigh_p++].v=critical_vertice[i];
            }
        }
    }
}

void judge_neighbourhood(void)
{
    free_neighbour();
    make_neighbourhood_move();
    int i;
    for(i=0;i<Neigh_p;i++)
    {
        if(i==0)
        {
            if(!Tabu_list[Neighbourhood[i].v][Neighbourhood[i].c])
            {
                best_nt.fs=Neighbourhood[i].fs;
                best_nt.c=Neighbourhood[i].c;
                best_nt.v=Neighbourhood[i].v;
            }
            else
            {
                best_t.fs=Neighbourhood[i].fs;
                best_t.c=Neighbourhood[i].c;
                best_t.v=Neighbourhood[i].v;
            }
        }
        else
        {
            if(!Tabu_list[Neighbourhood[i].v][Neighbourhood[i].c])
            {
                if(best_nt.fs>Neighbourhood[i].fs)
                { 
                    best_nt.fs=Neighbourhood[i].fs;
                    best_nt.c=Neighbourhood[i].c;
                    best_nt.v=Neighbourhood[i].v;
                }
            }
            else
            {
                if(best_t.fs>Neighbourhood[i].fs)
                { 
                    best_t.fs=Neighbourhood[i].fs;
                    best_t.c=Neighbourhood[i].c;
                    best_t.v=Neighbourhood[i].v;
                }
            }
        }
        if(best_t.fs<best_ever)
        {
            best=best_t;
            best_ever=best_t.fs;
        }
        else 
        {
            best=best_nt;
            best_ever=best_nt.fs;
        }
    }
}
