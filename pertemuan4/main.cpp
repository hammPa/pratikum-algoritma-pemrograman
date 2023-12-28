#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    // deklarasi dan inisialisasi
    string myName = "hammPa", herName = "aisqy";
    
    // deklarasi
    int myAge, herAge;
    
    // assignment
    myAge = 19;
    herAge = 18;

    // display
    cout << "My name is " << myName << " and i'm " << myAge << endl;
    cout << "Her name is " << herName << " and her is " << herAge << endl;



    // aritmatika

    // + -
    cout << "1 + 2 : " << 1 + 2 << endl;
    cout << "3 - 1 : " << 3 - 1 << endl;

    // * /
    cout << "5 x 5 : " << 5 * 5 << endl;
    cout << "10 / 5 : " << 10 / 5 << endl;

    // pow sqrt
    cout << "3 pangkat 4 : " << pow(3, 4) << endl;
    cout << "akar 25 : " << sqrt(25) << endl;

    // percent
    cout << 500 << " adalah " << (1.0/2.0) * 100 << "% dari 1000" << endl;

    return 0;
}
