#include "Engine.h"
#include <string.h>

Coordinates Move(Coordinates playerCoordinates, Map& map, int size, Player player, bool p) {

    bool input = true;
    while (input) {
        if(p){
            printw("Turns Player1\n\n");
        }else{
            printw("Turns Player2\n\n");
        }
        for (int i = 0; i < player.getSteps().size(); i = i + 4) {
            printw("%i %i\n", player.getSteps()[i + 1], player.getSteps()[i]);
        }


        int a = getch();
            switch (a) {
                case 119:
                    if (playerCoordinates.x <= size && playerCoordinates.x >= 1 &&
                        map.getMap()[playerCoordinates.x - 1][playerCoordinates.y] == '.') {
                        map.Step(playerCoordinates.x, playerCoordinates.y, '.');
                        playerCoordinates.x--;
                    }
                    map.Step(playerCoordinates.x, playerCoordinates.y, 'O');
                    clear();
                    map.DrawMap();
                    break;
                case 97:
                    if (playerCoordinates.y <= size && playerCoordinates.y >= 1 &&
                        map.getMap()[playerCoordinates.x][playerCoordinates.y - 1] == '.') {
                        map.Step(playerCoordinates.x, playerCoordinates.y, '.');
                        playerCoordinates.y--;
                    }
                    map.Step(playerCoordinates.x, playerCoordinates.y, 'O');
                    clear();
                    map.DrawMap();
                    break;
                case 115:
                    if (playerCoordinates.x <= size && playerCoordinates.x >= 1 &&
                        map.getMap()[playerCoordinates.x + 1][playerCoordinates.y] == '.') {
                        map.Step(playerCoordinates.x, playerCoordinates.y, '.');
                        playerCoordinates.x++;
                    }
                    map.Step(playerCoordinates.x, playerCoordinates.y, 'O');
                    clear();
                    map.DrawMap();
                    break;
                case 100:
                    if (playerCoordinates.y <= size && playerCoordinates.y >= 1 &&
                        map.getMap()[playerCoordinates.x][playerCoordinates.y + 1] == '.') {
                        map.Step(playerCoordinates.x, playerCoordinates.y, '.');
                        playerCoordinates.y++;
                    }
                    map.Step(playerCoordinates.x, playerCoordinates.y, 'O');
                    clear();
                    map.DrawMap();
                    break;
                case 32:
                    input = false;
                    map.Step(playerCoordinates.x, playerCoordinates.y, player.getColor());
                    break;
                default:
                    clear();
                    map.DrawMap();
                    break;
            }
        }
        return playerCoordinates;
}

int main() {
    int size;
    std::cout << "Введите размер поля. (N <= 4 && N % 2 = 0)" << std::endl;
    std::cin >> size;
    if(size % 2 != 0 && size < 4){
        std::cout << "Введите правильный размер поля." << std::endl;
        std::cin >> size;
    }
    Map map(size);
    Player player1('W', size);
    Player player2('B', size);
    int amount = 0, end = 0;
    map.Step(2, 1, 'O');
    Engine engine;
    Coordinates coordinates, playerCoordinates;
    playerCoordinates.x = 2;
    playerCoordinates.y = 1;
    initscr();
    noecho();

    for (int i = 0; i < (size * size - 4) / 2; ++i) {
        end = 0;
        map.DrawMap();
        engine.PossibleMoves(player1, map, 'W');
        bool error = true;
        if(!player1.getSteps().empty()) {
            playerCoordinates = Move(playerCoordinates, map, size, player1, true);
            while (error) {
                for (int i = 0; i < player1.getSteps().size(); i = i + 2) {
                    if (playerCoordinates.x == player1.getSteps()[i + 1] &&
                        playerCoordinates.y == player1.getSteps()[i]) {
                        error = false;
                        break;
                    }
                }
                if (!error) break;
                printw("Error: %i %i\n", playerCoordinates.x, playerCoordinates.y);
                playerCoordinates = Move(playerCoordinates, map, size, player1, true);
            }
            error = true;
            amount = engine.NumberOfTurns(playerCoordinates, map, player1);
            player1.setAmount(amount);
            player2.setAmount(-amount);
            if (player1.getAmount() > player2.getAmount() && player1.getAmount() + player2.getAmount() == size * size) {
                printw("Win Player1\n");
                getch();
                break;
            }
            if (player1.getAmount() < player2.getAmount() && player1.getAmount() + player2.getAmount() == size * size) {
                printw("Win Player2\n");
                getch();
                break;
            }
            map.Step(playerCoordinates.x, playerCoordinates.y, player1.getColor());
            clear();
            player1.ClearSteps();
            printw("Input coordinates Player1: %i %i\n\n", playerCoordinates.x, playerCoordinates.y);
            playerCoordinates.x = 1;
            playerCoordinates.y = 1;
        }else{
            end++;
        }

        map.DrawMap();
        engine.PossibleMoves(player2, map);
        if(!player2.getSteps().empty()) {
            playerCoordinates = Move(playerCoordinates, map, size, player2, false);
            while (error) {
                for (int i = 0; i < player2.getSteps().size(); i = i + 2) {
                    if (playerCoordinates.x == player2.getSteps()[i + 1] &&
                        playerCoordinates.y == player2.getSteps()[i]) {
                        error = false;
                        break;
                    }
                }
                if (!error) break;
                printw("Error: %i %i\n", playerCoordinates.x, playerCoordinates.y);
                playerCoordinates = Move(playerCoordinates, map, size, player1, true);
            }
            amount = engine.NumberOfTurns(playerCoordinates, map, player2);
            player1.setAmount(amount);
            player2.setAmount(-amount);
            if (player1.getAmount() > player2.getAmount() && player1.getAmount() + player2.getAmount() == size * size) {
                printw("Win Player1\n");
                getch();
                break;
            }
            if (player1.getAmount() < player2.getAmount() && player1.getAmount() + player2.getAmount() == size * size) {
                printw("Win Player2\n");
                getch();
                break;
            }
            map.Step(playerCoordinates.x, playerCoordinates.y, player2.getColor());
            clear();
            printw("Input coordinates Player2: %i %i\n\n", playerCoordinates.x, playerCoordinates.y);
            playerCoordinates.x = 1;
            playerCoordinates.y = 1;
            player2.ClearSteps();
        }else{
            end++;
        }
        if(end == 2){
            break;
        }
    }

    if (player1.getAmount() > player2.getAmount() && end == 2) {
        printw("Win Player1\n");
        getch();
    }
    if (player1.getAmount() < player2.getAmount() && end == 2) {
        printw("Win Player2\n");
        getch();
    }
//    refresh();
    getch();
    endwin();
    return 0;
}
