/*
    Created By hammPa
    0. UI ala ala : done
    1. startgame : done
    2. isGameOver : done
    3. move : done
    4. playerPos : done
    5. automation swapPos per second : belum
    6. score : done
    7. food : done
    8. grow : done
    9. border : done
    10. skor : done 
*/

#include <iostream>
#include <conio.h>

using namespace std;

const int baris = 30;
const int kolom = 50;
const int MAX_PLAYER = 5;
int jumlahPlayer = 0;

typedef struct {
    string name;
    int score;
} Ranking;

typedef struct {
    int posY, posX, score = 0; // baris kolom score
    bool isGameOver = false;
} Player;

typedef struct {
    int posY = 4, posX = 4;
} Food;

typedef struct {
    char background[baris][kolom];
} Map;

typedef struct {
    Player player;
    Map map;
} Game;

Food generateFoodPos();
void makeBackground(Game *);
void renderPlayerAndGrow(Game *, const char key);
void renderMap(Game *, Food *, const char key);
void move(Game *, const char key);
bool checkIsGameOver(Game *);
void isPlayerPosEqualToFoodPos(Game *, Food *);
void addScoreToRanking(Ranking *, string playerName, Game *);
void displayRanking(Ranking ranking[]);
void menu(char *, string *);
void gameOver(Game *, Ranking *, string playerName, char *);
void gameStart(Game *, Food *, Ranking *, string playerName, char start);
string inputName();

int main(){
 
    Game *game = nullptr;
    Food *food = nullptr;
    Ranking *ranking = new Ranking[MAX_PLAYER];
    char start;
    string nameInputed;
    
    do{
        menu(&start, &nameInputed);
        gameStart(game, food, ranking, nameInputed, start);
    } while(start == 'y' || start == 'Y');

    return 0;
}


Food generateFoodPos(){
    Food food;
    food.posY = 10 + rand() % (baris-15);
    food.posX = 20 + rand() % (kolom-30);
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
    game->map.background[game->player.posY][game->player.posX] = 'o';
    for(int i = 1; i <= game->player.score; i++){
        // menambahkan node istilahnya
        if(key == 'w' || key == 'W') {
            game->map.background[game->player.posY + i][game->player.posX] = 'O';
            game->map.background[game->player.posY][game->player.posX] = '^';
        }
        if(key == 'a' || key == 'A') {
            game->map.background[game->player.posY][game->player.posX + i] = 'O';
            game->map.background[game->player.posY][game->player.posX] = '<';
        }
        if(key == 's' || key == 'S') {
            game->map.background[game->player.posY - i][game->player.posX] = 'O';
            game->map.background[game->player.posY][game->player.posX] = 'v';
        }
        if(key == 'd' || key == 'D') {
            game->map.background[game->player.posY][game->player.posX - i] = 'O';
            game->map.background[game->player.posY][game->player.posX] = '>';
        }
    }
}

void renderMap(Game *game, Food *food, const char key){
    cout << "\tScore : " << game->player.score << endl;
    makeBackground(game);
    renderPlayerAndGrow(game, key);

    if(game->player.score % 5 == 0 && game->player.score != 0){
        game->map.background[food->posY][food->posX] = 'O';
    }
    else {
        game->map.background[food->posY][food->posX] = '*';
    }
    
    // render
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << game->map.background[i][j];
        }
        cout << endl;
    }
}

void move(Game *game, const char key){
    if(key == 'w' || key == 'W') game->player.posY--;
    if(key == 'a' || key == 'A') game->player.posX--;
    if(key == 's' || key == 'S') game->player.posY++;
    if(key == 'd' || key == 'D') game->player.posX++;
}

bool checkIsGameOver(Game *game){
    if(game->player.posY == 0 || game->player.posY == baris-1) return true;
    else if(game->player.posX == 0 || game->player.posX == kolom-1) return true;
    else return false;
}

void isPlayerPosEqualToFoodPos(Game *game, Food *food){
    if(game->player.posY == food->posY && game->player.posX == food->posX){
        if(game->player.score % 5 == 0 && game->player.score != 0) game->player.score += 3;
        else game->player.score++;
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
    cin.get();
}

string inputName(){
    string playerName;
    ++jumlahPlayer;
    cout << "Masukkan nama player : ";
    getline(cin, playerName);
    return playerName;
}

void menu(char *start, string *nameInputed){
    cout << "Selamat Datang Di Program Snake Ala Ala Terminal" << endl;
    cout << "\t\tStart ? (y/n) : ";
    cin >> *start;
    cin.ignore();
    if(*start != 'y' && *start !='Y') exit(0);
    else *nameInputed = inputName();
}

void gameOver(Game *game, Ranking *ranking, string playerName, char *start){
    cout << "\t\tGame Over" << endl;
    cout << "\t\tYour Score is " << game->player.score << endl;
    addScoreToRanking(ranking, playerName, game);
    cout << "1. Tampilkan Ranking" << endl;
    cout << "2. Keluar" << endl;
    int pil;
    cout << "Masukkan Pilihan : ";
    cin >> pil;
    if(pil == 1) {
        displayRanking(ranking);
        return;
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
    game->player.posY = 5;
    game->player.posX = 5;
    system("cls");
    cout << "Selamat Bermain " << playerName << " !! :D" << endl;
    do {
        renderMap(game, food, key);
        key = getch();
        move(game, key);
        isPlayerPosEqualToFoodPos(game, food);
        cout << "\x1B[2J\x1B[H";
        isOver = checkIsGameOver(game);
    } while(!isOver);
    gameOver(game, ranking, playerName, &start);
    delete(food);
    delete(game);
}