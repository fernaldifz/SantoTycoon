#include "player.h"
#include "string.h"
#include <stdio.h>

int SearchItem(List I, char* Nama){
/* Mengecek apakah item sudah ada di inventory */
    int i;
    boolean Found;

    i = 0;
    Found = false;
    while ((i < Length(I)) && (!Found)){
        // printf("Pencarian ke-%d\n", i+1);
        // printf("Kata 1: %s\n", Item(I,i));
        // printf("Kata 2: %s\n", Nama);
        if (strcmp(Item(I,i),Nama) == 0){
            Found = true;
        }else{
            i++;
        }
    }

    if (Found){
        return i;
    }else{
        return PNil;
    }
}

void TambahItem(List *I, char* Nama, char* Kateg, int Harga){
/* Menambahkan nama, kategori, dan harga item ke dalam inventory */
    int Idx;
    Idx = SearchItem(*I,Nama);
    if(Idx == PNil){
        InsertLast(I,Nama,Kateg,Harga);
    }
    else{
        Count(*I,Idx)++;
    }
}

void HapusItem(List *I, char* Nama){
/* Menghapus item dari inventory */
/* Prekondisi: Komponen ada dalam inventory */
    int Idx;
    Idx = SearchItem(*I,Nama);

    if(Count(*I,Idx) == 1){
        DeleteAt(I,Nama,Idx);
    }
    else{
        Count(*I,Idx)--;
    }
}
