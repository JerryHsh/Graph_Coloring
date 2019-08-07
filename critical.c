#include"hsh_solution.h"

void make_critical_vertice(void) //make the array store critical vertice
{
    free_critical_vertice();
    int i,j;
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<Vertices_Num;j++)
        {
            if(graph[i][j]&&(vertice_color[i]==vertice_color[j]))
            {
                critical_vertice[Critical_v_p++]=i;
                break;
            }
        }
    }
}

void free_critical_vertice(void)
{
    int i;
    for(i=0;i<Critical_v_p;i++)
        critical_vertice[i]=Max_Vertice_Num;
    Critical_v_p=0;
}

void define_critical_array(void)
{
    int i;
    for(i=0;i<Max_Vertice_Num;i++)
    {
        critical_vertice[i]=Max_Vertice_Num;
    }
}
