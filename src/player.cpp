#include "../include/player.h"

player::player(std::string name, std::string sign) : m_name(name) , x_o(sign),m_winner(false) {

}

player::player(std::string name) : m_name(name),m_winner(false){

}

/*
 Chooses the player's sign
 */
void player::choose_sign_auto(std::string sign) {
        this->x_o = sign;
}

/*
 Gets the player's sign
 */
std::string player::get_sign() {
    return this->x_o;
}
/*
 Check if it is this player's turn
 */
bool player::get_turn() {
    return this->m_turn;
}
/*
 chooses the player's turn
 */
void player::set_turn(bool turn) {
        this->m_turn = turn;
}

/*
 Gets the player's name
 */
std::string player::get_name() {
    return this->m_name;
}