/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR__
#define __MESIN_KAR__
#include "boolean.h"
#define MARK '.'
#define BLANK ' '

boolean EndKata;
extern char CC;
boolean EOP;

void START();
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/

void ADV();
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F' 
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/

void STARTC();

void ADVC();

#endif
