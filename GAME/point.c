/* File: point.c */
/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include "boolean.h"
#include "math.h"
#include "point.h"

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y, char V)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT a;
    Absis(a) = X;
    Ordinat(a) = Y;
    Nama(a) = V;
    return a;
}


/* *** Kelompok operasi relasional terhadap POINT *** */
boolean IsSamePoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
