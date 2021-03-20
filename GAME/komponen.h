/* File: komponen.h */
#ifndef Komponen_H
#define Komponen_H
#define IdxMax 24

typedef struct {
    char* Nama_Komponen;
    char* Kategori;
    int Harga;
} Komponen;

typedef struct {
    Komponen Tab[IdxMax+1];
} ArrKomponen;

/* Selektor */
#define NamaK(T,i) (T)->Tab[(i)].Nama_Komponen
#define Kategori(T,i) (T).Tab[(i)].Kategori
#define Harga(T,i) (T).Tab[(i)].Harga

void TambahNama (ArrKomponen *T);
/* Menambahkan nama-nama komponen ke dalam array */

void TambahKategori (ArrKomponen *T);
/* Menambahkan jenis-jenis kategori ke dalam array */

void TambahHarga (ArrKomponen *T);
/* Menambahkan harga komponen ke dalam array */

#endif
