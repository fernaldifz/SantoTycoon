/* ADT Adjacency List */

#ifndef _GRAPH_
#define _GRAPH_

#include "boolean.h"
#define Nil 0

typedef int infotype;
typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNode { 
	infotype Id;
	adrSuccNode Trail;
	adrNode Next;
} Node;

typedef struct tSuccNode {
	infotype Id;
	adrSuccNode NextSucc;
} SuccNode;

typedef struct {
	adrNode First;
} Graph;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define First(G) ((G).First)
#define Id(P) (P)->Id
#define Trail(P) (P)->Trail
#define Next(P) (P)->Next
#define NextSucc(P) (P)->NextSucc

/* *** Konstruktor *** */
void CreateGraph (Graph *G, int nodeCount);
/* I.S. Sembarang */
/* F.S. Terbentuk Graph dengan jumlah node X */

/* *** Manajemen Memory List Simpul (Leader) *** */
adrNode AlokNode (infotype X);
/* Mengembalikan address hasil alokasi Simpul X */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Trail(P)=Nil, dan Next(P)=Nil. 
Jika alokasi gagal, mengembalikan Nil */

/* *** Manajemen Memory List Successor (Trailer) *** */
adrSuccNode AlokSuccNode (infotype X);
/* Mengembalikan address hasil alokasi */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Id(Pt)=X dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil */

/* *** Fungsi/Prosedur Lain *** */
void InsertNode (adrNode P, infotype X);
/* Menambahkan SuccNode */

void InsertNodeP (Graph *G, infotype N, infotype M);
/* Melakukan penghubungan dengan node N */

void PrintGraph (Graph G);
/* Melakukan pencetakan Graph */

boolean IsConnected (Graph G, infotype N, infotype M);
/* Mengecek apakah simpul Y ditunjuk oleh simpul X atau tidak */
/* Simpul X pasti ada di graph */

boolean IsNodeEmpty(adrNode P);
/* Mengecek apakah node tersebut kosong atau tidak */

void PrintGraph(Graph G);
/* Melakukan print graph */
#endif
