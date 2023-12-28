#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_BARANG 5
#define MAX_JENIS_BARANG 10
#define MAX_PEMBELI 10

int indexBarangPelanggan = 0;
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
    string namaPesanan[MAX_BARANG];
    int jumlahPesanan[MAX_BARANG];
    int hargaPesanan[MAX_BARANG];
    float totalBelanja;
} Pelanggan;

JenisBarang jenisBarang[MAX_JENIS_BARANG];    
Pelanggan pelanggan[MAX_PEMBELI];


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
            jenisBarang[i].barang[j].nama = namaBarang[i][j]; // jenisBarang
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
    getline(cin, temp.namaJenisBarang);
    do {
        cout << "Masukkan nama barang : ";
        getline(cin, temp.barang[index].nama);
        cout << "Masukkan harga barang : ";
        cin >> temp.barang[index].harga;
        cout << "Masukkan jumlah barang : ";
        cin >> temp.barang[index].jumlahBarang;
        index++;
        cout << "Tambah barang lain ?(Tidak boleh barang yang sama) y/n : ";
        cin >> ulang;
        cin.ignore();
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
    cin.ignore();
    if(pilih==1) addNewStock();
    else addStock();
}

void searchStock(){
    string nama;
    cout << "Masukkan nama barang yang ingin di cari : ";
    getline(cin, nama);
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        for(int j = 0; j < MAX_BARANG; j++){
            if(jenisBarang[i].barang[j].nama == nama){
                cout << "Barang ditemukan, berikut detailnya : " << endl;
                cout << "Nama barang : " << jenisBarang[i].barang[j].nama << endl;
                cout << "Harga barang :" << jenisBarang[i].barang[j].harga << endl;
                cout << "Stok tersedia : " << jenisBarang[i].barang[j].jumlahBarang << endl;
                return;
            }
        }
    }
    cout << nama << " tidak ditemukan" << endl; // jika tidak ditemukan

}

void payment(){
    string namaInput[5];
    int jumlahInput[5];
    int indexWhile = 0;
    char tambah;
    pelanggan[indexPelanggan].totalBelanja = 0;

    do {
        cout << "Masukkan nama barang ke-" << indexWhile + 1 << " : ";
        getline(cin, namaInput[indexWhile]);
        cout << "Masukkan jumlah barang ke-" << indexWhile + 1 << " : ";
        cin >> jumlahInput[indexWhile];
        for(int i = 0; i < MAX_JENIS_BARANG; i++){
            for(int j = 0; j < MAX_BARANG; j++){
                if(jenisBarang[i].barang[j].nama == namaInput[indexWhile]){
                    pelanggan[indexPelanggan].hargaPesanan[indexWhile] = jenisBarang[i].barang[j].harga;
                    cout << "Harga : " << pelanggan[indexPelanggan].hargaPesanan[indexWhile] << endl;

                    pelanggan[indexPelanggan].idPelanggan = id;
                    pelanggan[indexPelanggan].namaPesanan[indexWhile] = namaInput[indexWhile];
                    pelanggan[indexPelanggan].jumlahPesanan[indexWhile] = jumlahInput[indexWhile];
                    cout << "Jumlah : " << pelanggan[indexPelanggan].jumlahPesanan[indexWhile] << endl;
                    
                    pelanggan[indexPelanggan].totalBelanja += (jumlahInput[indexWhile] * pelanggan[indexPelanggan].hargaPesanan[indexWhile]);
                    cout << "Total : " << pelanggan[indexPelanggan].totalBelanja << endl;
                    indexPelanggan++; // tambah index
                }
            }
        }
        indexWhile++;
        cout << "Tambah barang ? y/n : ";
        cin >> tambah;
        cin.ignore();
    } while(tambah != 'N' && tambah != 'n' && indexWhile < 5);
    // karena tadi sudah ++ si indexPelanggan
    cout << "Total Belanja anda adalah : " << pelanggan[indexPelanggan - 1].totalBelanja << endl;
}

void strukPembayaran(){
    // int id;
    // bool hasil;
    // int index;
    // cout << "Masukkan ID : ";
    // cin >> id;
    // for(int i = 0; i < MAX_JENIS_BARANG; i++){
    //     hasil = pelanggan[i].idPelanggan == id;
    //     index = i;
    // }

    // if(hasil){
    //     cout << pelanggan[index].idPelanggan << endl;
    //     for(int i = 0; i < MAX_BARANG; i++){
    //         if(pelanggan[index].barang[index].nama != ""){
    //             cout << pelanggan[index].barang[i].nama << endl;
    //             cout << pelanggan[index].barang[i].harga << endl;
    //             cout << pelanggan[index].barang[i].jumlahBarang << endl;
    //         }
    //     }
    // }
    // else {
    //     cout << "Data tidak ditemukan" << endl;
    // }
}

void saveStrukInFile(){
    // string namaFile;
    // ofstream myFile;
    // cout << "Masukkan nama file : ";
    // getline(cin, namaFile);
    // myFile.open(namaFile, ios::app);
    
    // for(int i = 0; i < MAX_JENIS_BARANG; i++){
    //     if(pelanggan[i].idPelanggan != 0){
    //         cout << pelanggan[i].idPelanggan << endl;
    //         for(int j = 0; j < MAX_BARANG; j++){
    //             if(pelanggan[i].barang[j].nama != ""){
    //                 myFile << pelanggan[i].barang[j].nama << endl;
    //                 myFile << pelanggan[i].barang[j].harga << endl;
    //                 myFile << pelanggan[i].barang[j].jumlahBarang << endl << endl;
    //             }
    //         }
    //     }
    // }
    
    // myFile.close();
    // cout << "Berhasil di simpan ke file " << namaFile << endl;
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
                system("cls");
                inputStock();
                break;
            case 3:
                system("cls");
                searchStock();
                cout << "Klik apa saja untuk kembali" << endl;
                cin.get();
                break;
            case 4:
                system("cls");
                payment();
                break;
            case 5:
                system("cls");
                strukPembayaran();
                break;
            case 6:
                system("cls");
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