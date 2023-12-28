#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int baris = 20;
const int kolom = 40;

typedef struct {
    char background[baris][kolom];
} Map; 

struct Player {
    char img;
    int posX;
    int posY;
    struct Player *next;
};

typedef struct {
    char img;
    int posX;
    int posY;
} Food;

int score = 0;
Map map;
Food *food = new Food(); 
Player *head, *tail, *newNode, *current;



void createPlayer(){
    head = new Player();

    head->img = '*';
    head->posX = 5;
    head->posY = 5;
    head->next = tail;
    tail = head;
}


void addTail(){
    newNode = new Player();

    newNode->next = nullptr;    
    newNode->img = '*';
    newNode->posX = head->posX - 1;
    newNode->posY = head->posY;

    tail->next = newNode;
    tail = newNode;
}

void move(const char key){
    int posPrevX = head->posX; // posisi kepala awal
    int posPrevY = head->posY;
    switch(key){
        case 'a':
        case 'A':
        case 75:
            head->posX--;  // posisi kepala di update
            head->img = '<';
            break;
        case 's':
        case 'S':
        case 80:
            head->posY++;
            head->img = 'v';
            break;
        case 'w':
        case 'W':
        case 72:
            head->posY--;
            head->img = '^';
            break;
        case 'd':
        case 'D':
        case 77:
            head->posX++;
            head->img = '>';
            break;
    }

    current = head->next; // memperbarui selain kepala
    while(current != nullptr){
        int tempX = current->posX; // posisi badan sekarang disimpan
        int tempY = current->posY;

        current->posX = posPrevX; // posisi badan sekarang adalah posisi kepala sebelumnya
        current->posY = posPrevY;

        posPrevX = tempX; // posisi badan sebelumnya disimpan menjadi posisi kepala sekarang
        posPrevY = tempY;

        current = current->next; // lanjut ke node selanjutnya
    }
}
    
Food createNewFood(){
    Food food;
    food.posX = 1 + rand() % (kolom - 2);
    food.posY = 1 + rand() % (baris - 2);
    food.img = 'o';
    return food;
}

void createFood(){
    food->posX = 10;
    food->posY = 10;
    food->img = score != 0 && score % 2 == 0 ? 'O' : 'o';
}

void renderFood(){
    map.background[food->posY][food->posX] = food->img;
}

void isPlayerPosEqualToFood(){
    if(head->posX == food->posX && head->posY == food->posY){
        addTail();
        if(score!=0 && score % 10 == 0) score+=3;
        score++;
        *food = createNewFood();
    }
}

void renderPlayer(){
    current = head;
    while(current != nullptr){
        map.background[current->posY][current->posX] = current->img;
        current = current->next;
    }
}

bool checkIsGameOver(){
    if(head->posX == 0 || head->posX == kolom-1) return true;
    if(head->posY == 0 || head->posY == baris-1) return true;
    return false;
}

void createMap(){
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            if(i == 0 || i == baris - 1) map.background[i][j] = '-';
            else if(j == 0 || j == kolom - 1) map.background[i][j] = '|';
            else map.background[i][j] = ' ';
        }
    }
}

void renderMap(){
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << map.background[i][j];
        }
        cout << endl;
    }
}

void menu(){
    char start;
    cout << "==================================================================================" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                          Welcome to my first project                           |" << endl;
    cout << "|                        This game is created by M.ilham                         |" << endl;
    cout << "|                    Don't forgot to follow my github: hammPa                    |" << endl;
    cout << "| This game is created to fulfill my last exam on subject Programming Algorithm  |" << endl;
    cout << "|                                Enjoyy!! :D                                     |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "==================================================================================" << endl;
    cout << "\n Start ? (y/n) : ";
    cin >> start;
    if(start != 'y' && start != 'Y'){
        cout << "Thanks for playing this game" << endl;
        exit(0);
    }
    else system("cls");
}

int main(){

    char key;
    bool isOver = false;
    menu();
    
    createPlayer(); // buat player(posisi)
    createFood(); // buat makanan(posisi)
    do {
        createMap(); // buat map
        system("cls");
        cout << "Score " << score << endl;
        renderFood(); // render posisi makanan
        renderPlayer(); // render posisi player
        renderMap(); // render map yang sudah di render semua hal
        key = getch(); // input
        move(key); // pindah bergerak
        isPlayerPosEqualToFood(); // cek apakah makan
        isOver = checkIsGameOver(); // cek apakah kena dinding
    } while(!isOver);
    // delete

    return 0;
}