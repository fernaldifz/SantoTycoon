#include "mesinkata.h"
#include "mesinkar.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;
void IgnoreBlank()
{
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC ? BLANK atau CC = MARK */
    while ((CC == BLANK) | (CC == '\n'))
    {
        ADV();
    }

}

void STARTKATA()
{
    /* 
    I.S. : CC sembarang
    F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata 
    */
    START();
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
}
void ADVKATA()
{
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
        IgnoreBlank();
    }
}
void SalinKata()
{
    /* Mengakuisisi kata, menyimpan dalam CKata
    I.S. : CC adalah karakter pertama dari kata
    F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int i = 0;
    while ((CC != MARK) && (CC != BLANK) && (i <= NMax))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = (i < NMax) ? i : NMax;
}

boolean IsKataSama(Kata kata1, Kata kata2)
{
	boolean Sama = true;
	if(kata1.Length != kata2.Length){
		return false;
	}
	else{
		int i = 0;
		while (Sama && (i < kata2.Length)){
			if(kata1.TabKata[i] != kata2.TabKata[i]){
				Sama = false;
			}
			i++;
		}
		return Sama;
	}
}

int string_length(char* s){
	int c = 0;
	while(s[c] != '\0'){
		c++;
	}
	return c;
}

Kata MakeKata(char* command)
{
	Kata hasil;
	int panjang = string_length(command);
	int i = 0;
	while(i < panjang){
		hasil.TabKata[i] = command[i];
		i++;
	}
	hasil.Length = panjang;
	return hasil;
}

void STARTCOMMAND()
{
    STARTC();
	IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKataC();
    }
}

void SalinKataC()
{
	int i = 0;
    while ((CC != ENTER) && (i <= NMax))
    {
        CKata.TabKata[i] = CC;
        ADVC();
        i++;
    }
    CKata.Length = (i < NMax) ? i : NMax;
}
