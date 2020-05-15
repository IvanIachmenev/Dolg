//#include "Player.h"
#include "Engine.h"

Player::Player(char c, int size) : color(c), amount(2) {
    amount = 2;
}

int Player::getAmount() {
    return  amount;
}

void Player::setSteps(std::vector<int> s){
    steps = s;
}

Player Player::setAmount(int i) {
    amount += i;
    return *this;
}

std::vector<int> Player::getSteps() {
    return steps;
}

char Player::getColor() {
    return color;
}

void Player::ClearSteps(){
    steps.clear();
}