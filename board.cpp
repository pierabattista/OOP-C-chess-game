#include "board.h"

using namespace chess; 

//Default constructor for the board filled with shared base class pointers for the different variants
board::board(std::string type)
{
    for (int row{0}; row < 8; row++){
            for (int column{0}; column < 8; column++){
                full_board[row][column] = 0;
            }
    }
    if (type == "standard"){
        for (int column{0}; column < 8; ++column){
            full_board[1][column] = std::make_shared <pawn> ('b');
            full_board[6][column] = std::make_shared <pawn>('w');
        }
        full_board[0][0] = std::make_shared <rook> ('b');
        full_board[0][1] = std::make_shared <knight> ('b');
        full_board[0][2] = std::make_shared <bishop> ('b');
        full_board[0][3] = std::make_shared <queen> ('b');
        full_board[0][4] = std::make_shared <king> ('b');
        full_board[0][5] = std::make_shared <bishop> ('b');
        full_board[0][6] = std::make_shared <knight> ('b');
        full_board[0][7] = std::make_shared <rook> ('b');

        full_board[7][0] = std::make_shared <rook> ('w');
        full_board[7][1] = std::make_shared <knight> ('w');
        full_board[7][2] = std::make_shared <bishop> ('w');
        full_board[7][3] = std::make_shared <queen> ('w');
        full_board[7][4] = std::make_shared <king> ('w');
        full_board[7][5] = std::make_shared <bishop> ('w');
        full_board[7][6] = std::make_shared <knight> ('w');
        full_board[7][7] = std::make_shared <rook> ('w');
    }
    if (type == "charge"){
        for (int column{0}; column < 8; ++column){
            full_board[1][column] = std::make_shared <pawn> ('b');
            full_board[6][column] = std::make_shared <pawn>('w');
        }
        for (int column{0}; column < 8; column++){
            if (column != 4){
                full_board[0][column] = std::make_shared <knight> ('b');
            }
        }
        full_board[0][4] = std::make_shared <king> ('b');

        full_board[7][1] = std::make_shared <queen> ('w');
        full_board[7][3] = std::make_shared <queen> ('w');
        full_board[7][4] = std::make_shared <king> ('w');
        full_board[7][6] = std::make_shared <queen> ('w');
    } 
    if (type == "revolt"){
        for (int column{0}; column < 8; ++column){
            full_board[6][column] = std::make_shared <pawn>('w');
        }
        full_board[0][1] = std::make_shared <knight> ('b');
        full_board[0][2] = std::make_shared <knight> ('b');
        full_board[0][4] = std::make_shared <king> ('b');
        full_board[0][5] = std::make_shared <knight> ('b');
        full_board[0][6] = std::make_shared <knight> ('b');
        full_board[1][4] = std::make_shared <pawn> ('b');

        full_board[7][4] = std::make_shared <king> ('w');
    }
    if (type == "weak"){
        for (int column{0}; column < 8; ++column){
            full_board[1][column] = std::make_shared <pawn> ('b');
            full_board[6][column] = std::make_shared <pawn>('w');
        }
        for (int column{0}; column < 8; column++){
            if (column != 4){
                full_board[0][column] = std::make_shared <knight> ('b');
            }
        }
        full_board[0][4] = std::make_shared <king> ('b');
        full_board[2][2] = std::make_shared <pawn> ('b');
        full_board[2][5] = std::make_shared <pawn> ('b');
        for (int column{1}; column < 6; column++){
            full_board[3][column] = std::make_shared <pawn> ('b');
        }
        full_board[7][0] = std::make_shared <rook> ('w');
        full_board[7][1] = std::make_shared <knight> ('w');
        full_board[7][2] = std::make_shared <bishop> ('w');
        full_board[7][3] = std::make_shared <queen> ('w');
        full_board[7][4] = std::make_shared <king> ('w');
        full_board[7][5] = std::make_shared <bishop> ('w');
        full_board[7][6] = std::make_shared <knight> ('w');
        full_board[7][7] = std::make_shared <rook> ('w');
    }     
}

//Constructor to create a copy of a board 
board::board(array_pieces &b)
{
    for (int row{0}; row < 8; row ++){
        for (int column{0}; column < 8; column++)
        full_board[row][column] = b[row][column];
    }
}

//Functions to print the board. First a line (with or without pieces) is printed, then a board row, and then the full board
void board::print_empty_line(char color1, char color2)
{
    for (int couple_squares{0}; couple_squares < 4; couple_squares++){
        for (int character{0}; character <= size_square ; character++){
            std::cout << color1;
        }
        for (int character{0}; character <= size_square; character++){
            std::cout << color2;
        }
    }
}
void board::print_piece_line(char color1, char color2, int row)
{
    for (int couple_squares{0}; couple_squares < 4; couple_squares++){
        for (int character{0}; character < size_square ; character++){
            if (character == size_square/2){
                if (full_board[row][2*couple_squares] == 0){
                    std::cout << color1;
                } else {
                    if (full_board[row][2*couple_squares]->get_color() == 'b'){
                        std::cout << full_board[row][2*couple_squares] -> get_name();
                    } else {
                        std::cout << char(toupper(full_board[row][2*couple_squares] -> get_name()));
                    }   
                }
            } if ((character- size_square/2 == 0 || character - size_square/2 == -1) && full_board[row][2*couple_squares] != 0){
                //Leave space on the left and right of the piece character to ease readability  
                std::cout << " ";
            } else {
                std::cout << color1;
            }    
        }
        for (int character{0}; character < size_square ; character++){
            if (character == size_square/2){
                if (full_board[row][1 + (2*couple_squares)] == 0){
                    std::cout << color2;
                } else {
                    if (full_board[row][1 + (2*couple_squares)]->get_color() == 'b'){
                        std::cout << full_board[row][1 + (2*couple_squares)] -> get_name();
                    } else {
                        std::cout << char(toupper(full_board[row][1 + (2*couple_squares)] -> get_name()));
                    }
                }
            } if ((character- size_square/2 == 0 || character - size_square/2 == -1) && full_board[row][1 + (2*couple_squares)] != 0){
                //Leave space on the left and right of the piece character to ease readability
                std::cout << " ";
            } else {
                std::cout << color2;
            }    
        } 
    }
}
void board::print_row(char color1, char color2, int row) 
{
    for (int line{0}; line < size_square/2; line++){
        if (line == ((size_square/2)-1)/2){
            std::cout << "  " << 8-(row) << "  ";
            print_piece_line(color1, color2, row);
            std::cout<< '\n';
        } else{
            std::cout << "     ";
            print_empty_line (color1, color2);
            std::cout<< '\n';
        }
    } 
}
void board::print_board(char color1, char color2)
{
    std::cout << "\n\tA      B      C      D      E      F      G      H\n\n";
    for (int row{0}; row < 4; row++){
        print_row(color1, color2, 2*row);
        print_row(color2, color1, 1 + (2*row));
    }
}

//Function to return the position index of a specific piece
board::position_index board::get_piece_position (char color, char name)
{
    for (int row{0}; row < 8; row++){
        for (int column{0}; column < 8; column++){
            if (full_board[row][column] != 0){
                if (full_board[row][column] -> get_name() == name){
                    if (full_board[row][column] -> get_color() == color){
                        return position_index{row, column};
                    }
                }
            } 
        }
    }
    return position_index{8,8}; //index out of range
}

//Function to check if the selected piece is a piece and if its color is the given one 
bool board::is_piece_of_color(int start_row, int start_column, char color)
{
    if (full_board[start_row][start_column] != 0 && full_board[start_row][start_column]->get_color() == color){
        return true;
    } else{
        return false;
    }
}

//Function to check if the selected piece is a piece and if its color is the opposite of the given one
bool board::is_piece_of_opposite_color(int start_row, int start_column, char color)
{
    if (full_board[start_row][start_column] != 0 && full_board[start_row][start_column]->get_color() != color){
        return true;
    } else{
        return false;
    }
}

//Check if the selected square is allowed by the piece class
bool board::is_allowed_square(int start_row, int start_column, int end_row, int end_column, char color)
{
    if (full_board[start_row][start_column]->allowed_move(start_row, start_column, end_row, end_column, full_board)){
        return true;
    } else {
        return false;
    }
}

//Function to move a piece
void board::move_piece(int start_row, int start_column, int end_row, int end_column)
{
    full_board[end_row][end_column] = full_board[start_row][start_column];
    full_board[start_row][start_column] = 0;
}

//Function to increase the number of times a piece is moved
int board::increase_move_counter(int row, int column)
{
    return full_board[row][column]->increase_times_moved();
}

//Function to check if the king is in check
bool board::king_in_check(char color)
{
    position_index king_position{get_piece_position(color, 'k')};
    for (int row{0}; row < 8; row++){
        for (int column{0}; column < 8; column++){
            if (full_board[row][column] != 0 && full_board[row][column]->get_color() != color){
                if (full_board[row][column]->allowed_squares(row,column, king_position.row, king_position.column, full_board)){
                    return true;
                }
            }
        }
    }
    return false;
}

//Function to check if the movement of a piece puts the king in check 
bool board::puts_king_in_check(int start_row, int start_column, int end_row, int end_column, char const color)
{
    board temp_board{full_board};
    temp_board.move_piece(start_row, start_column, end_row, end_column);
    if (temp_board.king_in_check(color)){
        return true;
    } else {
        return false;
    }
}

//Function to check if the king can move to any square in which it is not in check
bool board::king_can_move(char color)
{
    position_index king_position{get_piece_position(color, 'k')};

    for (int row{0}; row < 8; row ++){
        for (int column{0}; column < 8; column++){
            if (full_board[king_position.row][king_position.column]->allowed_move(king_position.row, king_position.column, row, column, full_board)==true){
                board temp_board{full_board};
                temp_board.move_piece(king_position.row, king_position.column, row, column);
                if (!temp_board.king_in_check(color)){
                    return true;
                }
            }
        }
    }
    return false;
}

//Function to check if one attacker is present if any other piece of the pther color can eat it 
bool board::can_take_attacker(char color)
{
    position_index king_position{get_piece_position(color, 'k')};
    position_index attacker_piece;

    int number_of_attackers{0};
    for (int row{0}; row < 8; row++){
        for (int column{0}; column < 8; column++){
            if (is_piece_of_opposite_color(row, column, color) && full_board[row][column]->allowed_move(row, column, king_position.row, king_position.column, full_board)){
                number_of_attackers++;
                attacker_piece.row = row;
                attacker_piece.column = column;
            }
        }
    }
    if (number_of_attackers == 1){
        for (int row{0}; row < 8; row++){
            for (int column{0}; column < 8; column++){
                if (is_piece_of_color(row, column, color) && full_board[row][column]->allowed_move(row, column, attacker_piece.row, attacker_piece.column, full_board) && full_board[row][column]->get_name() != 'k'){
                    return true;
                }
            }
        }
    }
    return false;
}

//Checks if any piece in the chessboard of the same color can move (for stalemate)
bool board::any_piece_can_move(char color){

    for (int start_row{0}; start_row < 8; start_row++){
        for (int start_column{0}; start_column < 8; start_column++){
            for (int end_row{0}; end_row < 8; end_row++){
                for (int end_column{0}; end_column < 8; end_column++){
                    if (is_piece_of_color(start_row, start_column, color) && full_board[start_row][start_column]->allowed_move(start_row, start_column, end_row, end_column, full_board) && full_board[start_row][start_column]->get_name() != 'k'){
                    return true;
                    }
                }
            }
        }
    }
    return false;
}


bool board::is_checkmate(char color)
{
    if (king_in_check(color) && !can_take_attacker(color) && !king_can_move(color)){
        return true;
    }else{
        return false;
    }
}

bool board::is_stalemate(char color)
{
    if (!king_in_check(color) && !king_can_move(color) && !any_piece_can_move(color)){
        return true;
    } else {
        return false;
    }
}

//Function to check if a pawn hits a square in which it has to be promoted and promotes it
void board::check_pawn_promotion()
{
   for (int column{0}; column < 8; column++){
       if (full_board[0][column] != 0 && full_board[0][column]->get_name()=='p' && full_board[0][column]->get_color() == 'w'){
           full_board[0][column] = std::make_shared <queen> ('w');
       } else if (full_board[7][column]!=0 && full_board[7][column]->get_name()=='p' && full_board[7][column]->get_color() == 'b'){
           full_board[7][column] = std::make_shared <queen> ('b');
       }
   }
}

//Check if the squares are emty, the rook and king have never moved, and if the king is not in check in each square it travels
bool board::castling_king_side_allowed(int start_row, int start_column, int end_row, int end_column, char color)
{
    if (!king_in_check(color)){
        if (color == 'w' && start_row == 7 && start_column == 4 && end_row ==7 && end_column == 6){
            if (full_board[7][7] != 0 && full_board[7][7]->get_name() == 'r'){
                if (full_board[7][4] != 0 && full_board[7][4]->get_name() == 'k'){
                    if (full_board[7][4]->get_number_moves() == 0 && full_board[7][7]->get_number_moves() == 0){
                        for (int column{5}; column < 7; column++){
                            board temp_board{full_board};
                            temp_board.move_piece(start_row, start_column, end_row, column);
                            if (temp_board.king_in_check('w')){
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        } else if (color == 'b' && start_row == 0 && start_column == 4 && end_row == 0 && end_column == 6){
            if (full_board[0][7] != 0 && full_board[0][7]->get_name() == 'r'){
                if (full_board[0][4] != 0 && full_board[0][4]->get_name() == 'k'){
                    if (full_board[0][4]->get_number_moves() == 0 && full_board[0][7]->get_number_moves() == 0){
                        for (int column{5}; column < 7; column++){
                            board temp_board{full_board};
                            temp_board.move_piece(start_row, start_column , end_row, column);
                            if (temp_board.king_in_check('b')){
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false; 
}

//Same as king side but from the queen side (different postion of rook and king)
bool board::castling_queen_side_allowed(int start_row, int start_column, int end_row, int end_column, char color)
{
    if (!king_in_check(color)){
        if (color == 'w' && start_row == 7 && start_column == 4 && end_row ==7 && end_column == 2){
            if (full_board[7][0] != 0 && full_board[7][0]->get_name() == 'r'){
                if (full_board[7][4] != 0 && full_board[7][4]->get_name() == 'k'){
                    if (full_board[7][4]->get_number_moves() == 0 && full_board[7][0]->get_number_moves() == 0){
                        for (int column{3}; column > 1; column--){
                            board temp_board{full_board};
                            temp_board.move_piece(start_row, start_column, end_row, column);
                            if (temp_board.king_in_check('w')){
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        } else if (color == 'b' && start_row == 0 && start_column == 4 && end_row ==0 && end_column == 2){
            if (full_board[0][0] != 0 && full_board[0][0]->get_name() == 'r'){
                if (full_board[0][4] != 0 && full_board[0][4]->get_name() == 'k'){
                    if (full_board[0][4]->get_number_moves() == 0 && full_board[0][0]->get_number_moves() == 0){
                        for (int column{3}; column > 1; column--){
                            board temp_board{full_board};
                            temp_board.move_piece(start_row, start_column, end_row, column);
                            if (temp_board.king_in_check('b')){
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

//Function to move the pieces to castle on the king side 
void board::castle_king_side(int start_row, int start_column, int end_row, int end_column)
{
    move_piece(start_row, start_column, end_row, end_column);
    move_piece(start_row, 7, end_row, 5);
} 

//Function to move the pieces to castle on the queen side
void board::castle_queen_side(int start_row, int start_column, int end_row, int end_column)
{
    move_piece(start_row, start_column, end_row, end_column);
    move_piece(start_row, 0, end_row, 3);
}