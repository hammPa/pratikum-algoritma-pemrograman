#include <iostream>
#include <string>
using namespace std;

#define MAX_BARANG 10
#define MAX_JENIS_BARANG 10
#define MAX_PEMBELI 10

int indexBarang = 0;
int indexJenisBarang = 0;

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

string namaJenisBarang[10] = {
    "Sabun", "Minuman", "Makanan Ringan", "Minuman Bubuk", "Shampo Botol",
    "", "", "", "", ""
};
string namaBarang[10][10] = {
    {"Lux", "Lifebuoy", "Shinzui", "Dove", "Biore"},
    {"Sprite Mini", "Sprite", "Fanta", "Teh Pucuk", "Fanta Mini"},
    {"Malkist Keju", "Chitato", "Roma Kelapa", "Wafello Coklat", "Beng-Beng"},
    {"Creamy Latte", "Milo", "Torabiko Cappucino", "Dancow", "Beng-Beng Bubuk"},
    {"Clear Botol", "Dove Botol", "Pantene Botol", "Sunsilk Botol", "Lifebuoy Botol"}
};
float hargaBarang[10][10] = {
    {4000, 5000, 4500, 5500, 6000},
    {3500, 5500, 5500, 3500, 3500},
    {7000, 3000, 10000, 5500, 2000},
    {2000, 2500, 2500, 2500, 2000},
    {14000, 14500, 15500, 12600, 11500}
};

void databaseInit(){
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        jenisBarang[i].namaJenisBarang = namaJenisBarang[i]; 
        for(int j = 0; j < MAX_BARANG; j++){
            jenisBarang[i].barang[j].nama = namaBarang[i][j];
            jenisBarang[i].barang[j].harga = hargaBarang[i][j];
            jenisBarang[i].barang[j].jumlahBarang = 10;
        }
    }
}

void displayAll(){
    bool kosong;
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        
        kosong = jenisBarang[i].namaJenisBarang.empty() || jenisBarang[i].namaJenisBarang == "";
        if(kosong) break; // jika namaJenisBarang kosong, looping selesai
        
        cout << "Jenis Barang : " << jenisBarang[i].namaJenisBarang << endl;
        for(int j = 0; j < MAX_BARANG; j++){
            
            kosong = jenisBarang[i].barang[j].nama == "" || jenisBarang[i].barang[j].nama.empty();
            if(kosong) break; // jika tidak ada barang, looping selesai
            cout << jenisBarang[i].barang[j].nama << endl;
            cout << jenisBarang[i].barang[j].harga << endl;
            cout << jenisBarang[i].barang[j].jumlahBarang << endl;
        }
    }
}

void displayMenu(int *pilihan){
    cout << "Selamat datang di program kasir" << endl;
    cout << "Berikut fitur yang tersedia  : " << endl;
    cout << "1. Menampilkan Semua Stok Barang" << endl;
    cout << "2. Menambah Stok Barang" << endl;
    cout << "3. Mencari Barang" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Cetak Struk Belanja" << endl;
    cout << "6. Keluar Program" << endl;
    cout << "Masukkan pilihan anda : ";
    cin >> *pilihan;
}

int main(){

    int pilihan;
    bool berhenti = false;
    databaseInit();
    do {
        displayMenu(&pilihan);
        switch(pilihan){
            case 1:
                system("cls");
                displayAll();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                berhenti = true;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while(!berhenti);
    
    return 0;
}