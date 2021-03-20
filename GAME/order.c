#include "order.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TambahPemesan(ArrNama *N){
    NamaP(N,0) = "Pelanggan 1";
    NamaP(N,1) = "Pelanggan 2";
    NamaP(N,2) = "Pelanggan 3";
    NamaP(N,3) = "Pelanggan 4";
    NamaP(N,4) = "Pelanggan 5";
    NamaP(N,5) = "Pelanggan 6";
    NamaP(N,6) = "Pelanggan 7";
}

void TambahOrderan(Queue *Q, ArrNama N, ArrKomponen K, int Jumlah){
    int count = 0;
    srand(time(0));
    CreateQueueEmpty(Q);
    
    while (count != Jumlah){
        // Pembentukan List Komponen
        Komponen X;
        Stack Daftar_Komponen;
        CreateStackEmpty(&Daftar_Komponen);
    
        float sum = 0;
        int i = rand();
        int j = 0;

        while (!IsStackFull(Daftar_Komponen)){
            // Pengisian Komponen
            X.Nama_Komponen = NamaK(&K,(i % 3 + j));
            X.Kategori = Kategori(K,(i % 3 + j));
            X.Harga = Harga(K,(i % 3 + j));
            sum = sum + X.Harga + (X.Harga * 0.1);
            j += 3;

            // Push Stack
            Push(&Daftar_Komponen,X);
        }

        Enqueue(Q, NamaP(&N,(i%7)), Daftar_Komponen, sum);
        count++;
    }
}

void PrintOrder(Queue Q){
    printf("Nomor Order: %d\n", NoOrder(Q));
    printf("Pemesan: %s\n", NPemesan(Q));
    printf("Invoice: $%d\n", TotalH(Q));
    printf("Komponen: \n");

    Stack A;
    CreateStackEmpty(&A);
    CopyStack(LKomponen(Q),&A);
    InverseStack(&A);
    int i = 1;
    s_infotype X;

    while (!(IsStackEmpty(A))){
        printf("%d. %s\n", i, NamaKomp(A));
        Pop(&A,&X);
        i++;
    }
}
