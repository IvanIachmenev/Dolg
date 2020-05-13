#include "Engine.h"
#include <string.h>

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

    Engine engine;
    Coordinates coordinates;
    initscr();
    printw("First turn: ");
    printw("Player1\n");



    int o = 0;
    int steps;
    std::vector<std::vector<char>> _map = map.getMap();
    for(int i = 0; i < (size*size-4)/2; i++){
        if(o == 1){
            printw("Turns Player1\n");
        } else{
            o = 1;
        }
        map.DrawMap();

        steps = engine.PossibleMoves(player1, map);
        if(steps == 0){
            printw("Win Player2");
            break;
        }
        printw("Enter coordinates (y, x) separated by space\n");
        scanw("%i%i", &coordinates.x, &coordinates.y);

        int amount1 = engine.Step(coordinates, map, player1)+1;
//        if(amount == 1){
//            for(;;){
//                map.Step(coordinates.x, coordinates.y, '.');
//                printw("Impossible action!\n");
//                scanw("%i%i", &coordinates.x, &coordinates.y);
//                amount = engine.Step(coordinates, map, player1);;
//                if(amount > 1){
//                }
//            }
//        }

        player1.setAmount(amount1);
        player2.setAmount(-amount1);
//                    break;
        clear();

        printw("Turn Player2\n");
        map.DrawMap();

        printw("Enter coordinates (y, x) separated by space\n");
        steps = engine.PossibleMoves(player2, map);
        if(steps == 0){
            printw("Win Player1");
            break;
        }
        scanw("%i%i", &coordinates.x, &coordinates.y);
        int amount2 = engine.Step(coordinates, map, player2)+1;
//        if(amount == 1){
//            for(;;){
//                map.Step(coordinates.x, coordinates.y, '.');
//                printw("Impossible action!\n");
//                scanw("%i%i", &coordinates.x, &coordinates.y);
//                amount = engine.Step(coordinates, map, player2)+1;
//                if(amount > 1){
//                }
//            }
//        }

        player1.setAmount(-amount2);
        player2.setAmount(amount2);

        if(player1.getAmount() > player2.getAmount()){
            printw("Win Player1");
        }
        if(player1.getAmount() < player2.getAmount()){
            printw("Win Player2");
        }

        clear();
    }


    refresh();
    getch();
    endwin();
    return 0;
}
