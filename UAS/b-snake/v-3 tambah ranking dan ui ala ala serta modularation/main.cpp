/*
    0. UI ala ala : proccess
    1. startgame : done
    2. isGameOver : done
    3. move : done
    4. playerPos : done
    5. automation swapPos per second : belum
    6. score : done
    7. food : done
    8. grow : done
    9. border : done
    10. skor : proccess 
*/

#include <iostream>
#include <conio.h>
using namespace std;

const int baris = 12;
const int kolom = 24;
const int MAX_PLAYER = 5;
int jumlahPlayer = 0;

typedef struct {
    string name;
    int score;
} Ranking;

typedef struct {
    int posX; // baris
    int posY; // kolom
    int score = 0;
    bool isGameOver = false;
} Player;

typedef struct {
    int posX = 4;
    int posY = 4;
} Food;

typedef struct {
    char background[baris][kolom];
} Map;

typedef struct {
    Player player;
    Map map;
} Game;

Food generateFoodPos(){
    Food food;
    food.posX = 1 + rand() % (baris-1);
    food.posY = 1 + rand() % (kolom-1);
    return food; 
}

void makeBackground(Game *game){
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            if(i == 0 || i == baris-1){
                game->map.background[i][j] = '-';
            }
            else if(j == 0 || j == kolom-1){
                game->map.background[i][j] = '|';
            }
            else {
                game->map.background[i][j] = ' ';
            }
        }
    }
}

void renderPlayerAndGrow(Game *game, const char key){
    game->map.background[game->player.posX][game->player.posY] = 'H';
    for(int i = 1; i <= game->player.score; i++){
        // menambahkan node istilahnya
        if(key == 'w' || key == 'W') {
            game->map.background[game->player.posX + i][game->player.posY] = '*';
        }
        if(key == 'a' || key == 'A') {
            game->map.background[game->player.posX][game->player.posY + i] = '*';
        }
        if(key == 's' || key == 'S') {
            game->map.background[game->player.posX - i][game->player.posY] = '*';
        }
        if(key == 'd' || key == 'D') {
            game->map.background[game->player.posX][game->player.posY - i] = '*';
        }
    }
}

void renderMap(Game *game, Food *food, const char key){
    cout << "\tScore : " << game->player.score << endl;
    makeBackground(game);
    renderPlayerAndGrow(game, key);

    game->map.background[food->posX][food->posY] = '*';
    
    // render
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << game->map.background[i][j];
        }
        cout << endl;
    }
}

void move(Game *game, const char key){
    if(key == 'w' || key == 'W') game->player.posX--;
    if(key == 'a' || key == 'A') game->player.posY--;
    if(key == 's' || key == 'S') game->player.posX++;
    if(key == 'd' || key == 'D') game->player.posY++;
}

bool checkIsGameOver(Game *game){
    if(game->player.posX == 0 || game->player.posX == baris-1) return true;
    else if(game->player.posY == 0 || game->player.posY == kolom-1) return true;
    else return false;
}

void isPlayerPosEqualToFoodPos(Game *game, Food *food){
    if(game->player.posX == food->posX && game->player.posY == food->posY){
        game->player.score++;
        *food = generateFoodPos();
    }
}

void addScoreToRanking(Ranking *ranking, string playerName, Game *game){
    ranking[jumlahPlayer-1].name = playerName;
    ranking[jumlahPlayer-1].score = game->player.score;
}

void displayRanking(Ranking ranking[]){
    for(int i = 0; i < jumlahPlayer; i++){
        cout << "Nama  : " << ranking[i].name << endl;
        cout << "Score : " << ranking[i].score << endl;
    }
}

void menu(char *start){
    cout << "Selamat Datang Di Program Snake Ala Ala Terminal" << endl;
    cout << "\t\tStart ? (y/n) : ";
    cin >> *start;
}

void gameOver(Game *game, Ranking *ranking, string playerName, char *start){
    cout << "\t\tGame Over" << endl;
    cout << "\t\tYour Score is " << game->player.score << endl;
    addScoreToRanking(ranking, playerName, game);
    cout << "1. Tampilkan Ranking dan ulangi" << endl;
    cout << "2. Keluar" << endl;;
    int pil;
    cout << "Masukkan Pilihan : ";
    cin >> pil;
    if(pil == 1) {
        displayRanking(ranking);
        cin.get();
        menu(start);
    }
    else {
        cout << "Terima Kasih!!" << endl;
        cout << "\t\tBerhasil Keluar Program!" << endl;
        exit(0);
    }
}

void gameStart(Game *game, Food *food, Ranking *ranking, string playerName, char start){
    char key;
    bool isOver = false;
    game = new Game();
    food = new Food();
    game->player.posX = 5;
    game->player.posY = 5;
    system("cls");
    cout << "Selamat Bermain!! :D" << endl;
    do {
        renderMap(game, food, key);
        key = getch();
        move(game, key);
        isPlayerPosEqualToFoodPos(game, food);
        cout << "\x1B[2J\x1B[H";
        isOver = checkIsGameOver(game);
    } while(!isOver);
    delete(food);
    delete(game);
    gameOver(game, ranking, playerName, &start);
}

string inputName(){
    string playerName;
    ++jumlahPlayer;
    cout << "Masukkan nama player : ";
    getline(cin, playerName);
    return playerName;
}

int main(){
 
    Game *game = nullptr;
    Food *food = nullptr;
    Ranking *ranking = new Ranking[MAX_PLAYER];
    char start;
    
    menu(&start);
    cin.ignore();
    string nameFromInput = inputName();
    while(start == 'y' || start == 'Y'){
        gameStart(game, food, ranking, nameFromInput, start);
    }

    return 0;
}