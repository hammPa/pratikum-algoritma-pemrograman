#include <iostream>
#include <string>
using namespace std;

#define MAX_BARANG 5
#define MAX_JENIS_BARANG 5
#define MAX_PEMBELI 10

typedef struct {
    string nama;
    float harga;
    int jumlahBarang;
} Barang;

typedef struct {
    string namaJenisBarang;
    Barang barang[MAX_BARANG];
} JenisBarang;

typedef struct {
    int idPelanggan;
    JenisBarang barang[MAX_BARANG];
    int totalBelanja;
} StrukBelanja;

JenisBarang jenisBarang[MAX_JENIS_BARANG];    
StrukBelanja strukBelanja[MAX_PEMBELI];

void databaseInit(){
    jenisBarang[0].namaJenisBarang = "Sabun";
    jenisBarang[0].barang[0].nama = "Lux";
    jenisBarang[0].barang[0].harga = 4000;
    jenisBarang[0].barang[0].jumlahBarang = 10;
    jenisBarang[0].barang[1].nama = "Lifebuoy";
    jenisBarang[0].barang[1].harga = 5000;
    jenisBarang[0].barang[1].jumlahBarang = 10;
    jenisBarang[0].barang[2].nama = "Shinzui";
    jenisBarang[0].barang[2].harga = 4500;
    jenisBarang[0].barang[2].jumlahBarang = 10;
    jenisBarang[0].barang[3].nama = "Dove";
    jenisBarang[0].barang[3].harga = 5500;
    jenisBarang[0].barang[3].jumlahBarang = 10;
    jenisBarang[0].barang[4].nama = "Biore";
    jenisBarang[0].barang[4].harga = 6000;
    jenisBarang[0].barang[4].jumlahBarang = 10;

    jenisBarang[1].namaJenisBarang = "Minuman";
    jenisBarang[1].barang[0].nama = "Sprite Mini";
    jenisBarang[1].barang[0].harga = 3500;
    jenisBarang[1].barang[0].jumlahBarang = 10;
    jenisBarang[1].barang[1].nama = "Sprite";
    jenisBarang[1].barang[1].harga = 5500;
    jenisBarang[1].barang[1].jumlahBarang = 10;
    jenisBarang[1].barang[2].nama = "Fanta";
    jenisBarang[1].barang[2].harga = 5500;
    jenisBarang[1].barang[2].jumlahBarang = 10;
    jenisBarang[1].barang[3].nama = "Teh Pucuk";
    jenisBarang[1].barang[3].harga = 3500;
    jenisBarang[1].barang[3].jumlahBarang = 10;
    jenisBarang[1].barang[4].nama = "Fanta Mini";
    jenisBarang[1].barang[4].harga = 3500;
    jenisBarang[1].barang[4].jumlahBarang = 10;

    jenisBarang[2].namaJenisBarang = "Makanan Ringan";
    jenisBarang[2].barang[0].nama = "Malkist Keju";
    jenisBarang[2].barang[0].harga = 7000;
    jenisBarang[2].barang[0].jumlahBarang = 10;
    jenisBarang[2].barang[1].nama = "Chitato";
    jenisBarang[2].barang[1].harga = 3000;
    jenisBarang[2].barang[1].jumlahBarang = 10;
    jenisBarang[2].barang[2].nama = "Roma Kelapa";
    jenisBarang[2].barang[2].harga = 10000;
    jenisBarang[2].barang[2].jumlahBarang = 10;
    jenisBarang[2].barang[3].nama = "Wafello Coklat";
    jenisBarang[2].barang[3].harga = 5500;
    jenisBarang[2].barang[3].jumlahBarang = 10;
    jenisBarang[2].barang[4].nama = "Beng-Beng";
    jenisBarang[2].barang[4].harga = 2000;
    jenisBarang[2].barang[4].jumlahBarang = 10;

    jenisBarang[3].namaJenisBarang = "Minuman Bubuk";
    jenisBarang[3].barang[0].nama = "Creamy Latte";
    jenisBarang[3].barang[0].harga = 2000;
    jenisBarang[3].barang[0].jumlahBarang = 10;
    jenisBarang[3].barang[1].nama = "Milo";
    jenisBarang[3].barang[1].harga = 2500;
    jenisBarang[3].barang[1].jumlahBarang = 10;
    jenisBarang[3].barang[2].nama = "Torabiko Cappucino";
    jenisBarang[3].barang[2].harga = 2500;
    jenisBarang[3].barang[2].jumlahBarang = 10;
    jenisBarang[3].barang[3].nama = "Dancow";
    jenisBarang[3].barang[3].harga = 2500;
    jenisBarang[3].barang[3].jumlahBarang = 10;
    jenisBarang[3].barang[4].nama = "Beng-Beng Bubuk";
    jenisBarang[3].barang[4].harga = 2000;
    jenisBarang[3].barang[4].jumlahBarang = 10;

    jenisBarang[4].namaJenisBarang = "Shampo Botol";
    jenisBarang[4].barang[0].nama = "Clear Botol";
    jenisBarang[4].barang[0].harga = 14000;
    jenisBarang[4].barang[0].jumlahBarang = 10;
    jenisBarang[4].barang[1].nama = "Dove Botol";
    jenisBarang[4].barang[1].harga = 14500;
    jenisBarang[4].barang[1].jumlahBarang = 10;
    jenisBarang[4].barang[2].nama = "Pantene Botol";
    jenisBarang[4].barang[2].harga = 15500;
    jenisBarang[4].barang[2].jumlahBarang = 10;
    jenisBarang[4].barang[3].nama = "Sunsilk Botol";
    jenisBarang[4].barang[3].harga = 12600;
    jenisBarang[4].barang[3].jumlahBarang = 10;
    jenisBarang[4].barang[4].nama = "Lifebuoy Botol";
    jenisBarang[4].barang[4].harga = 11500;
    jenisBarang[4].barang[4].jumlahBarang = 10;
}

void displayMenu(int *pilihan){
    cout << "Selamat datang di program kasir" << endl;
    cout << "Berikut fitur yang tersedia  : " << endl;
    cout << "1. Menambah Stok Barang" << endl;
    cout << "2. Mencari Barang" << endl;
    cout << "3. Pembayaran" << endl;
    cout << "4. Cetak Struk Belanja" << endl;
    cout << "5. Keluar Program" << endl;
    cout << "Masukkan pilihan anda : ";
    cin >> *pilihan;
}

int main(){

    int pilihan;
    bool berhenti = false;
    do {
        displayMenu(&pilihan);
        switch(pilihan){
            case 1:
                system("cls");
                // cout << 
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                berhenti = true;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while(!berhenti);
    
    return 0;
}