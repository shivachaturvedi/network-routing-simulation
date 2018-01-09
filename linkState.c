#include <stdio.h>
#include <malloc.h>

#include "warshall.c"

int maxNodes = 0;
int **graph = NULL;
int **routingTable = NULL;

struct node{

	char name;
	int **myRoutingTable;	
};


typedef struct node new_router;

new_router** makeList(int maxNodes);

void calculateRatio(int **graph,int packetSize){

	int size_in_bits = packetSize*8;int ratio = 0;
	
	int i = 0; int j = 0; int k = 0;

	for(i = 0; i<maxNodes; i++){
		for(j = 0; j<maxNodes; j++){
		
			if(graph[i][j]!=0 && graph[i][j]!=9999){
				
				ratio = size_in_bits/graph[i][j];
			//	printf("\nRatio for bandwidth %d is %d\n",graph[i][j],ratio);
				
				if(ratio == 0){
				
					graph[i][j] = 1;
				}
				else{
					graph[i][j] = ratio;
				
				}

			}
		}
	}


}
void flushSequence(int *hopSequence){
	
	int j = 0;
		
	for(j = 0; j<maxNodes; j++){
			
		hopSequence[j] = 0;
	}
	
}
void copySequence(int *myPath){

	int i = 0;
	for(i = 0; i<maxNodes; i++){
		myPath[i] = hopSequence[i];
	}
}
int ** makeRoutingTable(int router,int **path){

	int **table = NULL;
	int i = 0; int j = 0; int k = 0;
	int *temp = NULL;
	int *myPath = NULL;

	table = (int**)calloc(maxNodes,sizeof(int*));
	
	for(i = 0; i<maxNodes; i++){


		short_path(router,i,path);
		
		myPath = (int*)calloc(maxNodes,sizeof(int));
		copySequence(myPath);
		flushSequence(hopSequence);
		table[i] = myPath;	

	count = 0;
	}
return table;
}

new_router** initList(new_router **list,int **path){

	int i = 0; int j = 0; int k = 0;

	int **temp = NULL;

	for(i = 0; i<maxNodes; i++){

		printf("\nPrinting the routing table for %d\n",i);
		list[i]->myRoutingTable = makeRoutingTable(i,path);
		printGraph(list[i]->myRoutingTable,maxNodes);
		flushSequence(hopSequence);


	}

}

int main(int argc, char **argv){


	int **distance = NULL;
	int **path = NULL;
	int **ratioGraph = NULL;
	
	int source = 0;
	int dest = 0;
	int packetSize = 0;

	scanf("%d",&maxNodes);

	printf("\nEnter the number of Routers to start with :");
	printf("\nEnter the packet size (in KB) :");
	
	scanf("%d",&packetSize);

	graph = makeGraph(maxNodes);	// Creating Adjency Matrix to hold the Graph

	distance = makeGraph(maxNodes);
	path = makeGraph(maxNodes);

	takeValues(graph,maxNodes);	//Reading Values and creating Adjancey Matrix
	printGraph(graph,maxNodes);
	calculateRatio(graph,packetSize);	

	printGraph(graph,maxNodes);
	floydfn(graph,distance,path,maxNodes);
	
//	scanf("%d",&source);scanf("%d",&dest);
//	short_path(source,dest,path);printf("\n");
	new_router **list = makeList(maxNodes);		// Creating a list of Nodes of the Routers
	
	list = initList(list,path);
	

return 0;
}

new_router** makeList(int maxNodes){

	new_router **list = (new_router**)calloc(maxNodes,sizeof(new_router*));
	int i = 0; int j = 0; int k = 0;

	for(i = 0; i<maxNodes; i++){

	list[i] = (new_router*)calloc(maxNodes,sizeof(new_router));

	}
return list;
}
