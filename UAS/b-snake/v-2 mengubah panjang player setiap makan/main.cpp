/*
    1. startgame : done
    2. isGameOver : done
    3. move : done
    4. playerPos : done
    5. automation swapPos per second
    6. score : done
    7. food : done
    8. grow : done
    9. border : done
    10. pakai linkedlist
*/

#include <iostream>
#include <conio.h>
using namespace std;

const int baris = 12;
const int kolom = 24;

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

int main(){

    Game *game = new Game();
    Food *food = new Food();
    char key;
    game->player.posX = 5;
    game->player.posY = 5;
    bool isOver = false;

    do {
        renderMap(game, food, key);
        key = getch();
        move(game, key);
        isPlayerPosEqualToFoodPos(game, food);
        system("cls");
        isOver = checkIsGameOver(game);
    } while(!isOver);

    cout << "Game Over" << endl;
    cout << "Your Score is " << game->player.score << endl;

    delete(game);
    return 0;
}