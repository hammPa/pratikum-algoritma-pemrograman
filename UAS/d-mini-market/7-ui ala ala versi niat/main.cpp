/*
    nama: M.ilham
    nim: 23343008
    program kasir dengan bahasa c++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_BARANG 5
#define MAX_JENIS_BARANG 10
#define MAX_PEMBELI 10

int indexJenisBarang = 0; // jumlahJenisBarangSekarang
int indexPelanggan = 0; // jumlahPelanggansSekarang
int id = 1;


string namaJenisBarang[MAX_JENIS_BARANG] = {
    "Sabun", "Minuman", "Makanan Ringan", "Minuman Bubuk", "Shampo Botol",
    "", "", "", "", ""
};

string namaBarang[MAX_JENIS_BARANG][MAX_BARANG] = {
    {"Lux", "Lifebuoy", "Shinzui", "Dove", "Biore"},
    {"Sprite Mini", "Sprite", "Fanta", "Teh Pucuk", "Fanta Mini"},
    {"Malkist Keju", "Chitato", "Roma Kelapa", "Wafello Coklat", "Beng-Beng"},
    {"Creamy Latte", "Milo", "Torabiko Cappucino", "Dancow", "Beng-Beng Bubuk"},
    {"Clear Botol", "Dove Botol", "Pantene Botol", "Sunsilk Botol", "Lifebuoy Botol"},
    {},{},{},{},{}
};

float hargaBarang[MAX_JENIS_BARANG][MAX_BARANG] = {
    {4000, 5000, 4500, 5500, 6000},
    {3500, 5500, 5500, 3500, 3500},
    {7000, 3000, 10000, 5500, 2000},
    {2000, 2500, 2500, 2500, 2000},
    {14000, 14500, 15500, 12600, 11500},
    {},{},{},{},{}
};

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
    float hargaPesanan[MAX_BARANG];
    float hargaTotal[MAX_BARANG];
    float totalBelanja;
} Pelanggan;

JenisBarang jenisBarang[MAX_JENIS_BARANG];    
Pelanggan pelanggan[MAX_PEMBELI];

void databaseInit(){
    // index jenis barang 0
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        jenisBarang[i].namaJenisBarang = namaJenisBarang[i]; 
        for(int j = 0; j < MAX_BARANG; j++){
            jenisBarang[i].barang[j].nama = namaBarang[i][j]; // jenisBarang
            jenisBarang[i].barang[j].harga = hargaBarang[i][j];
            jenisBarang[i].barang[j].jumlahBarang = 10;
        }
        if(jenisBarang[i].namaJenisBarang != "") { // jika nama jenis barang bukan kosong, index++
            indexJenisBarang++;
        }
    }
}

void displayAll(){
    string space = " ";
    string indentAngka = "";
    bool kosong;
    int nomor = 1;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "| No | Jenis Barang    | Nama                | Harga  | JumlahBarang |" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        kosong = jenisBarang[i].namaJenisBarang.empty() || jenisBarang[i].namaJenisBarang == "";
        if(kosong) break; // jika namaJenisBarang kosong, looping selesai
        
            
        for(int j = 0; j < MAX_BARANG; j++){ // jika tidak kosong
            kosong = jenisBarang[i].barang[j].nama == "" || jenisBarang[i].barang[j].nama.empty();
            if(kosong) break; // jika tidak ada nama barang, looping selesai
            
            // indentasi start
            (nomor<10 ? indentAngka = space : indentAngka = ""); // spasi angka
            
            int panjangJenisBarang = jenisBarang[i].namaJenisBarang.length();
            string indentJenisBarang = "";
            if(panjangJenisBarang<15) {
                int spasi = 15 - panjangJenisBarang;
                for(int i = 0; i < spasi; i++) indentJenisBarang += " ";
            }
            
            int panjangNamaBarang = jenisBarang[i].barang[j].nama.length();
            string indentNamaBarang = "";
            if(panjangNamaBarang<19) {
                int spasi = 19 - panjangNamaBarang;
                for(int i = 0; i < spasi; i++) indentNamaBarang += " ";
            }
            
            string stringHargaBarang = to_string((int)jenisBarang[i].barang[j].harga); 
            int panjangHargaBarang = stringHargaBarang.length();
            string indentHargaBarang = "";
            if(panjangHargaBarang<6) {
                int spasi = 6 - panjangHargaBarang;
                for(int i = 0; i < spasi; i++) indentHargaBarang += " ";
            }
            // indentasi end

            cout << "| " << nomor << indentAngka << " | " << jenisBarang[i].namaJenisBarang << indentJenisBarang;
            cout << " | " << jenisBarang[i].barang[j].nama << indentNamaBarang;
            cout << " | " << jenisBarang[i].barang[j].harga << indentHargaBarang;
            cout << " |      " << jenisBarang[i].barang[j].jumlahBarang << "      |" << endl;
            nomor++;
        }
    }
    cout << "----------------------------------------------------------------------" << endl;
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
    if(indexJenisBarang < MAX_JENIS_BARANG){
        JenisBarang temp;
        int index = 0;
        char ulang;

        cout << "Masukkan jenis barang : ";
        getline(cin, temp.namaJenisBarang);
        do {
            // input
            cout << "Masukkan nama barang ke-" << index+1 << " : ";
            getline(cin, temp.barang[index].nama);
            cout << "Masukkan harga barang ke-" << index+1 << " : ";
            cin >> temp.barang[index].harga;
            cout << "Masukkan jumlah barang ke-" << index+1 << " : ";
            cin >> temp.barang[index].jumlahBarang;
            index++;

            cout << "Tambah barang lain ?(Tidak boleh barang yang sama) y/n : ";
            cin >> ulang;
            cin.ignore();
        } while( (ulang == 'Y' || ulang =='y') && index < MAX_BARANG);
        if(index == MAX_BARANG) cout << "Sudah Penuh" << endl;

        // setelah ditambahkan ke jenisBarang, index++
        jenisBarang[indexJenisBarang] = temp;
        indexJenisBarang++;
        cout << "Menambah barang berhasil!!" << endl; 
    }
    else {
        cout << "Penyimpanan Barang Penuh" << endl;
    }
    cin.get();
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

void addStock(){
    int namaJenisBarang, namaBarang, jumlahBarang;
    int i, j;
    
    // setelah init, indexJenisBarang 5, menampilkan jenis barang
    cout << "Jenis barang tersedia : " << endl;
    for(i = 0; i < indexJenisBarang; i++) cout << i+1 << "." << jenisBarang[i].namaJenisBarang << endl;
    
    cout << "\nMasukkan angka jenis barang yang ingin di tambah : "; // input jenisBarang
    cin >> namaJenisBarang;
    
    system("cls");
    cout << "Barang yang tersedia : " << endl; // tampilkan barang
    for(j = 0; j < MAX_BARANG; j++) cout << j+1 << "." << jenisBarang[namaJenisBarang-1].barang[j].nama << endl;

    cout << "\nMasukkan angka barang yang akan ditambah : "; // input barang
    cin >> namaBarang;

    cout << "Masukkan jumlah barang baru yang akan ditambah : "; // input jumlahBarang
    cin >> jumlahBarang;

    // pakai -1 karena input dimulai dari 1
    jenisBarang[namaJenisBarang-1].barang[namaBarang-1].jumlahBarang += jumlahBarang;
    cout << "Berhasil di tambah!!" << endl;
}

void inputStock(){
    int pilih;
    cout << "1. Jenis barang baru" << endl;
    cout << "2. Jenis barang yang sudah ada" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilih;
    cin.ignore();
    if(pilih==1) addNewStock();
    else addStock();
}


void payment(){
    string namaInput[5];
    int jumlahInput[5];
    int indexWhile = 0;
    char tambah;
    pelanggan[indexPelanggan].totalBelanja = 0; // awalnya nol

    do {
        cout << "Masukkan nama barang ke-" << indexWhile + 1 << " : ";
        getline(cin, namaInput[indexWhile]);
        cout << "Masukkan jumlah barang ke-" << indexWhile + 1 << " : ";
        cin >> jumlahInput[indexWhile];

        for(int i = 0; i < indexJenisBarang; i++){ // cari
            for(int j = 0; j < MAX_BARANG; j++){
                // jika ketemu namanya sama
                if(jenisBarang[i].barang[j].nama == namaInput[indexWhile]){
                    // masukkan dari database ke pelanggan
                    pelanggan[indexPelanggan].idPelanggan = id;
                    pelanggan[indexPelanggan].namaPesanan[indexWhile] = namaInput[indexWhile];
                    pelanggan[indexPelanggan].jumlahPesanan[indexWhile] = jumlahInput[indexWhile];
                    pelanggan[indexPelanggan].hargaPesanan[indexWhile] = jenisBarang[i].barang[j].harga;
                    pelanggan[indexPelanggan].hargaTotal[indexWhile] = (jumlahInput[indexWhile] * jenisBarang[i].barang[j].harga);
                    
                    cout << "ID : " << pelanggan[indexPelanggan].idPelanggan << endl;
                    cout << "Nama Pesanan : " << pelanggan[indexPelanggan].namaPesanan[indexWhile] << endl;
                    cout << "Jumlah Barang : " << pelanggan[indexPelanggan].jumlahPesanan[indexWhile] << endl;
                    cout << "Harga Pesanan : Rp." << pelanggan[indexPelanggan].hargaPesanan[indexWhile] << endl;
                    cout << "Harga Total : Rp." << pelanggan[indexPelanggan].hargaTotal[indexWhile] << endl;
                    break;
                }
            }
        }
        indexWhile++;
        cout << "Tambah barang ? y/n : ";
        cin >> tambah;
        cin.ignore();
    } while(tambah != 'N' && tambah != 'n' && indexWhile < MAX_BARANG);
    
    // total belanja adalah jumlah seluruh harga total per pesanan
    for(int i = 0; i < indexWhile; i++) {
        pelanggan[indexPelanggan].totalBelanja += pelanggan[indexPelanggan].hargaTotal[i];
    }
    cout << "Total Belanja anda adalah : " << pelanggan[indexPelanggan].totalBelanja << endl;
    indexPelanggan++; // tambah index setelah semuanya selesai
    id++;
}



void strukPembayaran(){
    int id;
    bool ditemukan;
    cout << "Masukkan ID : ";
    cin >> id;
    for(int i = 0; i < indexJenisBarang; i++){
        // dicari apakah pelanggan ke i , id nya sama dengan id yg dimasukkan
        ditemukan = pelanggan[i].idPelanggan == id; 
        if(ditemukan){ // jika ditemukan, tampilkan
            cout << "ID : " << pelanggan[i].idPelanggan << endl;
            for(int j = 0; j < MAX_BARANG; j++){
                if(pelanggan[i].hargaPesanan[j] != 0){
                    cout << "Nama pesanan ke-" << i+1 << " : " << pelanggan[i].namaPesanan[j] << endl;
                    cout << "Jumlah pesanan ke-" << i+1 << " : " << pelanggan[i].jumlahPesanan[j] << endl;
                    cout << "Harga pesanan ke-" << i+1 << " : " << pelanggan[i].hargaPesanan[j] << endl << endl;
                }
            }
            cout << "Total Belanja pesanan ke-" << i+1 << " : " << pelanggan[i].totalBelanja << endl << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan" << endl;
}

void saveStrukInFile(){
    string namaFile;
    ofstream myFile;
    cout << "Masukkan nama file : ";
    getline(cin, namaFile);
    myFile.open(namaFile, ios::app);
    
    for(int i = 0; i < indexJenisBarang; i++){ // cari per index
        if(pelanggan[i].idPelanggan != 0){ // jika nilai pada index bukan 0, tampilkan
            myFile << "ID : " << pelanggan[i].idPelanggan << endl;
            for(int j = 0; j < MAX_BARANG; j++){
                if(pelanggan[i].hargaPesanan[j] != 0){
                    myFile << "Nama pesanan ke-" << i+1 << " : " << pelanggan[i].namaPesanan[j] << endl;
                    myFile << "Jumlah pesanan ke-" << i+1 << " : " << pelanggan[i].jumlahPesanan[j] << endl;
                    myFile << "Harga pesanan ke-" << i+1 << " : " << pelanggan[i].hargaPesanan[j] << endl << endl;
                }
            }
            myFile << "Total Belanja pesanan ke-" << i+1 << " : " << pelanggan[i].totalBelanja << endl << endl;
        }
    }
    cout << "Berhasil di simpan ke file " << namaFile << endl;
    myFile.close();
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