#include <iostream>
using namespace std;

#define MAX_MAHASISWA 20
#define MAX_CHAR 30

int main(){
    
    int jumlah;
    char kumpulanNamaMahasiswa[MAX_MAHASISWA][MAX_CHAR];
    cout << "Selamat Datang Di Program Input Data Mahasiswa" << endl;
    cout << "Mau menginputkan berapa nama ? : ";
    cin >> jumlah;
    cin.ignore();

    for(int i = 0; i < jumlah; i++){
        cout << "Silahkan masukkan nama mahasiswa ke-" << i + 1 << " : ";
        cin.getline(kumpulanNamaMahasiswa[i], sizeof(kumpulanNamaMahasiswa[i]));
    }

    cout << endl;

    for(int i = 0; i < jumlah; i++){
        cout << "Nama mahasiswa ke-" << i + 1 << " : ";
        cout << kumpulanNamaMahasiswa[i] << endl;
    }
    
    return 0;
}
