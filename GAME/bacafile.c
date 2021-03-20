#include "bacafile.h"
#include "mesinkar.h"
#include "mesinkata.h"


char KenaliBangunan (int c){

	if(c==0){
		return 'B';
	}
	else if (c==1){
		return 'S';
	}
	else if(c==2){
		return IntToChar(1);
	}
	else {
		return IntToChar(c-1);
	}
}

char IntToChar(int c){
	if (c==0){
		return '0';
	}
	else if (c==1){
		return '1';
	}
	else if (c==2){
		return '2';
	}
	else if (c==3){
		return '3';
	}
	else if (c==4){
		return '4';
	}
	else if (c==5){
		return '5';
	}
	else if (c==6){
		return '6';
	}
	else if (c==7){
		return '7';
	}
	else if (c==8){
		return '8';
	}
	else if (c==9){
		return '9';
	}
	
}

int CharToInt(char c){
	if (c=='0'){
		return 0;
	}
	else if (c=='1'){
		return 1;
	}
	else if (c=='2'){
		return 2;
	}
	else if (c=='3'){
		return 3;
	}
	else if (c=='4'){
		return 4;
	}
	else if (c=='5'){
		return 5;
	}
	else if (c=='6'){
		return 6;
	}
	else if (c=='7'){
		return 7;
	}
	else if (c=='8'){
		return 8;
	}
	else if (c=='9'){
		return 9;
	}
	
}

int getpanjangPeta(pembacaan Q){
	if(Q.panjangPeta[1]==' '){

		int d = CharToInt(Q.panjangPeta[0]); 
		return d;

	}
	else{
		int c = CharToInt(Q.panjangPeta[0]);
		int b = CharToInt(Q.panjangPeta[1]);
		int a = c*10 + b;
		return a;
	}
}


int getlebarPeta(pembacaan Q){
	if(Q.lebarPeta[1]==' '){

		int d = CharToInt(Q.lebarPeta[0]); 
		return d;

	}
	else{
		int c = CharToInt(Q.lebarPeta[0]);
		int b = CharToInt(Q.lebarPeta[1]);
		int a = c*10 + b;
		return a;
	}
}


int getbanyakBangunan(pembacaan Q){

	return CharToInt(Q.banyakbangunan);
}


MATRIKS getMatriksAdjacency(pembacaan Q){

	return Q.adjacency;
}

int getxBangunan (char c, pembacaan Q){

	bangunan search;
	int i;
	for (i = 0 ; i<getbanyakBangunan(Q);i++){
		if((Q.T[i].jenis) == c){
			search = Q.T[i];
			i=getbanyakBangunan(Q);
	    }
	}
	if(search.x[1] == ' '){
		int a = CharToInt(search.x[0]);
		return a;
	}
	else{
		int b = CharToInt(search.x[0]);
		int c = CharToInt(search.x[1]);
		int d = b*10+c;
		return d;
	}
}


int getyBangunan (char c, pembacaan Q){

	bangunan search;
	int i;
	for (i = 0 ; i<getbanyakBangunan(Q);i++){
		if((Q.T[i].jenis) == c){
			search = Q.T[i];
			i=getbanyakBangunan(Q);
	    }
	}
	if(search.y[1] == ' '){
		int a = CharToInt(search.y[0]);
		return a;
	}
	else{
		int b = CharToInt(search.y[0]);
		int c = CharToInt(search.y[1]);
		int d = b*10+c;
		return d;
	}
}

int getYFromBangunan(bangunan search){

	if(search.y[1] == ' '){
		int a = CharToInt(search.y[0]);
		return a;
	}
	else{
		int b = CharToInt(search.y[0]);
		int c = CharToInt(search.y[1]);
		int d = b*10+c;
		return d;
	}
}

int getXFromBangunan(bangunan search){
	if(search.x[1] == ' '){
		int a = CharToInt(search.x[0]);
		return a;
	}
	else{
		int b = CharToInt(search.x[0]);
		int c = CharToInt(search.x[1]);
		int d = b*10+c;
		return d;
	}
}
	
/**********baca file eksternal*******/
pembacaan baca () {
    pembacaan Q;
	START();
	/*********baca ukuran peta**********/
	Q.panjangPeta[0]=' ';
	Q.panjangPeta[1]=' ';
	Q.lebarPeta[0]=' ';
	Q.lebarPeta[1]=' ';
	
	Q.lebarPeta[0]=CC;
	ADV();
	IgnoreBlank();
	Q.lebarPeta[1]=CC;
	ADV();
	IgnoreBlank();
	Q.panjangPeta[0]=CC;
	ADV();
	IgnoreBlank();
	Q.panjangPeta[1]=CC;
	/*********baca banyak bangunan**********/
	ADV();
	IgnoreBlank();
	Q.banyakbangunan=CC;
	ADV();
	IgnoreBlank();
	/*********baca letak bangunan**********/
	int i;
	for (i = 0 ; i<=CharToInt(Q.banyakbangunan);i++){

		Q.T[i].y[1]=' ';
		Q.T[i].x[1]=' ';
		Q.T[i].y[0]=' ';
		Q.T[i].x[0]=' ';

	}

	i = 0;
	while (i<CharToInt(Q.banyakbangunan)){

			Q.T[i].jenis=CC;
			
			ADV();
			IgnoreBlank();
			Q.T[i].y[0]=CC;
			
			ADV();
			if(CC==' '){
				
						IgnoreBlank();
					
						Q.T[i].x[0]=CC;
						
						ADV();
						if(CC=='\n'){
								IgnoreBlank();
								i++;

						}

						else{
								Q.T[i].x[1]=CC;
								ADV();
								IgnoreBlank();
								i++;
			               				
			            }
			}
			else{
						
						Q.T[i].y[1]=CC;
						
						ADV();
						IgnoreBlank();
						Q.T[i].x[0]=CC;
						
						ADV();
						if(CC=='\n'){
								IgnoreBlank();
								i++;
						}
						else{
								Q.T[i].x[1]=CC;
								ADV();
								IgnoreBlank();
								i++;
						}
			}
			
    }
    // /*********baca adjacency matriks**********/
	MakeMATRIKS(getbanyakBangunan(Q),getbanyakBangunan(Q),&(Q.adjacency));
	
    for (i = 1; i<=getbanyakBangunan(Q);i++){
    	int j;
		for (j = 1; j<=getbanyakBangunan(Q);j++){
 			Elmt(Q.adjacency,i,j)=CC;   		
    		ADV();
    		IgnoreBlank();
    	}
    }   

	for (i = 0 ; i < getbanyakBangunan(Q) ; i++){

		Q.P[i].X = getXFromBangunan(Q.T[i]);
		Q.P[i].Y = getYFromBangunan(Q.T[i]);
		Q.P[i].name = Q.T[i].jenis;

	}	

	for (i = 2 ; i < getbanyakBangunan(Q) ; i++){

		Q.P[i].name = IntToChar(i-1);

	}	
	Q.posisi=Q.P[0];

    return Q;
}
