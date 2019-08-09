#include"hsh_solution.h"

int test(void)
{
    //fprintf(f_log,"\n***Color_num is %d\n",color_num);
    rand_color();
    //print_color();
    int i;
    step=0;
    best.fs=1;
    if(depth!=0)
    {
        free_matrix();
        free_tabu_list();
    }
    for(i=0;i<Vertices_Num;i++)
    {
        C_Matrix[i]=(int *)malloc(color_num*sizeof(int));
        Tabu_list[i]=(int *)malloc(color_num*sizeof(int));
    }
    init_tabu_list();
    color_matrix();
    best_ever=calculate();
    while((optimize_num!=0)&&(step<=Max_Step))
    {
    ++step;
    reduce_tabu_list();
    make_critical_vertice();
    //judge_neighbourhood();
    judge_neighbourhood_test();
    move(best.v,best.c,2);
    //print_tabu_list();
    optimize_num=best.fs;
    }
    if(!optimize_num)
    {
        print_answer();
        return color_num;
    }
    else
    {
        fprintf(f_log,"**The solution color number is %d\n",color_num);
        fprintf(f_log,"step is %d \n",step);
        fprintf(f_log,"the function is been used for %d times\n",jishuqi);
        return 0;
    }
}
