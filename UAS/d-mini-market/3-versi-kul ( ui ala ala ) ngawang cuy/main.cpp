#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_BARANG 5
#define MAX_JENIS_BARANG 10
#define MAX_PEMBELI 10

int indexBarang = 0;
int indexJenisBarang = 0;
int indexPelanggan = 0;
int id = 1;

typedef struct {
    string nama;
    float harga;
    int jumlahBarang;
    bool beli = true;
} Barang;

typedef struct {
    string namaJenisBarang;
    Barang barang[MAX_BARANG];
} JenisBarang;

typedef struct {
    int idPelanggan;
    Barang barang[MAX_BARANG];
    int totalBelanja = 0;
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
    string space = " ";
    string indent = "";
    bool kosong;
    int nomor = 1;
    cout << "---------------------------------------------------" << endl;
    cout << "| No | Jenis Barang | Nama | Harga | JumlahBarang |" << endl;
    cout << "---------------------------------------------------" << endl;
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        
        kosong = jenisBarang[i].namaJenisBarang.empty() || jenisBarang[i].namaJenisBarang == "";
        if(kosong) break; // jika namaJenisBarang kosong, looping selesai
        
            
        for(int j = 0; j < MAX_BARANG; j++){
            kosong = jenisBarang[i].barang[j].nama == "" || jenisBarang[i].barang[j].nama.empty();
            if(kosong) break; // jika tidak ada barang, looping selesai
            
            (nomor<10 ? indent = space : indent = "");
            cout << "| " << nomor << indent << " | " << jenisBarang[i].namaJenisBarang << " ";
            cout << " | " << jenisBarang[i].barang[j].nama << " ";
            cout << " | " << jenisBarang[i].barang[j].harga << " ";
            cout << " | " << jenisBarang[i].barang[j].jumlahBarang << "|" << endl;
            nomor++;
        }
        indexJenisBarang++;
    }
    cout << "---------------------------------------------------" << endl;
}

void displayMenu(int *pilihan){
    cout << "Selamat datang di program kasir" << endl;
    cout << "Berikut fitur yang tersedia  : " << endl;
    cout << "1. Menampilkan Semua Stok Barang" << endl;
    cout << "2. Menambah Stok Barang" << endl;
    cout << "3. Mencari Barang" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Cetak Struk Belanja" << endl;
    cout << "6. Simpan Data" << endl;
    cout << "7. Keluar Program" << endl;
    cout << "Masukkan pilihan anda : ";
    cin >> *pilihan;
}

void addNewStock(){
    JenisBarang temp;
    int index = 0;
    char ulang;

    cout << "Masukkan jenis barang : ";
    cin >> temp.namaJenisBarang;
    do {
        cout << "Masukkan nama barang : ";
        cin >> temp.barang[index].nama;
        cout << "Masukkan harga barang : ";
        cin >> temp.barang[index].harga;
        cout << "Masukkan jumlah barang : ";
        cin >> temp.barang[index].jumlahBarang;
        index++;
        cout << "Tambah barang lain ?(Tidak boleh barang yang sama) y/n : ";
        cin >> ulang;
    } while(ulang == 'Y' || ulang =='y');
    jenisBarang[indexJenisBarang] = temp;
    cout << "Menambah barang berhasil!!" << endl; 
    cin.get();
}

void addStock(){
    int namaJenisBarang, namaBarang, jumlahBarang;
    int i;
    int j;
    cout << "Jenis barang tersedia : " << endl;
    for(i = 0; i < indexJenisBarang; i++) cout << i+1 << "." << jenisBarang[i].namaJenisBarang << endl;
    cout << "\nMasukkan jenis barang yang ingin di tambah : ";
    cin >> namaJenisBarang;
    
    system("cls");
    cout << "Barang yang tersedia : " << endl;
    for(j = 0; j < MAX_BARANG; j++) cout << j+1 << "." << jenisBarang[namaJenisBarang].barang[j].nama << endl;

    cout << "\nMasukkan barang yang akan ditambah : ";
    cin >> namaBarang;

    cout << "Masukkan jumlah barang baru yang akan ditambah : ";
    cin >> jumlahBarang;

    jenisBarang[namaJenisBarang].barang[namaBarang].jumlahBarang = jumlahBarang;
    cout << "Berhasil di tambah!!" << endl;
}

void inputStock(){
    int pilih;
    cout << "1. Jenis barang baru" << endl;
    cout << "2. Barang yang sudah ada" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilih;
    if(pilih==1) addNewStock();
    else addStock();
}

void searchStock(){
    string nama;
    cout << "Masukkan nama barang yang ingin di cari : ";
    cin >> nama;
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        for(int j = 0; j < MAX_BARANG; j++){
            if(jenisBarang[i].barang[j].nama == nama){
                cout << "Barang ditemukan, berikut detailnya : " << endl;
                cout << "Nama barang : " << jenisBarang[i].barang[j].nama << endl;
                cout << "Harga barang :" << jenisBarang[i].barang[j].harga << endl;
                cout << "Stok tersedia : " << jenisBarang[i].barang[j].jumlahBarang << endl;
            }
            else {
                cout << nama << " tidak ditemukan" << endl;
            }
        }
    }
}

bool searchName(string nama){
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        for(int j = 0; j < MAX_BARANG; j++){
            if(jenisBarang[i].barang[j].nama == nama) return true;
            else return false;
        }
    }
}

void payment(){
    string nama[5];
    int jumlah[5];
    int i = 0;
    bool result[5]; 
    do{
        cout << "Masukkan nama barang ke-" << i+1 << " : ";
        cin >> nama[i];
        cout << "Masukkan jumlah barang ke-" << i+1 << " : ";
        cin >> jumlah[i];
        result[i] = searchName(nama[i]);
        
        if(result[i]){
            float harga = strukBelanja[indexPelanggan].barang[i].harga;
            strukBelanja[indexPelanggan].idPelanggan = id;
            strukBelanja[indexPelanggan].barang[i].jumlahBarang = jumlah[i];
            strukBelanja[indexPelanggan].totalBelanja += (harga * jumlah[i]);
        }
        else {
            strukBelanja[indexPelanggan].barang[i].beli = false;
        }
        i++;
    } while(i<5);
    cout << "Total Belanja anda adalah : " << strukBelanja[indexPelanggan].totalBelanja << endl;
}

void strukPembayaran(){
    int id;
    bool hasil;
    int index;
    cout << "Masukkan ID : ";
    cin >> id;
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        hasil = strukBelanja[i].idPelanggan == id;
        index = i;
    }

    if(hasil){
        cout << strukBelanja[index].idPelanggan << endl;
        for(int i = 0; i < MAX_BARANG; i++){
            if(strukBelanja[index].barang[index].nama != ""){
                cout << strukBelanja[index].barang[i].nama << endl;
                cout << strukBelanja[index].barang[i].harga << endl;
                cout << strukBelanja[index].barang[i].jumlahBarang << endl;
            }
        }
    }
    else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void saveStrukInFile(){
    string namaFile;
    ofstream myFile;
    cout << "Masukkan nama file : ";
    cin >> namaFile;
    myFile.open(namaFile, ios::app);
    
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        if(strukBelanja[i].idPelanggan != 0){
            cout << strukBelanja[i].idPelanggan << endl;
            for(int j = 0; j < MAX_BARANG; j++){
                if(strukBelanja[i].barang[j].nama != ""){
                    myFile << strukBelanja[i].barang[j].nama << endl;
                    myFile << strukBelanja[i].barang[j].harga << endl;
                    myFile << strukBelanja[i].barang[j].jumlahBarang << endl << endl;
                }
            }
        }
    }
    
    myFile.close();
    cout << "Berhasil di simpan ke file " << namaFile << endl;
}

int main(){

    int pilihan;
    bool berhenti = false;
    databaseInit();

    do {
        displayMenu(&pilihan);
        cin.ignore();
        switch(pilihan){
            case 1:
                system("cls");
                displayAll();
                break;
            case 2:
                inputStock();
                break;
            case 3:
                searchStock();
                break;
            case 4:
                payment();
                break;
            case 5:
                strukPembayaran();
                break;
            case 6:
                saveStrukInFile();
                break;
            case 7:
                berhenti = true;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while(!berhenti);
    
    return 0;
}