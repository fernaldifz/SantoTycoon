#ifndef __BACAFILE_H__
#define __BACAFILE_H__

#include "mesinkar.h"
#include "matriks.h"
#include "point.h"

#define maks 100

typedef struct 
{
   char jenis;
   char x[2];
   char y[2];
   
}bangunan;

typedef struct
{

	char panjangPeta[2];
	char lebarPeta[2];
	char banyakbangunan;
	bangunan T[maks];
	MATRIKS adjacency;
	POINT P[maks];
	POINT posisi;


} pembacaan;

/**********baca file eksternal*******/

pembacaan baca ();

char KenaliBangunan (int c);

char IntToChar(int c);

int CharToInt(char c);

int getpanjangPeta(pembacaan Q);

int getlebarPeta(pembacaan Q);

int getbanyakBangunan(pembacaan Q);

MATRIKS getMatriksAdjacency(pembacaan Q);

int getxBangunan (char c, pembacaan Q);

int getyBangunan (char c, pembacaan Q);

int getYFromBangunan (bangunan search);

int getXFromBangunan (bangunan search);


#endif
