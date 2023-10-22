#include "../include/board.h"

board::board() {
}


/*
 Show the new grid with numbers from 1 to 9 to help the players choose the position to put x or o in.
 */
void board::show_grid() {
    std::cout << "\t-------------" << std::endl;
    for (int x = 0 ; x < GRID_SIZE ; ++x){
        for (int y = 0 ; y < GRID_SIZE ; ++y){
            if ((x==0 && y ==0) || (x==1 && y == 0) || (x == 2 && y == 0)) {
                std::cout << "\t" << "| " << grid[x][y] << " | ";
            }
            else {
                std::cout << grid[x][y] << " | ";
            }
        }
        std::cout << "\n\t-------------\n";
    }
}
/*
 Ask the players each time to choose the position where they want to put x or o in and check if it is possible to
 choose that position
 */
void board::ask_turn(player *player1,player *player2) {
    std::string input;
    while(true){
        if(player1->get_turn()) {
            std::cout << player1->get_name() << " "<< "where would you like to play ?" << std::endl;
        }
        else if (player2->get_turn()){
            std::cout << player2->get_name() << " " << "where would you like to play ?" << std::endl;
        }
        getline(std::cin,input);
        if (input != ""){
            char entered = input.c_str()[0];
            if (entered >= '1' && entered <= '9'){
                int entered_number = entered - '0';
                int index = entered_number - 1 ;
                int row = index / 3;
                int col = index % 3;
                std::string grid_position = grid[row][col];
                if (grid_position == "x" || grid_position == "o"){
                    std::cout << "that grid position is already taken!" << std::endl;
                }
                else{
                    if(player1->get_turn() ) {
                        grid[row][col] = player1->get_sign();
                        player1->set_turn(false);
                        player2->set_turn(true);
                        break;
                    }
                    else if (player2->get_turn()){
                        grid[row][col] = player2->get_sign();
                        player1->set_turn(true);
                        player2->set_turn(false);
                        break;
                    }
                }

            }else{
                std::cout << "you have to play in range 1-9!" << std::endl;
            }
        }else{
            std::cout << "you must put something" <<std::endl;
        }
    }
}

/*
 Generate the grid in the first place and create two players and take all the information related to the players
 */
void board::generate_grid() {
    int number = 1;
    for (int x = 0 ; x < GRID_SIZE ; ++x){
        for (int y = 0 ; y < GRID_SIZE ; ++y){
            grid[x][y] = std::to_string(number).c_str()[0];
            number += 1;
        }
    }
    std::string player1_name;
    std::string player2_name;
    std::string player1_sign;
    std::cout << "player 1 please enter your name" << std::endl;
    getline(std::cin,player1_name);
    while (player1_sign != "x" && player1_sign != "o") {
        std::cout << "player 1 please choose x or o" << std::endl;
        getline(std::cin, player1_sign);
    }
    player *player1 = new player(player1_name,player1_sign);
    std::cout << "player 2 please enter your name" << std::endl;
    getline(std::cin,player2_name);
    player *player2 = new player(player2_name);
    if (player1_sign == "x" || player1_sign == "X"){
        player2->choose_sign_auto("o");
    }
    else {
        player2->choose_sign_auto("x");
    }
    player1->set_turn(true);
    player2->set_turn(false);
    this->p1 = player1;
    this->p2 = player2;
}
/*
 check each time whether we have a winner
 */
bool board::check_for_wins(player *player1, player *player2) {

    std::vector<std::string> winning_moves {
        "123",
        "456",
        "789",
        "147",
        "258",
        "369",
        "159",
        "357"
    };

    for (int i = 0 ; i < 8 ; ++i){
        bool winner = true;
        std::string previous_grid = "0";
         const std::string winning_move = winning_moves[i];
        for (int index = 0; index < GRID_SIZE ; ++index){
            char character = winning_move[index];
            int entered_number = character - '0';
            int grid_space = entered_number - 1;
            int row = grid_space / GRID_SIZE;
            int col = grid_space % GRID_SIZE;
            std::string grid_char = grid[row][col];
            if (previous_grid == "0"){
                previous_grid = grid_char;
            }
            else if (previous_grid == grid_char){
                continue;
            }
            else {
                winner = false;
                break;
            }
        }
        if (winner) {
            std::cout << "********* We have a winner! **********" << std::endl;
            if (previous_grid == player1->get_sign()){
                std::cout << "looks like " << player1->get_name() << " won! " << std::endl;
            }
            else if (previous_grid == player2->get_sign()) {
                std::cout << "looks like " << player2->get_name() << " won! " << std::endl;
            }
            return true;
        }
    }
    return false;
}

void board::play() {
    bool replay = true;
    while(replay) {
        replay = false;
        generate_grid();
        bool winner = false;
        bool draw = false;
        while (!winner && !draw) {
            show_grid();
            winner = check_for_wins(this->p1, this->p2);
            draw = check_for_draw();
            if(!winner && !draw) {
                ask_turn(this->p1, this->p2);
            }
        }
        std::string play;
        std::cout << "You want to play again ? (yes / no)" << std::endl;
        getline(std::cin,play);
        if(play == "yes") {
            replay = true;
        }
    }
}

/*
 check if we have a draw
 */
bool board::check_for_draw() {
    for (int i = 0 ; i < GRID_SIZE ; ++i){
        for (int j = 0 ; j < GRID_SIZE ; ++j){
            if(grid[i][j] != "x" && grid[i][j]!= "o"){
                return false;
            }
        }
    }
    std::cout << "********* We have a draw! **********" << std::endl;
    return true;
}