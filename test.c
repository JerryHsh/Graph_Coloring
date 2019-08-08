#include"hsh_solution.h"

int test(void)
{
    printf("\nColor_num is %d\n",color_num);
    rand_color();
    print_color();
    int i;
    step=0;
    if(depth)
    {
        free_matrix();
        free_tabu_list();
    }
    best.fs=1;
    //free_matrix();
    /*
    fp=fopen("./color.txt","r");
    for(i=0;i<Vertices_Num;i++)
    {
        fscanf(fp,"%d",&vertice_color[i]);
    }
    fclose(fp);
    */
    for(i=0;i<Vertices_Num;i++)
    {
        C_Matrix[i]=(int *)malloc(color_num*sizeof(int));
        Tabu_list[i]=(int *)malloc(color_num*sizeof(int));
    }
    putchar('\n');
    init_tabu_list();
    color_matrix();
    best_ever=calculate();
    while((calculate()!=0)&&(step<=Max_Step))
    {
    ++step;
    reduce_tabu_list();
    //printf("\nThis is the %d step\n",++step);
    //print_matrix();
    make_critical_vertice();
    //print_critical_vertice();
    judge_neighbourhood();
    //print_neibourhood();
    move(best.v,best.c,2);
    //print_tabu_list();
    optimize_num=best.fs;
    }
    if(!optimize_num)
    {
        print_answer();
        return 1;
    }
    else
    {
        printf("step is %d \n",step);
        printf("the calculate is been used for %d times",jishuqi);

        return 0;
    }
    

    // there is possibility that optimize num isn't update
}
