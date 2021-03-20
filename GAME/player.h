/* File: player.h */
#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "ArrayDinamis.h"
#include "komponen.h"

#define PNil -1

int SearchItem(List I, char* Nama);
/* Mengecek apakah item sudah ada di inventory */
/* Jika komponen terdapat inventory maka akan dihasilkan indeks dari komponen tersebut */
/* Jika tidak ada dalam inventory, akan dihasilkan Nil */

void TambahItem(List *I, char* Nama, char* Kateg, int Harga);
/* Menambahkan nama, kategori, dan harga item ke dalam inventory */

void HapusItem(List *I, char* Nama);
/* Menghapus item dari inventory */
/* Prekondisi: Komponen ada dalam inventory */

#endif