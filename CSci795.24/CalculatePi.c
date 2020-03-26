#include<mpi.h>
#include<stdio.h>
#include<math.h>
#define ROOT 0
double calculate(int id,int segment,int process_num)
{
    double sum=0;
    double dx=1.0/segment;


    for(int i=id;i<=segment;i+=process_num)
    {
        double x=(i-0.5)*dx;
        sum+=1.0/(1.0+x*x);
    }
    return 4.0*dx*sum;
}

int main(int argc , char *argv[])
{
    int id;
    int process_num;
    double estimatePI;
    double tempsum=0;
    int segment;
    MPI_Init( &argc , &argv );
    MPI_Comm_rank( MPI_COMM_WORLD , &id );
    MPI_Comm_size(MPI_COMM_WORLD,&process_num);
    while(1)
    {
        if(ROOT==id)
        {
            printf("Enter tje number of intervals:\n");
            fflush(stdout);
            scanf("%d",&segment);
        }
        MPI_Bcast (&segment , 1, MPI_INT , ROOT , MPI_COMM_WORLD);
        if(segment==0)
            break;
        tempsum=calculate(id,segment,process_num);

        MPI_Reduce(&tempsum,&estimatePI,1,MPI_DOUBLE,MPI_SUM , 0, MPI_COMM_WORLD);
        if(ROOT==id)
        {
            printf(" pi is approximated to be %.16f. The error is %.16f\n" , estimatePI , fabs(estimatePI - M_PI));
            fflush(stdout);
        }
    }
    MPI_Finalize (); 
    return 0;
}