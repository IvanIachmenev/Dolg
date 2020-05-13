#include <math.h>
#include <vector>
#include <memory>
#include <iostream>
#include <ncurses.h>


struct Coordinates{
    int x;
    int y;
};

class Map {
private:
    std::vector<std::vector<char>> map;
    int size;
public:
    Map(int);
    void DrawMap();
    void Step(int, int, char);
    std::vector<std::vector<char>> getMap();
    int getSize();
};

class Player{
private:
    char color;
    int amount;
    std::vector<std::vector<bool>> steps;
//    Coordinates coordinates;
public:
    Player(char, int);
    Player setAmount(int);
    int getAmount();
    char getColor();
    void ClearMoves();
    std::vector<std::vector<bool>> getSteps();
    void setPossibleMoves(int, int);
};

class Engine {
private:

public:
    int Step(Coordinates, Map&, Player&);
    int NumberOfTurns(Coordinates, Map&, Player&);
    int getAmountPlayer(Player);
    int PossibleMoves(Player&, Map);
};
