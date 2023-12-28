#include <iostream>
using namespace std;

bool contoh(){
    cout << "Ini voidnya" << endl;
    return true;
}

int main(){

    contoh();
    int a = contoh();
    cout << a << endl;

    return 0;
}