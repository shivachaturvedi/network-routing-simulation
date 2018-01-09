#include <stdio.h>
#include<malloc.h>

int maxRouters = 0;
int count = 0;

int *hopSequence = NULL;

int* storePath(int val,int *hopSequence);

int** makeGraph(int maxRouter){
	 hopSequence = (int*)calloc(1000,sizeof(int));

	maxRouters = maxRouter;

	int **ptr = (int**)calloc(maxRouter,sizeof(int*));

	int i = 0, j = 0, k= 0;

	for(i = 0; i<maxRouter; i++){

		ptr[i] = (int*)calloc(maxRouter,sizeof(int));
	}

return ptr;
}

void takeValues(int **graph,int maxRouter){

	int i = 0;
	int j = 0;

	printf("\n\n Enter the cost of the edges\n");

	for(i = 0; i<maxRouter; i++){

		for(j = 0; j<maxRouter; j++){

			if(i!=j){
				//printf("%d to %d is: ",i,j);
				scanf("%d",&graph[i][j]);
				//scanf("%d",&graph[j][i]);
			}
			else
				graph[i][j] = 0;
		}
	}
}
void printGraph(int **graph,int maxRouter){

	int i = 0;
	int j = 0;
	char temp = 65;
	char temp1 = 65;
	printf("\n   ");
	for(i =0; i<maxRouter; i++){
		printf("%c	  ",temp);
		++temp;
	}
	printf("\n\n");

	for(i = 0; i<maxRouter; i++){
		
		printf("%c",temp1);
		++temp1;
		printf("   ");
		
		for(j = 0; j<maxRouter; j++){

			if(graph[i][j] == 9999){
				
				printf("#	  ");
			}else{
				printf("%d	  ",graph[i][j]);
			}
		}
	printf("\n\n");
	}
printf("\n\n");
}

void floydfn(int **cost,int **d,int **path,int maxRouter){


int i,j,k;

int **dt = makeGraph(maxRouter);
int **pt = makeGraph(maxRouter);
int n = maxRouter;

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			d[i][j]=cost[i][j];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if ((d[i][j]==0) || (d[i][j] == 9999))
				path[i][j]=0;
			else
				path[i][j]=i;

	for (k=0;k<n;k++){

		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				dt[i][j]=d[i][j];
	
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				d[i][j]=min(dt[i][j],dt[i][k]+dt[k][j]);

		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				pt[i][j]=path[i][j];
	
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (dt[i][j]>(dt[i][k]+dt[k][j]))
					path[i][j]=pt[k][j];
}

	printf("\nOUTPUT COST MATRIX:\n\n");
	printGraph(d,n);
	printf("\nPATH MATRIX:\n\n");
	printGraph(path,n);
}

int min(int x,int y){

	int minimum;
	minimum=(x<=y)?x:y;

return minimum;
}

void short_path(int i,int j,int **path){



	int f = 0;
	

	if (i==j){

		//printf("%d  ",i);
		hopSequence[count]=i;
		++count;
	}
	else{

		short_path(i,path[i][j],path);	
		//printf(" %d",j);
		hopSequence[count]=j;
		++count;
	}


}


