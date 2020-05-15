#include "Engine.h"

Map::Map(int s) : size(s){
    map.resize(size+2);
    for(int i = 0; i < size+2; ++i){
        map[i].resize(size+2);
        for(int j = 0; j < size+2; ++j){
            map[i][j] = '.';
            map[0][j] = '#';
        }
        map[i][0] = '#';
    }

    for(int i = 0; i < size+2; ++i){
        map[size+1][i] = '#';
        map[i][size+1] = '#';
    }

    map[size/2][size/2] = 'W';
    map[size/2+1][size/2+1] = 'W';
    map[size/2+1][size/2] = 'B';
    map[size/2][size/2+1] = 'B';
}

void Map::DrawMap() {
    addch(' ');
    addch(' ');
    for(int i = 0; i < size+2; i++){
        printw("%i ", i+1);
    }
    addch('Y');
    addch('\n');
    for(int i = 0; i < size+2; ++i){
        printw("%i ", i+1);
        for(int j = 0; j < size+2; ++j){
            addch(map[i][j]);
            addch(' ');
        }
        addch('\n');
    }
    addch('X');
    addch('\n');
    addch('\n');
}

std::vector<std::vector<char> > Map::getMap() {
    return map;
}

void Map::Step(int x, int y, char color) {
    map[x][y] = color;
}

int Map::getSize() {
    return size;
}