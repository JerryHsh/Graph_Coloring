#include"hsh_solution.h"

void print_graph(void)          //correct
{
    fp=fopen("./graph.txt","w+");
    int i,j;
    fprintf(fp,"Graph:\n");
    for(i=0;i<Vertices_Num;i++)
    {
        fputc('\n',fp);
        for(j=0;j<Vertices_Num;j++)
        {
            fprintf(fp,"%d ",graph[i][j]);
        }
    }
    fputc('\n',fp);
    fclose(fp);
}


void print_matrix(void)         //correct
{
    int i,j;
    printf("Color_matrix:\n");
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        {
            printf("%d ",C_Matrix[i][j]);
        }
        putchar('\n');
    }
}

void print_color(void)
{
    int i;
    fprintf(f_log,"color\n");
    for(i=0;i<Vertices_Num;i++)
    {
        fprintf(f_log,"%d ",vertice_color[i]);
    }
    fputc('\n',f_log);
}

void print_critical_vertice(void)
{
    int i;
    printf("This is the critical vertice\n");
    printf("Number is %d\n",Critical_v_p);
    for(i=0;i<Critical_v_p;i++)
    {
        printf("%d ",critical_vertice[i]+1);
    }
    putchar('\n');
}

void print_neibourhood(void)
{
    int i;
    fprintf(f_log,"This is the neiborhood\n");
    for(i=0;i<Critical_v_p*(color_num-1);i++)
    {
        fprintf(f_log,"No %d,vertice is %d,color is %d,f(s) is %d\n",i+1,Neighbourhood[i].v,Neighbourhood[i].c,Neighbourhood[i].fs);
    }
    fprintf(f_log,"The best move: vertice is %d,color is %d,f(s)is %d\n",best.v,best.c,best.fs);
}

void print_answer(void)
{
    fp=fopen("./answer.txt","w");
    fprintf(fp,"The solution color number is %d\n",color_num);
    int i,j;
    fputc('\n',fp);
    for(i=0;i<color_num;i++)
    {
        fprintf(fp,"color %d color:",i+1);
        for(j=0;j<Vertices_Num;j++)
        {
            if(vertice_color[j]==i)
            {
                fprintf(fp,"%d;",j+1);
            }
        }
        fputc('\n',fp);
    }
        //fprintf(fp,"\nf(s)=%d\nstep is %d\n",optimize_num,step);
        //fprintf(fp,"the function is been used for %d times\n",jishuqi);
    fclose(fp);
}

void print_tabu_list(void)
{
    int i,j;
    fprintf(f_log,"This is Tabu list\n");
    for(i=0;i<Vertices_Num;i++)
    {
        for(j=0;j<color_num;j++)
        {
           fprintf(f_log,"%d ",Tabu_list[i][j]);
        }
        fputc('\n',f_log);
    }
}
