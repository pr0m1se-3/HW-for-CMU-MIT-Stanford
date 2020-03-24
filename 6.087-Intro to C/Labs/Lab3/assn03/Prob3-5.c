#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define STRSIZE 100 
#define NFIELDS 9
int main()
{
    char inputfile []="stateoutflow0708.txt" ; /*define all the fields*/
    char state_code_org[STRSIZE ];
    char country_code_org[STRSIZE];
    char state_code_dest[ STRSIZE] ;
    char country_code_dest[STRSIZE ];
    char state_abbrv[ STRSIZE];
    char state_name[STRSIZE ];
    char line [STRSIZE*NFIELDS];
    int return_num=0;
    int exmpt_num=0;
    int aggr_agi=0;
    long total=0;
    /* file related*/
    int fields_read=0;
    FILE* fp=fopen(inputfile , "r");
    if(fp==NULL)
    {
    fprintf(stderr , "Cannot open fileln" ); 
    exit(-1);
    }
    /*skip first line*/
    fgets(line , STRSIZE*NFIELDS,fp );
    /*print the header*/
    printf("%-30s,%6s\n" , "STATE" , "TOTAL" );
    printf("---------------------------------------\n" );
    while( fgets(line,STRSIZE*NFIELDS,fp))
    {
        /*parse the fields*/
        fields_read=sscanf(line , "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d" ,
                            state_code_org ,
                            country_code_org ,
                            state_code_dest,
                            country_code_dest,
                            state_abbrv ,
                            state_name ,
                            &return_num ,
                            &exmpt_num ,
                            &aggr_agi );
        if(strcmp(state_code_org , "\"25\"")==0)
        {
            printf("%-30s,%6d\n" ,state_name, aggr_agi);
            total+= aggr_agi ;
        }
    }
    /*print the header*/
    printf("---------------------------------------\n" );
    printf ("%-30s,%6lu\n" , " TOTAL " , total) ;
    fclose(fp );
    return 0;
}