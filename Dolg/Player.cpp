//#include "Player.h"
#include "Engine.h"

Player::Player(char c, int size) : color(c), amount(2) {
    amount = 2;
    steps.resize(size+2);
    for(int i = 0; i < size+2; ++i){
        steps[i].resize(size+2);
        for(int j = 0; j < size+2; j++){
            steps[i][j] = false;
        }
    }
}

int Player::getAmount() {
    return  amount;
}

void Player::setPossibleMoves(int x, int y) {
    if(steps[x][y]){
        steps[x][y] = false;
    } else{
        steps[x][y] = true;
    }
}

void Player::ClearMoves(){
    for(int i = 1; i < steps.size(); ++i){
        for(int j = 1; j < steps.size(); ++j){
            steps[i][j] = false;
        }
    }
}

Player Player::setAmount(int i) {
    amount += i;
    return *this;
}

std::vector<std::vector<bool> > Player::getSteps() {
    return steps;
}

char Player::getColor() {
    return color;
}
