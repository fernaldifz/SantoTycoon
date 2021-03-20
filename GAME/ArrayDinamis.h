#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "boolean.h"
#include "komponen.h"
#define InitialSize 20

typedef struct {
    char* Item;
    char* Kategori;
    int Harga;
    int count;
} Storage;

typedef int IdxType;
typedef struct {
    Storage *A;
    int Capacity;
    int Neff;
} List;

/* Selektor */
#define Item(L,i) (L).A[i].Item
#define Kateg(L,i) (L).A[i].Kategori
#define HargaK(L,i) (L).A[i].Harga
#define Count(L,i) (L).A[i].count

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList();

void CreateEmptyList(List *list);
/**
 * Prosedur untuk menginisialisasi count dengan 0
 */

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(List *list);

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsEmpty(List list);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list);

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
Storage Get(List list, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, char* el, char* cat, int harga, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, char* el, char* cat, int harga);

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(List *list, char* el, char* cat, int harga);

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: list terdefinisi
 */
void DeleteAt(List *list, char* el, IdxType i);

/**
 * Fungsi untuk menghapus elemen pertama
 * Prekondisi: list terdefinisi
 */
void DeleteFirst(List *list, char* el);

/**
 * Fungsi untuk menghapus elemen terakhir
 * Prekondisi: list terdefinisi
 */
void DeleteLast(List *list, char* el);

void InsertAtStatus(List *list, Komponen komponen, IdxType i);

#endif
