/* File: order.h */
#ifndef Order_H
#define Order_H
#include "stackt.h"
#include "queue.h"

#define NNama 20

typedef char* Orang;
typedef struct {
    Orang Tab[NNama+1];
} ArrNama;

/* Selektor */
#define NamaP(T,i) (T)->Tab[(i)]

void TambahPemesan(ArrNama *N);
/* Menambahkan nama pemesan ke dalam array pemesan */

void TambahOrderan(Queue *Q, ArrNama N, ArrKomponen K, int Jumlah);
/* Menambah orderan dengan menamahkan komponen terlebih ke dalam stack, kemudian */
/* menambahkan stack dan informasi lainnya ke Queue */

void PrintOrder(Queue Q);
/* Mencetak orderan pertama */

#endif

