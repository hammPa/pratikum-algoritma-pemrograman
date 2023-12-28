#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

    char ulang, jenisTiket;


    string film1 = "One Piece Movie Red"; 
    string film2 = "One Piece Movie Stampede";
    string film3 = "Kimi No Nawa";
    string film4 = "Tenki No Ko";
    string filmPilihan = ""; 

    float harga;
    float hargaTotal; 
    float hargaPerTiket; 
    float pajak;

    int pilihan;
    int jumlahTiket;

    cout << endl;
    do {
        cout << "Film tersedia : "<< endl;
        cout << "1. " << film1 << ", harga tiket : 50000" << endl;
        cout << "2. " << film2 << ", harga tiket : 45000" << endl;
        cout << "3. " << film3 << ", harga tiket : 50000" << endl; 
        cout << "4. " << film4 << ", harga tiket : 40000" << endl;

        cout << endl;
        cout << "Mau nonton film yang mana ? Silahkan masukkan nomor film : ";
        cin >> pilihan;

        if(pilihan == 1){
            filmPilihan += film1;
            hargaPerTiket = 50000;
        } 
        else if(pilihan == 2){
            filmPilihan += film2;
            hargaPerTiket = 45000;
        }
        else if(pilihan == 3){
            filmPilihan += film3;
            hargaPerTiket = 50000;
        }
        else if(pilihan == 4){
            filmPilihan += film4;
            hargaPerTiket = 40000;
        }
        else {
            cout << "Pilihan tidak tersedia\n";
        }

        cout << "Mau beli berapa tiket ? : ";
        cin >> jumlahTiket;

        cout << "Mau tiket VIP ? (tambah 10000) :";
        cin >> jenisTiket;

        int tambahan = jenisTiket ? 10000 : 0;
        harga = hargaPerTiket * jumlahTiket;
        pajak = 5/100 * harga;
        hargaTotal =  harga + pajak + jenisTiket;

        cout << endl;
        cout << "Anda membeli " << jumlahTiket << " tiket untuk menonton film " << filmPilihan;
        cout << "\nHarga yang harus anda bayar adalah Rp. " << harga << endl;

        cout << "\nApakah anda masih ingin membeli tiket ? (y/n) : ";
        cin >> ulang; 

    }while(ulang=='Y' || ulang=='y');
    cout << "Terima kasih, selamat menonton" << endl;

    return 0;
}