#include <iostream>
#include <math.h>

using namespace std;

int main(){
    

    string gameName = "Minecraft", founder = "Notch";
    string processor = "intel i3";
    int ram = 8, disk = 20;
    float percentage = (9.2)/(10.0)*100;
    char result = 'A';

    cout << gameName << " adalah game sandbox open world yang di buat oleh " << founder;
    cout << "\nUntuk memainkan game "<< gameName << " diperlukan spesifikasi komputer berikut : \n";

    cout << "1. Ram minimal " << ram << "gb, namun direkomendasikan " << ram + ram << "gb\n";
    cout << "2. Penyimpanan tersisa sebanyak" << disk << "gb, namun minimalnya " << disk - 10 << "gb\n";
    cout << "3. Processor menggunakan " << processor << " minimal gen 5\n";
    
    cout << "Menurut saya, secara keseluruhan dari gameplaynya, game ini layak mendapatkan ";
    cout << "rating " << result << " dan persentase saya merekomendasikan game ini untuk dicoba adalah ";
    cout << percentage << "%" << endl;

    return 0;
}
