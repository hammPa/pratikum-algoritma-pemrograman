#include <iostream>
#include <string.h>

using namespace std;

int main(){

    // Tahun habis dibagi 4 dan tidak habis dibagi 100.
    // Tahun habis dibagi 400.
    int tahun;
    string hasil;
    cout << "Selamat datang di program tahun kabisat" << endl;
    cout << "Masukkan tahun lahir anda : ";
    cin >> tahun;


    
    if((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)){
        hasil.append(" Tahun kabisat");
    } 
    else {
        hasil.append(" Bukan tahun kabisat");
    }
    cout << tahun << hasil << endl;

    return 0;
}