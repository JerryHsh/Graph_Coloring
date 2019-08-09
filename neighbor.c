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

void judge_neighbourhood_test(void)
{
    best_store_p=0;
    tabu_store_p=0;
    free_neighbour();
    make_neighbourhood_move();
    int i;
    for(i=0;i<Neigh_p;i++)
    {
        if(!Tabu_list[Neighbourhood[i].v][Neighbourhood[i].c])
        {
            if(!best_store_p)
            {
                best_store[best_store_p++]=Neighbourhood[i];
            }
            else if(Neighbourhood[i].fs<best_store[0].fs)
            {
                best_store_p=0;
                best_store[best_store_p++]=Neighbourhood[i];
            }
            else if((Neighbourhood[i].fs==best_store[0].fs)&&(best_store_p<100))
            {
                best_store[best_store_p++]=Neighbourhood[i];
            }
        }
        else
        {
            if(!tabu_store_p)
            {
                tabu_store[tabu_store_p++]=Neighbourhood[i];
            }
            else if(Neighbourhood[i].fs<tabu_store[0].fs)
            {
                tabu_store_p=0;
                tabu_store[tabu_store_p++]=Neighbourhood[i];
            }
            else if((Neighbourhood[i].fs==tabu_store[0].fs)&&(tabu_store_p<100))
            {
                tabu_store[tabu_store_p++]=Neighbourhood[i];
            }
        } 
    }
    if(best_store[0].fs<best_ever)
        best_ever=best_store[0].fs;
    if(tabu_store_p!=0)
    {
        if(tabu_store[0].fs<best_ever)
        {
            best=tabu_store[rand()%tabu_store_p];
            best_ever=tabu_store[0].fs;
        }
        else
        {
            best=best_store[rand()%best_store_p];
        }
    }
    else
    {
        best=best_store[rand()%best_store_p];
    }
    //fprintf(f_log,"%d   %d\n",best_store_p,tabu_store_p);
}

void judge_neighbourhood(void)
{
    free_neighbour();
    make_neighbourhood_move();
    int i;
    for(i=0;i<Neigh_p;i++)
    {
        if(i==0&&(!Tabu_list[Neighbourhood[i].v][Neighbourhood[i].c]))
            best=Neighbourhood[i];
        else if (!Tabu_list[Neighbourhood[i].v][Neighbourhood[i].c])
        {
            if(best.fs>Neighbourhood[i].fs)
                best=Neighbourhood[i];
        }
    }
    if(best.fs<best_ever)
    {
        best_ever=best.fs;
    }
    for(i=0;i<Neigh_p;i++)
    {
        if(Tabu_list[Neighbourhood[i].v][Neighbourhood[i].c])
        {
            if(Neighbourhood[i].fs<((best_ever>2)?(best_ever-2):1))
            {
                best=Neighbourhood[i];
                best_ever=best.fs;
            }
        }
    }
}
