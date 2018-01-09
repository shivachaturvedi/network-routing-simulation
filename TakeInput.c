
#include<stdio.h>
#include"initialize.c"
#include"delete.c"
int** readInput();

        int **graph =NULL;
        int maxRouter = 0;
        int **ngraph=NULL;

int main()
{
        int **mgraph=NULL;
        int i=0, j=0;
        int** mybuffer=NULL;
        mybuffer=readInput();
        print(graph,maxRouter);

printf("--------------------------------------------------* Link ADD *--------------------------------------------------- \n");
        mgraph=addLink(graph,maxRouter);
        warshall(mgraph,maxRouter);
        print(mgraph,maxRouter);
printf("--------------------------------------------------* Link Delete *------------------------------------------------ \n");
        mgraph=deleteLink(graph,maxRouter);
        warshall(mgraph,maxRouter);
        print(mgraph,maxRouter);
printf("--------------------------------------------------* Router Add *-------------------------------------------------\n");
        mgraph=addRouter(graph, maxRouter);
        maxRouter=(maxRouter+1);
        ngraph=mgraph;
        warshall(mgraph, maxRouter);
        print(mgraph, maxRouter);
printf("--------------------------------------------------* Delete Router *-----------------------------------------------\n");
        mgraph=deleteRouter(ngraph, maxRouter,1);
        ngraph=mgraph;
        warshall(mgraph,maxRouter-1);
        print(mgraph,maxRouter-1);      
    

return 0; 
}

int** readInput()
{
        FILE *reader=NULL;
        int i=0,j,weight=0;
        int** g1=NULL;
        int ch=0;
        char v1='\0',v2='\0',sp;
        char *fileName = (char*)calloc(20,sizeof(char));
        printf("\n\n\n  Enter the name of the Test file : ");
        scanf("%s",fileName);
        reader = fopen(fileName,"r");
        if(reader == NULL){
                printf("\n\n  File is not available or you do not have sufficient rights to access it!!\n\n");
                exit(-1);
        }
        else{
                printf("\n\t  File opened .... \n\t  Examining file contents..... \n");
                printf("\n\t  Reading Input from the Test File .....\n\n");

                sleep(3);
                //printf("\n\t  Storing file data in the structure [readBuffer] ....\n\n");
                //sleep(2);
                fscanf(reader, "%d", &maxRouter);
                graph = (int **)calloc(maxRouter,sizeof(int*));
                for(i=0; i<maxRouter; i++)
                {
                        graph[i] = (int*)calloc(maxRouter,sizeof(int));
                }
                //graph=Graph(maxRouter);
                for(i=0;i<maxRouter;i++)
                {
                        for(j=0;j<maxRouter;j++)
                        {
                                graph[i][j]=9999;
                        }
                }
                printf("\n\t Select the Algorithm:");
                printf("\n\t Distance Vector: 1");
                printf("\n\t Link State: 2 \n");
                //printf("enter the choice \n");
                fscanf(reader, "%d", &ch);
                fgetc(reader);
                switch(ch)
                {
                        case 1:while(feof(reader)==0)
                                {

                                        fscanf(reader,"%c",&v1);
                                        fgetc(reader);
                                        fscanf(reader,"%c",&v2);
                                        fgetc(reader);
                                        fscanf(reader,"%d",&weight);
                                        fgetc(reader);
                                        //validation for valid edges will be here.
                                        addEdge(v1,v2,weight,maxRouter,graph);
                                        //printf("%c %c %d \n", v1, v2, weight);
                                }
                                break;
                        case 2:break;
                        default:printf("Hi");
                                break;
                }
        }
        g1=graph;
        return g1;
}
     