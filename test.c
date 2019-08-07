#include"hsh_solution.h"

void test(void)
{
    best.fs=1;
    //free_matrix();
    fp=fopen("./color.txt","r");
    color_num=3;
    int i;
    for(i=0;i<Vertices_Num;i++)
    {
        C_Matrix[i]=(int *)malloc(color_num*sizeof(int));
    }
    for(i=0;i<Vertices_Num;i++)
    {
        fscanf(fp,"%d",&vertice_color[i]);
    }
    putchar('\n');
    color_matrix();
    print_matrix();
    while(best.fs!=0)
    {
    make_critical_vertice();
    print_critical_vertice();
    judge_neighbourhood();
    print_neibourhood();
    move(best.v,best.c,2);
    color_matrix();
    print_matrix();
    print_answer();
    }
}
