char vertex[20]={};
int getIndex(char ,int );
int next[5][5];
char path[10];
int p=0;

int  print(int **graph, int n)
{
        int i,j;
        for(i=0; i<n; i++)
        {
                for(j=0; j<n; j++)
                {
                        if(i==j)
                        {
                                graph[i][j]=0;
                        }
                        printf(" %d",graph[i][j]);
                }
                printf("\n");
        }
}


void addEdge(char  vertexS, char  vertexD,int weight, int maxrouter, int **graph)
        {
                int i ,j;
                i=getIndex(vertexS,maxrouter);
                j=getIndex(vertexD,maxrouter);
                  graph[i][j] = weight;
                  graph[j][i] = weight;
        }

int getIndex(char name,int leng)
        {
                int i;
                for(i = 0; i < leng ; i++)
                {
                        if( vertex[i] == '\0' )
                        {
                                vertex[i] = name;
                                return (i);
                        }
                        else if ( vertex[i] == name)
                        {
                                return (i);
                        }
                }
        return (-1);
       }

char getPath(int i, int j, int **graph)
{
        printf("in function getpath :i %c\n",path[p]);
        if(graph[i][j]==9999)
                printf("no path");
                return 0;
        char inter = (char)(next[i][j]);
        if(inter =='\0')
        {
                printf("%c",inter);
                printf("  ");
                return 0;
        }
        else{
                        printf("%c", inter);
                        path[p++]=getPath(i,(int)inter,graph);
                        path[p++]=inter;
                        path[p++]=getPath((int)inter,j,graph);
                        return path[p];
        }
        return (-1);
}

void warshall(int **graph, int maxRouter)
{
        int i,j, k;
        for(k=0; k<maxRouter; k++)
                for(i=0; i<maxRouter; i++)
                        for(j=0; j<maxRouter; j++)
                        {
                                if( graph[i][j] > graph[i][k] + graph[k][j])
                                {
                                        graph[i][j] = graph[i][k] + graph[k][j];
                                        next[i][j]=k;
                                        printf("%d %d %d\n",graph[i][j],graph[i][k],graph[k][j]);
                                }
                        }
        //print(graph,maxRouter);
        getPath(0,4,graph);
        //printf("%s",path);
}
