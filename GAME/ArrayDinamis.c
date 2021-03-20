# include "ArrayDinamis.h"	
# include <stdlib.h>
# include <stdio.h>

List MakeList()
/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
 {
	List list;
    list.A = (Storage*) malloc(InitialSize * sizeof(Storage));
    list.Capacity = InitialSize;
    list.Neff = 0;
	CreateEmptyList(&list);
    return list;
 }

void CreateEmptyList(List *list)
/**
 * Prosedur untuk menginisialisasi count dengan 0
 */
{
	int i;
	for(i = 0; i < GetCapacity(*list); i++){
		Count(*list,i) = 0;
	}

}

void DeallocateList(List *list)
/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
 {
 	free((*list).A);
 }
boolean IsEmpty(List list)
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
 {
 	return list.Neff == 0;
 }
 
int Length(List list)
/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
 {
 	return list.Neff;
 }

Storage Get(List list, IdxType i)
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
 {
 	return list.A[i];
 }
 
int GetCapacity(List list)
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
 {
 	return list.Capacity;
 }
 
void InsertAt(List *list, char* el, char* cat, int harga, IdxType i)
/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
 {
 	int index;
 	if(Length(*list) == GetCapacity(*list)){
 		int newCapacity = GetCapacity(*list) + InitialSize;
 		Storage* newArray = (Storage*) malloc(newCapacity * sizeof(Storage));
		
		for(index=0; index<Length(*list); index++){
			newArray[index] = Get(*list, index);
		}
		
		free((*list).A);
		
		(*list).A = newArray;
		(*list).Capacity = newCapacity;
	}

	for(index = (Length(*list)-1); index >= i; index--){
		(*list).A[index+1] = (*list).A[index];
	}
	
	(*list).A[i].Item = el;
	(*list).A[i].Kategori = cat;
	(*list).A[i].Harga = harga;
	(*list).A[i].count = (*list).A[i].count + 1;	
    (*list).Neff++;
 }
 
void InsertLast(List *list, char* el, char* cat, int harga)
/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
 {
    InsertAt(list, el, cat, harga, Length(*list));
 }
 
void InsertFirst(List *list, char* el,char* cat, int harga)
{
	InsertAt(list, el, cat, harga, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: list terdefinisi
 */
void DeleteAt(List *list, char* el, IdxType i){
	int Idx;
	for(Idx = i+1; Idx < (*list).Neff; Idx++){
		(*list).A[Idx-1] = (*list).A[Idx];
	}
	(*list).A[Idx-1].Item = "DELETED";
	(*list).A[Idx-1].Kategori = "DELETED";
	(*list).A[Idx-1].Harga = 0;
	(*list).A[Idx-1].count = 0;
	(*list).Neff--;
}

/**
 * Fungsi untuk menghapus elemen pertama
 * Prekondisi: list terdefinisi
 */
void DeleteFirst(List *list, char* el){
	DeleteAt(list,el,0);
}

/**
 * Fungsi untuk menghapus elemen terakhir
 * Prekondisi: list terdefinisi
 */
void DeleteLast(List *list, char* el){
	DeleteAt(list,el,Length(*list));
}
