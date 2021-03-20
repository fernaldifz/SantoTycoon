#include "boolean.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ArrayDinamis.h"
#include "matriks.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "graf.h"
#include "bacafile.h"
#include "move_map.h"
#include "komponen.h"
#include "player.h"
#include "point.h"
#include "order.h"
#include "queue.h"
#include "stackt.h"
#include "command.h"

// Data Player
int saldo = 21000;
List Inventory;

ArrKomponen A;
ArrNama N;
Queue AntrianPesanan;
Stack KomponenTerpasang;
char CInput[30];

int NomorPesanan;
char* NomorPemesan;

void init_component(){
    TambahNama(&A);
    TambahKategori(&A);
    TambahHarga(&A);
}

void init_order(){
    TambahPemesan(&N);
    TambahOrderan(&AntrianPesanan,N,A,10);
}

void init_game(){
    init_component();
    init_order();
}


int main () {
	printf("    ___  _____                      .d88888b                        dP\n");           
    printf(" .'/,-Y'     '~-.                   88.                             88\n");            
    printf(" l.Y             ^.                 `Y88888b.  .d8888b.  88d888b. d8888P .d8888b.\n"); 
    printf(" /\\               _\\_                 `8b 88' `88    88'`88    88   88' `88    88`\n"); 
    printf("i            ___/'   '\\             d8'   .8P  88.  .88  88    88   88   88.  .88\n"); 
    printf("|          /'   '\\   o !             Y88888P   `88888P8  dP    dP   dP   `88888P'\n");
    printf("l         ]     o !__./\n");
    printf("\\ _  _     \\.___./    '~\\                                                        MMP--MM--YMM                                             \n");
    printf("   X \\/ \\            ___./                                                       P'   MM   `7                                             \n");
    printf(" ( \\ ___.   _..--~~'   ~`-.                                                           MM `7M'   `MF',p6-");
    printf("bo   ,pW'");
    printf("Wq.   ,pW'");
    printf("Wq.`7MMpMMMb.  \n");
    printf("  ` Z,--   /               \\                                                          MM   VA   ,V 6M'  OO  6W'   `Wb 6W'   `Wb MM    MM  \n");
    printf("    \\__.  (   /       ______)                                                         MM    VA ,V  8M       8M     M8 8M     M8 MM    MM  \n");        
    printf("       \\   l  /-----~~' /                                                             MM     VVV   YM.    , YA.   ,A9 YA.   ,A9 MM    MM  \n");
    printf("       Y   \\          /                                                             .JMML.   ,V     YMbmd'   `Ybmd9'   `Ybmd9'.JMML  JMML.\n");
    printf("       |    'x______.^                                                                       ,V                                            \n");
    printf("       |           \\  )                                                                   OOb'\n");
    printf("                                                 _               _        _    _                                     \n");
    printf("                                             ___(_) _ __   _  _ | | __ _ | |_ (_) ___  _ _    __ _  __ _  _ __   ___ \n");
    printf("                                            (_-<| || '  \\ | || || |/ _` ||  _|| |/ _ \\| ' \\  / _` |/ _` || '  \\ / -_)\n");
    printf("                                            /__/|_||_|_|_| \\_,_||_|\\__,_| \\__||_|\\___/|_||_| \\__, |\\__,_||_|_|_|\\___|\n");
    printf("                                                                                             |___/                   \n");
    printf("\n");
    printf("                                                 [  ]=== ===== ==== ** M A I N  M E N U** ==== ===== ===[  ]\n");
    printf("                                                  ||                                                     ||\n");
    printf("                                                  ||                     >>  PLAY  <<                    ||\n");
    printf("                                                  ||                     >>  EXIT  <<                    ||\n");
    printf("                                                  ||                                                     ||\n");
    printf("                                                 [  ]=== ===== ==== === === ===== === === ==== ===== ===[  ]\n");
    printf("\n");
	printf("                                                                     Enter Menu: ");
    STARTCOMMAND();
    printf("\n");
    
    boolean repeat = true;
    
    /* Hanya memperindah, saat input command menggunakan ADT Mesin Kata dan Mesin Karakter */
	while ((!IsKataSama(CKata, MakeKata("PLAY"))) && (!IsKataSama(CKata, MakeKata("EXIT")))){
    	printf("Input tidak sesuai, mohon masukkan input yang tertulis di atas.\n");
    	printf("Enter menu: ");
    	STARTCOMMAND();
    	printf("\n");
	}
	
	if(IsKataSama(CKata, MakeKata("EXIT"))){
		repeat = false;
		printf("Game telah berhasil dihentikan, sampai jumpa!\n");
	}
	
	int i;
    init_game();
    Inventory = MakeList();
    CreateStackEmpty(&KomponenTerpasang);
    boolean StartBuild = false;
	
	pembacaan Q;
	Q=baca();
	
	while(repeat){
		printf("ENTER COMMAND: ");
		STARTCOMMAND();
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		if(IsKataSama(CKata, MakeKata("MOVE"))){                    	
			MOVE(&Q);
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("MAP"))){				
			MAP(Q);
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("STARTBUILD"))){			
			int indeksLokasi;
			int a;
			for (a = 0; a<getbanyakBangunan(Q);a++){
				if(Q.P[a].X==Q.posisi.X && Q.P[a].Y==Q.posisi.Y){
					indeksLokasi = a;
					a=getbanyakBangunan(Q);
				}
			}
			char bangunan = KenaliBangunan(indeksLokasi);
			if (bangunan == 'B'){
				CreateStackEmpty(&KomponenTerpasang);
				printf("Kamu telah memulai pesanan %d untuk pelanggan %s", NoOrder(AntrianPesanan), NPemesan(AntrianPesanan));
				printf("\n");
				StartBuild = true;
			}
			else{
				printf("Kamu gagal memulai pesanan karena tidak berada di base!");
				printf("\n");
			}
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("FINISHBUILD"))){		
			Stack As,B;
    		s_infotype xAs, xB;
    		CreateStackEmpty(&As);
    		CreateStackEmpty(&B);
    		CopyStack(KomponenTerpasang,&As);
    		CopyStack(LKomponen(AntrianPesanan),&B);

    		if ((Top(As) != Top(B)) && (StartBuild)){
        		printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
    		}
    		else if (!StartBuild){
				printf("Mohon maaf perintah tidak dapat dilakukan,\n");
        		printf("Anda belum memulai perakitan pesanan, ");
        		printf("mohon gunakan perintah 'STARTBUILD' terlebih dahulu\n");
			}
    		else {
        		boolean IsStackSama = true;
        		while((!IsStackEmpty(As)) && (IsStackSama)){
            		if (NamaKomp(As) != NamaKomp(B)){
                		IsStackSama = false;
            		}
            		else {
                		Pop(&As,&xAs);
                		Pop(&B,&xB);
            		}
        		}

        		if ((IsStackSama) && (StartBuild)){
            		StartBuild = false;

            		/* Nomor Orderan */
            		int Nomor = NoOrder(AntrianPesanan);
            		char NomorP[5] = "";
            		sprintf(NomorP, "%d", Nomor);

            		/* Concat String */
            		char X[50] = "";
            		char* C1 = "Build untuk Pesanan #";
            		char* C2 = NomorP;
            		strcat(X,C1);
            		strcat(X,C2);
            		char* T = X;
            		TambahItem(&Inventory, T, "Build", TotalH(AntrianPesanan));            		
            		printf("Pesanan %d telah selesai. Silakan antar ke %s!\n", NoOrder(AntrianPesanan), NPemesan(AntrianPesanan));
            		
            		NomorPesanan = NoOrder(AntrianPesanan);
					NomorPemesan = NPemesan(AntrianPesanan);
            		
            		Dequeue(&AntrianPesanan);
            		TambahOrderan(&AntrianPesanan,N,A,1);
        		}
        		else {
            		printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
        		}
    		}
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("ADDCOMPONENT"))){
			ADDCOMPONENT(&KomponenTerpasang,&Inventory,StartBuild);
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("REMOVECOMPONENT"))){
			REMOVECOMPONENT(&KomponenTerpasang,&Inventory,StartBuild);
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("CHECKORDER"))){
			PrintOrder(AntrianPesanan);
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("STATUS"))){
			char* lokasi;
			printf("Uang tersisa: $%d\n", saldo);
    		printf("Build yang sedang dikerjakan: pesanan %d untuk %s.\n", NoOrder(AntrianPesanan), NPemesan(AntrianPesanan));
    		int indeksLokasi;
			int a;
			for (a = 0; a<getbanyakBangunan(Q);a++){
				if(Q.P[a].X==Q.posisi.X && Q.P[a].Y==Q.posisi.Y){
					indeksLokasi = a;
					a=getbanyakBangunan(Q);
				}
			}
			char bangunan = KenaliBangunan(indeksLokasi);
    		if (bangunan == 'B') {
        		lokasi = "Base";
        		printf("Lokasi: Pemain sedang berada pada %s.\n", lokasi);
    		}
    		else if (bangunan == 'S') {
        		lokasi = "Shop";
        		printf("Lokasi: Pemain sedang berada pada %s.\n", lokasi);
    		}
    		else {
        		lokasi = "Pelanggan";
        		printf("Lokasi: Pemain sedang berada pada %s %c.\n", lokasi, bangunan);
    		}
			
			printf("Inventory anda:\n");
			if (IsEmpty(Inventory)){
				printf("Inventory kosong.\n");
			}
			else {
				for(i = 0;i < Length(Inventory); i++){
                	printf("%d. %s (%s) - %d\n", i+1, Item(Inventory,i), Kateg(Inventory,i), Count(Inventory,i));
            	}
            	printf("\n");	
			}
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("SHOP"))){
			int indeksLokasi;
			int a;
			for (a = 0; a<getbanyakBangunan(Q);a++){
				if(Q.P[a].X==Q.posisi.X && Q.P[a].Y==Q.posisi.Y){
					indeksLokasi = a;
					a=getbanyakBangunan(Q);
				}
			}
			char bangunan = KenaliBangunan(indeksLokasi);
			if (bangunan == 'S'){
				ArrKomponen H;
    			TambahNama(&H);
    			TambahKategori(&H);
    			TambahHarga(&H);
    			printf("Komponen yang tersedia:\n");
    			int i;
    			for (i = 0; i < 24; i++){
        			printf("%d. %s (%s) - $%d\n", (i+1), NamaK(&H,i), Kategori(H,i), Harga(H,i));
				}
	
				printf("Komponen yang ingin dibeli: ");
				int number;
				scanf("%d", &number);
				while((number>24)||(number<1)){
					printf("Komponen yang diinginkan tidak tersedia di toko!\n");
					printf("Komponen yang ingin dibeli: ");
					scanf("%d", &number);
				}
	
				printf("Masukkan jumlah yang ingin dibeli: ");
				int count;
				scanf("%d", &count);
				while(count<1){
					printf("Jumlah yang diinginkan tidak valid!\n");
					printf("Masukkan jumlah yang ingin dibeli: ");
					scanf("%d", &count);
				}
				if(saldo > (Harga(H,(number-1))*count)){
					saldo -= (Harga(H,(number-1))*count);
					for(i = 0; i < count; i++){
						TambahItem(&Inventory, NamaK(&H,(number-1)), Kategori(H, (number-1)), Harga(H, (number-1)));	
					}
					printf("Komponen berhasil dibeli!\n");
				}
				else{
					printf("Uang tidak cukup!\n");
				}
			}
			else{
				printf("Maaf Anda tidak berada di Shop!");
			}
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("DELIVER"))){
			int Nomor = NoOrder(AntrianPesanan);
            char NomorP[5] = "";
            sprintf(NomorP, "%d", Nomor);
            		
			char X[50] = "";
            char* C1 = "Build untuk Pesanan #";
            char* C2 = NomorP;
            strcat(X,C1);
            strcat(X,C2);
            char* T = X;
			
			int indeksLokasi;
			int a;
			for (a = 0; a<getbanyakBangunan(Q);a++){
				if(Q.P[a].X==Q.posisi.X && Q.P[a].Y==Q.posisi.Y){
					indeksLokasi = a;
					a=getbanyakBangunan(Q);
				}
			}
			char bangunan = KenaliBangunan(indeksLokasi);
	
			if((bangunan == 'B') || (bangunan == 'S')){
				printf("ERROR! Maaf Anda berada di lokasi yang salah!\n");
			}
			else{
				if (bangunan != NomorPemesan[10]){
					printf("ERROR! Maaf Anda berada di lokasi yang salah!\n");
				}
				else{
					if (SearchItem(Inventory, T) == Nil){
						printf("Maaf Anda belum memiliki pesanan untuk diantar!\n");
					}
					else{
						saldo += HargaK(Inventory, SearchItem(Inventory, T));
						HapusItem(&Inventory,T);
						printf("Pesanan #%d berhasil diantarkan kepada %s!", NomorPesanan, NomorPemesan);
						printf("\n");
					}
				}
			}
		}
			
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("END_DAY"))){
			END_DAY(&AntrianPesanan,N,A);
			printf("Hari telah selesai,\n");
			printf("Hari telah berganti, silakan melanjutkan permainan.\n");
		}
		
		/***** 			 *****/
		/*****  COMMAND  *****/ 
		/*****			 *****/
		else if(IsKataSama(CKata, MakeKata("EXIT"))){
			repeat = false;
			printf("Terima kasih sudah bermain, sampai jumpa kembali!\n");
		}
		
		else{
			printf("COMMAND TIDAK VALID");
		}
		printf("\n");
	}	
	return 0;
}

