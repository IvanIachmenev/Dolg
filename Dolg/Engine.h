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
    std::vector<int> steps;
//    Coordinates coordinates;
public:
    Player(char, int);
    Player setAmount(int);
    int getAmount();
    char getColor();
    void setSteps(std::vector<int>);
    std::vector<int> getSteps();
    void ClearSteps();
};

class Engine {
private:

public:
    int Step(Coordinates, Map&, Player&);
    int NumberOfTurns(Coordinates, Map&, Player&);
    int getAmountPlayer(Player);
    std::vector<int> PossibleMoves(Player&, Map&);
    std::vector<int> PossibleMoves(Player &player, Map &map, char c);
};
