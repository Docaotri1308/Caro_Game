#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H
#include <iostream>
#include <string>

// Player class responsible of handling all the player's choices
class player {
public :
    player(std::string name,std::string sign);
    player(std::string name);
    void choose_sign_auto(std::string sign);
    std::string get_sign();
    bool get_turn();
    void set_turn(bool turn);
    std::string get_name();
private :
    std::string m_name;
    std::string x_o;
    bool m_turn;
    bool m_winner;
};
#endif