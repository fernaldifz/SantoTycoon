#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "bacafile.h"
#include "graf.h"
#include "move_map.h"


void MAP (pembacaan Q){


	MATRIKS peta;
	MakeMATRIKS(getlebarPeta(Q),getpanjangPeta(Q),&peta);
    int i;
	for (i = BrsMin; i <= NBrsEff(peta); i++){
        int j;
		for (j = KolMin; j <= NKolEff(peta); j++){
            Elmt(peta, i, j) = ' ';
	    }
	}
	
	for (i = 0; i<getbanyakBangunan(Q);i++){
		Elmt(peta,Q.P[i].Y,Q.P[i].X)=Q.P[i].name;
	}

	for (i = 0 ; i<getbanyakBangunan(Q);i++){

		if(Q.posisi.Y==Q.P[i].Y && Q.posisi.X==Q.P[i].X){
			Elmt(peta,Q.posisi.Y,Q.posisi.X) = 'P';

		}
	}

	TulisMATRIKS(peta);



}
	




void MOVE (pembacaan *Q){
	
	
	POINT search;
	int indeksLokasi;

	int i;
	for (i = 0; i<getbanyakBangunan(*Q);i++){
		if(Q->P[i].X==Q->posisi.X && Q->P[i].Y==Q->posisi.Y){
			indeksLokasi = i;
			i=getbanyakBangunan(*Q);
		}
	}

	char bangunan = KenaliBangunan(indeksLokasi);

	if (bangunan =='B'){
		printf("\nKamu berada pada base\n");
	}
	else if (bangunan == 'S'){
		printf("\nKamu berada pada Shop\n");
	}
	else{
		printf("\nKamu berada pada pelanggan %c\n", bangunan);
	}

	printf("\nDaftar lokasi yang dapat dicapai:\n");
    
    Graph G;
    CreateGraph(&G,getbanyakBangunan(*Q));
    for(i=1;i<=getbanyakBangunan(*Q);i++){

		int j;
        for(j=1;j<=getbanyakBangunan(*Q);j++){

            if( Elmt(Q->adjacency,i,j)=='1' || Elmt(Q->adjacency,i,j)=='1' ){
            	InsertNodeP(&G, i, j);
            }
        }
    }


    indeksLokasi++;
    
    int daftarTujuan[30];

	int hitung=0;

	for (i = 1;i<=getbanyakBangunan(*Q);i++){
		
		if((IsConnected(G,i,indeksLokasi))){

	        daftarTujuan[hitung]=i;
	        hitung++;

	    }
	}

	for (i = 0 ; i<hitung;i++){
		printf("\n%d",i+1);

		char bangunanTujuan = KenaliBangunan(daftarTujuan[i]-1);

		if (bangunanTujuan =='B'){
			printf(". base\n");
		}
		else if (bangunanTujuan == 'S'){
			printf(". Shop\n");
		}
		else{
			printf(". pelanggan %c\n", bangunanTujuan);
        }

	}

	printf("\n");
	printf("Nomor tujuan: ");
	int scan;
	scanf("%d",&scan);
    printf("\n");

	if(daftarTujuan[scan-1]==1){
		Q->posisi=Q->P[0];
	}
	else if(daftarTujuan[scan-1]==2){
		Q->posisi=Q->P[1];
	}
	else{
		Q->posisi=Q->P[daftarTujuan[scan-1]-1];
	}

}




