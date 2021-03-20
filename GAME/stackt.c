#include "stackt.h"

/*** Prototype ***/

/*** Konstruktor/Kreator ***/
void CreateStackEmpty(Stack *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 */
/* Ciri stack kosong: TOP bernilai Nil */
    (*S).TOP = SNil;
}

/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean IsStackEmpty(Stack S){
/* Mengirim true jika Stack kosong: TOP bernilai Nil */
    return (S.TOP == SNil);
}

boolean IsStackFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh: TOP bernilai MaxEl-1 */
    return (S.TOP == MaxEl-1);
}

/*********** Menambahkan sebuah elemen ke Stack **********/
void Push(Stack *S, s_infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    (*S).TOP = (*S).TOP + 1;
    (*S).T[(*S).TOP] = X; 
}

/*********** Menghapus sebuah elemen Stack **********/
void Pop(Stack *S, s_infotype *X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = (*S).T[(*S).TOP];
    (*S).TOP = (*S).TOP - 1;
}

void CopyStack (Stack SIn, Stack *SOut){
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */
    Stack STemp;
    s_infotype X;
    CreateStackEmpty(&STemp);

    while (!IsStackEmpty(SIn)){
        Pop(&SIn,&X);
        Push(&STemp,X);
    }

    while (!IsStackEmpty(STemp)){
        Pop(&STemp,&X);
        Push(&SIn,X);
        Push(SOut,X);
    }
}

void InverseStack (Stack *S){
/* Membalik isi suatu stack */
/* I.S. S terdefinisi */
/* Isi S terbalik dari posisi semula */
    Stack STemp;
    s_infotype X;
    CreateStackEmpty(&STemp);
    while (!IsStackEmpty(*S)){
        Pop(S,&X);
        Push(&STemp,X);
    }

    CopyStack(STemp,S);
}