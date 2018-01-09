#include<stdio.h>
char startVertex,endVertex, Vertex;
int weight=0;
int **makeGraph(int maxRouter)
{

        int **mgraph;
        int i=0, j=0;
        mgraph = (int **)calloc(maxRouter,sizeof(int*));
                for(i=0; i<maxRouter; i++)
                {
                        mgraph[i] = (int*)calloc(maxRouter,sizeof(int));
                }

        return mgraph;
}
int **addLink(int **graph,int maxRouter)
{            
        int i=0, j=0;
        int **mgraph=NULL; 
        while(fgetc(stdin)!='\n');
         
        printf("Enter the Link :\n");
        scanf("%c %c" ,&startVertex,&endVertex);
        mgraph=makeGraph(maxRouter);
        i=getIndex(startVertex,maxRouter);
        j=getIndex(endVertex,maxRouter);
        printf("Enter the weight:\n"); 
        scanf("%d", &weight);
        graph[i][j] = weight;
        graph[j][i] = weight;
        for(i=0; i<maxRouter; i++)
        {
                for(j=0; j<maxRouter; j++) 
                {
                        mgraph[i][j]=graph[i][j]; 
                        printf("%d ", mgraph[i][j]);
                }
                printf("\n");
        }
        return mgraph;
}

int **deleteLink(int **graph, int maxRouter)
{
        int i=0, j=0;
        int **mgraph=NULL;
        while(fgetc(stdin)!='\n');
        mgraph=makeGraph(maxRouter);
        printf("Enter the Link :\n");
        scanf("%c %c" ,&startVertex,&endVertex);
        i=getIndex(startVertex,maxRouter);
        j=getIndex(endVertex,maxRouter);
        graph[i][j]=9999;
        graph[j][i]=9999;
        for(i=0; i<maxRouter; i++)
        {
                for(j=0; j<maxRouter; j++)
                {
                        mgraph[i][j]=graph[i][j];
                        printf("%d ", mgraph[i][j]);
                }
                printf("\n");
        }
        return mgraph;

}


int **deleteRouter(int **graph, int maxRouter, int nodesDel)
{
        int i=0, j=0,index=0,k=0,l=0;
        int **mgraph = NULL;
        while(fgetc(stdin)!='\n');
        printf("Enter the name of delete router: \n");
        scanf("%c" ,&Vertex);
        mgraph=makeGraph(maxRouter-1);
        index=getIndex(Vertex,maxRouter);

        for(i=0; i<maxRouter; i++)
        {
                if(index==i)
                        continue;
                for(j=0; j<maxRouter; j++)
                {
                        if(index==j)
                                continue;
                        mgraph[l][k]=graph[i][j];
                        k++;
                }
                k = 0;

                l++;
        }
        for(i=0; i<maxRouter-1; i++)
        {
                for(j=0; j<maxRouter-1; j++)
                {
                        printf("%d", mgraph[i][j]);
                }
                printf("/n");
        }
        return mgraph;
}


int **addRouter(int **graph, int maxRouter)
{
        int i=0, j=0, k=0, link=0;
        int **mgraph = NULL;

        while(fgetc(stdin)!='\n');
        printf("Enter the name of new router : \n");
        scanf("%c", &Vertex);

        maxRouter=maxRouter+1;
        mgraph=makeGraph(maxRouter);

        for(i=0; i<maxRouter-1; i++)
        {

                for(j=0; j<maxRouter-1; j++)
                {

                        mgraph[i][j]=graph[i][j];
                }
                mgraph[i][j]=9999;

        }

        for(i=0; i<maxRouter; i++)
        {
                mgraph[maxRouter-1][i]=9999;
        }
        mgraph[maxRouter-1][maxRouter-1]=0;
        for(i=0; i<maxRouter; i++)
        {
                for(j=0; j<maxRouter; j++)
                {
                        printf("%d  ", mgraph[i][j]);
                }
                printf("\n");
        }


        printf("Enter the no of link: \n");
        scanf("%d", &link);

        for(k=0; k<link; k++)
        {


                while(fgetc(stdin)!='\n');
                printf("Enter the new link :\n");
                scanf("%c %c" ,&startVertex,&endVertex);
                i=getIndex(startVertex,maxRouter);
                j=getIndex(endVertex,maxRouter);
                printf("Enter the weight:\n");
                scanf("%d", &weight);
                mgraph[i][j] = weight;
                mgraph[j][i] = weight;
        }
        return mgraph;

}

