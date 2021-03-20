# include "graf.h"
# include <stdlib.h>
# include <stdio.h>

void CreateGraph(Graph *G, int nodeCount)
{
	adrNode P = AlokNode(1);
	First(*G) = P;
	
	int i;
	for(i=2;i<=nodeCount;i++)
	{
		adrNode Ptemp = AlokNode(i);
		Next(P) = Ptemp;
		P = Ptemp;
	}

}

adrNode AlokNode (infotype X)
{
	adrNode P;
    P = (adrNode) malloc (sizeof(Node));
    
    if (P!=Nil){
    	Id(P)=X;
		Trail(P)=Nil;
		Next(P)=Nil;
    	return P;
    } 
	else{
    	return Nil;
    }
}

adrSuccNode AlokSuccNode (infotype X)
{
	adrSuccNode P;
    P = (adrSuccNode) malloc (sizeof(SuccNode));
    
    if (P!=Nil){
    	Id(P)=X;
		NextSucc(P)=Nil;
    	return P;
    } 
	else{
    	return Nil;
    }
}

void InsertNode (adrNode P, infotype X)
{
	adrSuccNode Q = AlokSuccNode(X);
	if(IsNodeEmpty(P)){
		Trail(P) = Q;
	}
	else{
		adrSuccNode V = Trail(P);
		while(NextSucc(V) != Nil){
			V = NextSucc(V);
		}
		NextSucc(V) = Q;
	}
}

void InsertNodeP(Graph *G, infotype N, infotype M)
{
	adrNode P = First(*G);
	int i;
	for(i = 2; i <= N; i++){
		P = Next(P);
	}
	InsertNode(P, M);
}

boolean IsConnected(Graph G, infotype N, infotype M)
{
	adrNode P = First(G);
	boolean result = false;

	int i;
	for(i=2;i<=N;i++){
		P = Next(P);
	}
	adrSuccNode Q = Trail(P);
	while(!result && Q!=Nil)
	{
		if(Id(Q)==M){
			result = true;
		}
		else{
			Q = NextSucc(Q);
		}
	}
	return result;
}

boolean IsNodeEmpty(adrNode P)
{
	return(Trail(P) == Nil);
}

void PrintGraph(Graph G)
{
	adrNode P  = First(G);
	while(P!=Nil)
	{
		printf("Node %d is connected to:\n", Id(P));
		
		// Traverse connections
		adrSuccNode Q = Trail(P);
		while(Q!=Nil)
		{
			printf("\tNode %d\n", Id(Q));
			Q = NextSucc(Q);
		}
		printf("==================================\n");

		P = Next(P);
	}
	
}
