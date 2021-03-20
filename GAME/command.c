#include "command.h"
#include <stdio.h>

void ADDCOMPONENT(Stack *S, List *L, boolean StartBuild){
/* Memasang komponen pada komputer rakitan player */
    if(!StartBuild){
        printf("Mohon maaf perintah tidak dapat dilakukan,\n");
        printf("Anda belum memulai perakitan pesanan, ");
        printf("mohon gunakan perintah 'STARTBUILD' terlebih dahulu\n");
    }
    else{
        int i, j, input;
        if(IsEmpty(*L)){
            printf("Anda belum memiliki komponen apa pun,\n");
            printf("Mohon melakukan pembelian komponen dahulu!\n");
        }
        else{
            Stack A;
            CreateStackEmpty(&A);
            CopyStack(*S,&A);
            InverseStack(&A);   

            printf("Komponen yang telah terpasang:\n");
            i = 1;
            if (IsStackEmpty(A)){
                printf("Belum ada komponen yang terpasang\n");
            }
            s_infotype StackElmt;
            while (!IsStackEmpty(A)){
                printf("%d. %s\n", i, NamaKomp(A));
                Pop(&A,&StackElmt);
                i++;
            }

            printf("Komponen yang tersedia:\n");
            j = 0;
            while(j < Length(*L)){
                printf("%d. %s\n", j+1, Item(*L,j));
                j++;
            }
            
            printf("Komponen yang ingin dipasang: ");
            scanf("%d", &input);
            while((input < 1) || (input > j)){
                printf("Nomor komponen tidak sesuai, mohon input ulang: ");
                scanf("%d", &input);
            }
            
            s_infotype C;
            C.Nama_Komponen = Item(*L,input-1);
            C.Kategori = Kateg(*L,input-1);
            C.Harga = HargaK(*L,input-1);
            Push(S,C);
            HapusItem(L,Item(*L,input-1));
            printf("Komponen berhasil dipasang!\n");
        }
    }
}

void REMOVECOMPONENT(Stack *S, List *L, boolean StartBuild){
/* Mencopot komponen pada komputer rakitan player */
    if(!StartBuild){
        printf("Mohon maaf perintah tidak dapat dilakukan,\n");
        printf("Anda belum memulai perakitan pesanan, ");
        printf("mohon gunakan perintah 'STARTBUILD' terlebih dahulu\n");
    }
    else {
        if(IsStackEmpty(*S)){
            printf("Belum ada komponen yang terpasang,\n");
            printf("Silakan pasang komponen terlebih dahulu.\n");
        }
        else {
            s_infotype X;
            Pop(S,&X);
            TambahItem(L,X.Nama_Komponen,X.Kategori,X.Harga);
            printf("Komponen %s berhasil dicopot!\n", X.Nama_Komponen);
        }
    }
}

void END_DAY(Queue *Q, ArrNama N, ArrKomponen K){
/* Mengakhiri hari yang berjalan dan menuju keesokan hari */
    while (!IsQueueEmpty(*Q)){
        Dequeue(Q);
    }
    TambahOrderan(Q,N,K,10);
}
