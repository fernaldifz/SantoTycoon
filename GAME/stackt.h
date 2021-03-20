/* File: stack.h */
/* Implementasi Stack dalam bahasa C dengan alokasi statik */
#ifndef stack_H
#define stack_H
#include "boolean.h"
#include "komponen.h"

#define SNil -1
#define MaxEl 8

typedef Komponen s_infotype;   
typedef int s_address;        /* indeks tabel */
typedef struct {
    s_infotype T[MaxEl];      /* tabel penyimpan elemen */
    s_address TOP;            /* alamat TOP: elemen puncak */
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* Definisi akses dengan Selektor: */
#define Top(S) (S).TOP              
#define InfoTop(S) (S).T[(S).TOP]
#define NamaKomp(S) (S).T[(S).TOP].Nama_Komponen
#define KategoriKomp(S) (S).T[(S).TOP].Kategori
#define HargaKomp(S) (S).T[(S).TOP].Harga

/*** Prototype ***/

/*** Konstruktor/Kreator ***/
void CreateStackEmpty(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 */
/* Ciri stack kosong: TOP bernilai Nil */

/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong: TOP bernilai Nil */

boolean IsStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh: TOP bernilai MaxEl-1 */

/*********** Menambahkan sebuah elemen ke Stack **********/
void Push(Stack *S, s_infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/*********** Menghapus sebuah elemen Stack **********/
void Pop(Stack *S, s_infotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void CopyStack (Stack SIn, Stack *SOut);
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */

void InverseStack (Stack *S);
/* Membalik isi suatu stack */
/* I.S. S terdefinisi */
/* Isi S terbalik dari posisi semula */

#endif