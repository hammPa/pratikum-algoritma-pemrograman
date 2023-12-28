/*
    tugas: UAS Pratikum Algoritma Pemrograman
    programmer: hammPa
    cara kerja: menyimpan data langsung ke memory tanpa variabel tambahan dengan metode linked list
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int jumlahMahasiswa = 0;

struct Mahasiswa {
    string nama;
    string nim;
    string jurusan;
    string prodi;
    struct Mahasiswa *next;
};

struct Mahasiswa *head, *tail, *newNode, *current, *del;


// method
void menu(int *pilihan){
    cout << "1. Add new node at back\n";
    cout << "2. Add new node at front\n";
    cout << "3. Display all node\n";
    cout << "4. Display first node\n";
    cout << "5. Display last node\n";
    cout << "6. Delete last node\n";
    cout << "7. Delete first node\n";
    cout << "8. Save in file\n";
    cout << "9. exit\n";
    cout << "Mau melakukan operasi apa ? " << endl;
    cout << "Masukkan pilihan : ";
    cin >> *pilihan;
}

void initialize(struct Mahasiswa *temp){
    head = new Mahasiswa(); // dynamic allocation custom data types
    
    head->nama = temp->nama; // assignment to struct
    head->nim = temp->nim;
    head->jurusan = temp->jurusan;
    head->prodi = temp->prodi;

    head->next = tail; // next node is tail
    tail = head; // tail same as next because the jumlahMahasiswa is 1

    jumlahMahasiswa++;
}

void push_front(struct Mahasiswa *temp){
    newNode = new Mahasiswa();

    newNode->nama = temp->nama; // assignment to struct
    newNode->nim = temp->nim;
    newNode->jurusan = temp->jurusan;
    newNode->prodi = temp->prodi;

    newNode->next = head; // the next of newNode is refer to head
    head = newNode; // now, newNode is the head
}

void push_back(struct Mahasiswa *temp){
    newNode = new Mahasiswa(); 

    newNode->nama = temp->nama; // assignment to struct
    newNode->nim = temp->nim;
    newNode->jurusan = temp->jurusan;
    newNode->prodi = temp->prodi;

    newNode->next = nullptr; // newNode next is null
    tail->next = newNode; // the next of the tail is null, now next of tail is point to newNode
    tail = newNode; // now, tail is newNode
}

void saveInFile(){
    string namaFile;
    cout << "Mau nama filenya apa ? ";
    cin >> namaFile;
    
    current = head;
    ofstream myFile;
    myFile.open("./" + namaFile + ".txt", ios::app);
    
    while(current != nullptr){
        myFile << "Nama    : " << current->nama << endl;
        myFile << "NIM     : " << current->nim << endl;
        myFile << "Jurusan : " << current->jurusan << endl;
        myFile << "Prodi   : " << current->prodi << endl << endl;
        current = current->next;
    }

    myFile.close();
    cout << "Berhasil di simpan ke file hasilKeluaran.txt :D" << endl;
}

// masih tidak bisa
void remove(string condition){
    if(condition == "first"){ // del first
        del = head; // memory of del is same as head
        head = head->next; // now, next of head is the head
        delete del; // delete del
    }

    else { // del last
        del = head;
        while(del->next != nullptr){ // while next of del is not equal to null
            current = del; // current is same as del
            del=del->next;
        }
        current->next = nullptr;
        tail = current;
        delete del;
    }
    jumlahMahasiswa--;
}

// features
void add(string condition = "back"){
    system("cls");
    struct Mahasiswa *temp;
    temp = new Mahasiswa();
    cout << "Masukkan nama    : ";
    cin.ignore();
    getline(cin, temp->nama);
    cout << "Masukkan nim     : ";
    getline(cin, temp->nim);
    cout << "Masukkan jurusan : ";
    getline(cin, temp->jurusan);
    cout << "Masukkan prodi   : ";
    getline(cin, temp->prodi);
    
    if(jumlahMahasiswa==0) initialize(temp); // if empty, initialize
    else { // if not empty
        condition == "back" ? push_back(temp) : push_front(temp); // location to push is back or temp
    }

    delete(temp);
    
    cout << "Success added, click any button to continue" << endl;
    cin.get();
}

void display(string condition = "all"){ // by default, condition is all
    system("cls");
    current = head; // current is head
    while(current!=nullptr){ // while current is  null, display is over
        if(condition == "last" && current->next != nullptr) {
            current = current->next;
            continue;
        } // if last AND next of current is not null, continue(dont display)
        cout << "Nama    : " << current->nama << endl;
        cout << "NIM     : " << current->nim << endl;
        cout << "Jurusan : " << current->jurusan << endl;
        cout << "Prodi   : " << current->prodi << endl;
        cout << endl;
        if(condition == "first" || condition == "last") break; // if condition is first (also if last), break the program
        else if(condition == "all") current = current->next; // if condition to diplay is not first, continue
    }

    cout << "Click any buttonn to back to menu" << endl;
    cin.get();
}

int main(){

    int pilihan;
    bool run = true;
    do {
        menu(&pilihan);
        switch(pilihan){
        case 1:
            add(); // by default is back
            break;
        
        case 2:
            add("front");
            break;

        case 3:
            display(); // by default is all
            break;
        
        case 4:
            display("first");
            break;
        
        case 5:
            display("last");
            break;
        
        case 6:
            remove("last");
            break;
        
        case 7:
            remove("first");
            break;
        
        case 8:
            saveInFile();
            break;
        
        case 9:
            run = false;
            break;
        
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }

    } while(run);

    delete head;
    delete tail;
    delete newNode;
    delete current;
    delete del;

    return 0;
}