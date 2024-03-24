#include <stdio.h>

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

int isTahunKabisat(int tahun) {
    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) {
        return 1;
    }
    return 0;
}

struct Tanggal hitungTanggalBerikutnya(struct Tanggal tanggalSekarang) {
    int jumlahHariDalamBulan[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (tanggalSekarang.bulan == 2 && isTahunKabisat(tanggalSekarang.tahun)) {
        jumlahHariDalamBulan[2] = 29;
    }
    
    tanggalSekarang.hari++;
    
    if (tanggalSekarang.hari > jumlahHariDalamBulan[tanggalSekarang.bulan]) {
        tanggalSekarang.hari = 1;
        tanggalSekarang.bulan++;
        
        if (tanggalSekarang.bulan > 12) {
            tanggalSekarang.bulan = 1;
            tanggalSekarang.tahun++;
        }
    }
    
    return tanggalSekarang;
}

int main() {
    struct Tanggal tanggalSekarang, tanggalBerikutnya;
    
    printf("Masukkan tanggal (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &tanggalSekarang.hari, &tanggalSekarang.bulan, &tanggalSekarang.tahun);
    
    tanggalBerikutnya = hitungTanggalBerikutnya(tanggalSekarang);
    
    printf("Tanggal berikutnya: %d/%d/%d\n", tanggalBerikutnya.hari, tanggalBerikutnya.bulan, tanggalBerikutnya.tahun);
    
    return 0;
}
