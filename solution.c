#include"hsh_solution.h"


int calculate(void)         //correct
{
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
        while(low<up-1)
        {
            color_num=(low+up)/2;
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
        fprintf(f_log,"debug*******************************************\n");
        flag1=color_num;
        int i;
        for(i=0;i<5;i++)
        {
            if(test())
                break;
        }
        if(i==5)
            flag1++;
        while(test())
        {
            flag1=color_num;
            depth++;
            color_num--;
        }
        //return flag1;
        return 1;
    }
    else
    {   int flag2=0;// judge if the color_num could run
        Tabu_Length=((Vertices_Num/10)>10)?((color_num<(Vertices_Num/4))?(Vertices_Num/5):Vertices_Num/10):10;
        color_num=a;
        flag1=color_num;
        while(test())
        {
            flag2=1;
            flag1=color_num;
            depth++;
            color_num--;
        }
        //return flag1;
        return flag2;
    }
}

//there is quicker way
