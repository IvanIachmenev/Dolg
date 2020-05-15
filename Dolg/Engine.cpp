#include "Engine.h"


int Engine::Step(Coordinates _coordinates, Map &_map, Player &_player) {
//    _map.Step(_coordinates.x, _coordinates.y, _player.getColor());
//    int amount = NumberOfTurns(_coordinates, _map, _player);
//    PossibleMoves(_player, _map);

    return 0;
}

int Engine::getAmountPlayer(Player p) {
    return p.getAmount();
}

std::vector<int> Engine::PossibleMoves(Player &player, Map &map) {
    std::vector<std::vector<char>> _map = map.getMap();
    int size = map.getSize();

    int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    std::vector<int> s;
    for(int i = 1; i < size; ++i){
        for(int j = 1; j < _map[i].size(); ++j){
            if(_map[i][j] != (player.getColor() ? 'B' : 'W')) continue;

            for(int k = 0; k < 8; ++k){
                int path_length = 0;
                bool found_empty = false;

                int ni = i + dx[k], nj = j + dy[k];
                while(ni >= 0 && nj >= 0 && ni < size && nj < _map[ni].size()){
                    if(_map[ni][nj] == '.'){
                        found_empty = true;
                        break;
                    }

                    if(_map[ni][nj] == (player.getColor() ? 'B' : 'W')){
                        break;
                    }
                    path_length++;
                    ni = ni + dx[k];
                    nj = nj + dy[k];
                }

                if(found_empty && path_length > 0) {
                    s.emplace_back(nj);
                    s.emplace_back(ni);
                    s.emplace_back(j);
                    s.emplace_back(i);
                }
            }
        }
    }

    player.setSteps(s);

    return s;
}

std::vector<int> Engine::PossibleMoves(Player &player, Map &map, char c) {
    std::vector<std::vector<char>> _map = map.getMap();
    int size = map.getSize();

    int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    std::vector<int> s;
    for(int i = 1; i < size; ++i){
        for(int j = 1; j < _map[i].size(); ++j){
            if(_map[i][j] != (player.getColor() ? 'W' : 'B')) continue;

            for(int k = 0; k < 8; ++k){
                int path_length = 0;
                bool found_empty = false;

                int ni = i + dx[k], nj = j + dy[k];
                while(ni >= 0 && nj >= 0 && ni < size && nj < _map[ni].size()){
                    if(_map[ni][nj] == '.'){
                        found_empty = true;
                        break;
                    }

                    if(_map[ni][nj] == (player.getColor() ? 'W' : 'B')){
                        break;
                    }
                    path_length++;
                    ni = ni + dx[k];
                    nj = nj + dy[k];
                }

                if(found_empty && path_length > 0) {
                    s.emplace_back(nj);
                    s.emplace_back(ni);
                    s.emplace_back(j);
                    s.emplace_back(i);
                }
            }
        }
    }

    player.setSteps(s);

    return s;
}

int Engine::NumberOfTurns(Coordinates _coordinates, Map& _map, Player& player) {
    Coordinates coordinatesEnd;
    std::vector<std::vector<char>> map = _map.getMap();

    int count = 0;
    int amount = 0;
    bool flag = false;
    char color = player.getColor();


    // down
    char c;
    for(int i = _coordinates.x+1; i < _map.getSize(); ++i){
        if(map[i][_coordinates.y] != color && map[i][_coordinates.y] != '.' && map[i][_coordinates.y] != '#'){
            count++;
        }else{
            if(map[i][_coordinates.y] == color){
                flag = true;
                break;
            }
        }
    }

    amount += count;
    int temp = 0;
    for(int i = _coordinates.x+1; temp < count; ++temp, ++i){
        if(flag){
            _map.Step(i, _coordinates.y, color);
        }
    }
    count = 0;
    flag = false;

//    up
    for(int i = _coordinates.x-1; i > 1; --i){
        if(map[i][_coordinates.y] != color && map[i][_coordinates.y] != '.'  && map[i][_coordinates.y] != '#'){
            count++;
        }else{
            if(map[i][_coordinates.y] == color){
                flag = true;
                break;
            }
        }
    }

    amount += count;
    for(int i = _coordinates.x-1, j = 0; j < count; --i, ++j){
        if(flag){
            _map.Step(i, _coordinates.y, color);
        }
    }
    count = 0;
    flag = false;

    //left
    for(int i = _coordinates.y+1; i < _map.getSize(); ++i){
        if(map[_coordinates.x][i] != color && map[_coordinates.x][i] != '.' && map[_coordinates.y][i] != '#'){
            count++;
        }else{
            if(map[_coordinates.x][i] == color){
                flag = true;
                break;
            }
        }
    }

    amount += count;
    for(int i = _coordinates.y+1, j = 0; j < count; ++j, ++i){
        if(flag){
            _map.Step(_coordinates.x, i, color);
        }
    }
    count = 0;
    flag = false;

    //right
    for(int i = _coordinates.y-1; i > 1; --i){
        if(map[_coordinates.x][i] != color && map[_coordinates.x][i] != '.'  && map[_coordinates.y][i] != '#'){
            count++;
        }else{
            if(map[_coordinates.x][i] == color){
                flag = true;
                break;
            }
        }
    }

    amount += count;
    for(int i = _coordinates.y-1, j = 0; j < count; ++j, --i){
        if(flag){
            _map.Step(_coordinates.x, i, color);
        }
    }
    count = 0;
    flag = false;

    //down right
    for(int i = _coordinates.x+1, j = _coordinates.y+1; i < _map.getSize() && j < _map.getSize(); ++i, ++j){
        if(map[i][j] != color && map[i][j] != '.' && map[i][j] != '#'){
            count++;
        }else{
            if(map[i][j] == color){
                flag = true;
                break;
            }
        }
    }


    temp = 0;
    amount += count;
    for(int i = _coordinates.x+1, j = _coordinates.y+1; temp < count; ++temp, ++i, ++j){
        if(flag){
            _map.Step(i, j, color);
        }
    }
    count = 0;
    flag = false;

    //up left
    for(int i = _coordinates.x-1, j = _coordinates.y-1; i > 0 && j > 0; --i, --j){
        if(map[i][j] != color && map[i][j] != '.' && map[i][j] != '#'){
            count++;
        }else{
            if(map[i][j] == color){
                flag = true;
                break;
            }
        }
    }

    temp = 0;
    amount += count;
    for(int i = _coordinates.x-1, j = _coordinates.y-1; temp < count; ++temp, --i, --j){
        if(flag){
            _map.Step(i, j, color);
        }
    }
    count = 0;
    flag = false;

    //up right
    for(int i = _coordinates.x-1, j = _coordinates.y+1; i > 1 && j < _map.getSize(); --i, ++j){
        if(map[i][j] != color && map[i][j] != '.' && map[i][j] != '#'){
            count++;
        }else{
            if(map[i][j] == color){
                flag = true;
                break;
            }
            break;
        }
    }

    temp = 0;
    amount += count;
    for(int i = _coordinates.x-1, j = _coordinates.y+1; temp < count; ++temp, --i, ++j){
        if(flag){
            _map.Step(i, j, color);
        }
    }
    count = 0;
    flag = false;

    //down left
    for(int i = _coordinates.x+1, j = _coordinates.y-1; i < _map.getSize() && j > 1; ++i, --j){
        if(map[i][j] != color && map[i][j] != '.' && map[i][j] != '#'){
            count++;
        }else{
            if(map[i][j] == color){
                flag = true;
                break;
            }
            break;
        }
    }

    temp = 0;
    amount += count;
    for(int i = _coordinates.x+1, j = _coordinates.y-1; temp < count; ++temp, ++i, --j){
        if(flag){
            _map.Step(i, j, color);
        }
    }

    return amount;
}