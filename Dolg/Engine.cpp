#include "Engine.h"


int Engine::Step(Coordinates _coordinates, Map &_map, Player &_player) {
    _map.Step(_coordinates.x, _coordinates.y, _player.getColor());
    int amount = NumberOfTurns(_coordinates, _map, _player);
    _player.ClearMoves();
    PossibleMoves(_player, _map);

    return amount;
}

int Engine::getAmountPlayer(Player p) {
    return p.getAmount();
}

int Engine::PossibleMoves(Player &player, Map map) {
    std::vector<std::vector<char>> _map = map.getMap();
    int size = map.getSize();
    char color = player.getColor();
    int cnt = 0;
    //right
    for(int  i = 1; i < size; ++i){
        for(int j = 1; j < size; ++j){
            if(_map[i][j] == color){
                for(int k = j+1; k < size; ++k){
                    if((_map[i][k] != color && _map[i][k] != '.' && _map[i][k] != '#') && _map[i][k+1] == '.'){
                        player.setPossibleMoves(i, k+1);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

//    down
    for(int j = 1; j < size; ++j){
        for(int i = 1; i < size; ++i){
            if(_map[i][j] == color){
                for(int k = i+1; k < size; ++k){
                    if((_map[k][j] != color && _map[k][j] != '.' && _map[k][j] != '#') && _map[k+1][j] == '.'){
                        player.setPossibleMoves(k+1, j);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

//    left
    for(int i = size; i > 1; --i){
        for(int j = size; j > 1; --j){
            if(_map[i][j] == color){
                for(int k = j-1; k > 1; --k){
                    if((_map[i][k] != color && _map[i][k] != '.' && _map[i][k] != '#') && _map[i][k-1] == '.'){
                        player.setPossibleMoves(i, k-1);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    //down rigth
    for(int  i = 1; i < size; ++i){
        for(int j = 1; j < size; ++j) {
            if(_map[i][j] == color){
                for(int k = i+1, l = j+1; k < size && l < size; ++k, ++l){
                    if((_map[k][l] != color && _map[k][l] != '.' && _map[k][l] != '#') && _map[k+1][l+1] == '.'){
                        player.setPossibleMoves(k+1, l+1);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    //up
    for(int j = size; j > 1; --j){
        for(int i = size; i > 1; --i){
            if(_map[i][j] == color){
                for(int k = i-1; k > 1; --k){
                    if((_map[k][j] != color && _map[k][j] != '.' && _map[k][j] != '#') && _map[k-1][j] == '.'){
                        player.setPossibleMoves(k-1, j);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }


    //up rigth
    for(int  i = 1; i < size; ++i){
        for(int j = 1; j < size; ++j) {
            if(_map[i][j] == color){
                for(int k = i-1, l = j+1; k > 1 && l < size; --k, ++l){
                    if((_map[k][l] != color && _map[k][l] != '.' && _map[k][l] != '#') && _map[k-1][l+1] == '.'){
                        player.setPossibleMoves(k-1, l+1);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    //down left
    for(int  i = 1; i < size; ++i){
        for(int j = 1; j < size; ++j) {
            if(_map[i][j] == color){
                for(int k = i+1, l = j-1; k < size && l > 1; ++k, --l){
                    if((_map[k][l] != color && _map[k][l] != '.' && _map[k][l] != '#') && _map[k+1][l-1] == '.'){
                        player.setPossibleMoves(k+1, l-1);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    //up left
    for(int i = size; i > 1; --i){
        for(int j = size; j > 0; --j){
            if(_map[i][j] == color){
                for(int k = i-1, l = j-1; k > 1 && l > 1; --k, --l){
                    if((_map[k][l] != color && _map[k][l] != '.' && _map[k][l] != '#') && _map[k-1][l-1] == '.'){
                        player.setPossibleMoves(k-1, l-1);
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    return cnt;
}

int Engine::NumberOfTurns(Coordinates _coordinates, Map& _map, Player& player) {
    int count = 0;
    int amount = 0;
    bool flag = false;
    std::vector<std::vector<char>> map = _map.getMap();
    std::vector<std::vector<bool>> steps = player.getSteps();
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