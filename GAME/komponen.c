#include "komponen.h"

void TambahNama (ArrKomponen *T){
    // Motherboard
    NamaK(T,0) = "ASUS H61M-A";
    NamaK(T,1) = "ASRock H81 Pro BTC";
    NamaK(T,2) = "Gigabyte Socket 1151 GA-H110M-DS2";

    // CPU
    NamaK(T,3) = "Intel Processor Core i7-8700K";
    NamaK(T,4) = "AMD Ryzen 7 5800X";
    NamaK(T,5) = "Intel Processor Core i7-10700KF";

    // Memory
    NamaK(T,6) = "Corsair Vengeance Pro 8GB (2X4GB) DDR3 PC17000";
    NamaK(T,7) = "Team Elite Plus TPD48GM2400HC16DC01 8GB DDR4";
    NamaK(T,8) = "Corsair Dominator Platinum 32GB (2X16GB) DDR4 PC24000";
    
    // CPU Cooler
    NamaK(T,9) = "ID-COOLING SE-224-XT";
    NamaK(T,10) = "Deepcool Gammax GT A-RGB";
    NamaK(T,11) = "Cooler Master HYPER 212 RGB Black Edition";

    // Case
    NamaK(T,12) = "Cooler Master MASTERBOX LITE 3.1";
    NamaK(T,13) = "CORSAIR Carbide SPEC-02";
    NamaK(T,14) = "Corsair Carbide 330R Titanium Edition";

    // GPU
    NamaK(T,15) = "MSI Geforce GTX 1650 Aero ITX 4G OC";
    NamaK(T,16) = "MSI NVIDIA GeForce GTX 1050 Ti GTX1050 Ti 4G OC V1";
    NamaK(T,17) = "MSI AMD Radeon R9-270X GAMING 2G";

    // Storage
    NamaK(T,18) = "ADATA XPG SX8000 256GB PCIe Gen3x4 M.2 2280 SSD";
    NamaK(T,19) = "KINGSTON M.2 SATA SSD 240GB Gen 2.0 SM2280S3G2/240G";
    NamaK(T,20) = "WD Black 1TB WDS100T2X0C";

    // PSU
    NamaK(T,21) = "REDRAGON Gaming PC Power Supply RGPS 500W Full Range GC-PS001";
    NamaK(T,22) = "THERMALTAKE Smart RGB 500W [PS-SPR-0500NHSAWE1]";
    NamaK(T,23) = "CORSAIR CXM Series CX650M [CP-9020103-EU]";
}

void TambahKategori (ArrKomponen *T){
    int i;
    for (i = 0; i < 3; i++){
        Kategori(*T,i) = "Motherboard";
    }
    
    for (i = 3; i < 6; i++){
        Kategori(*T,i) = "CPU";
    }
    
    for (i = 6; i < 9; i++){
        Kategori(*T,i) = "Memory";
    }

    for (i = 9; i < 12; i++){
        Kategori(*T,i) = "CPU Cooler";
    }

    for (i = 12; i < 15; i++){
        Kategori(*T,i) = "Case";
    }

    for (i = 15; i < 18; i++){
        Kategori(*T,i) = "GPU";
    }

    for (i = 18; i < 21; i++){
        Kategori(*T,i) = "Storage";
    }
    
    for (i = 21; i < 24; i++){
        Kategori(*T,i) = "PSU";
    }
}

void TambahHarga (ArrKomponen *T){
    // Motherboard
    Harga(*T,0) = 600;
    Harga(*T,1) = 830;
    Harga(*T,2) = 1000;

    // CPU
    Harga(*T,3) = 4600;
    Harga(*T,4) = 7500;
    Harga(*T,5) = 5500;

    // Memory
    Harga(*T,6) = 750;
    Harga(*T,7) = 270;
    Harga(*T,8) = 2800;

    // CPU Cooler
    Harga(*T,9) = 420;
    Harga(*T,10) = 520;
    Harga(*T,11) = 770;

    // Case
    Harga(*T,12) = 650;
    Harga(*T,13) = 1000;
    Harga(*T,14) = 1600;

    // GPU
    Harga(*T,15) = 2300;
    Harga(*T,16) = 2500;
    Harga(*T,17) = 3000;

    // Storage
    Harga(*T,18) = 2300;
    Harga(*T,19) = 1500;
    Harga(*T,20) = 3500;

    // PSU
    Harga(*T,21) = 800;
    Harga(*T,22) = 1000;
    Harga(*T,23) = 1300;
    
}