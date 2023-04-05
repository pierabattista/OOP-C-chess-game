#ifndef BOARD_H
#define BOARD_H

#include "include.h"
#include "piece.h"

namespace chess
{
    //Class to store the board representation together with the rules allowed in it
    class board
    {
    private:
        //Bidimensional array of shared pointers representing the full board
        array_pieces full_board;  
        
        //Structure to return a piece position index
        struct position_index
        {
            int row;
            int column;
        };
        
    public:
        board(std::string type);
        ~board() {}
        board (array_pieces&);

        array_pieces& get_current_board() {return full_board;}

        void print_empty_line(char color1, char color2);
        void print_piece_line(char color1, char color2, int row);
        void print_row(char color1, char color2, int row);
        void print_board(char color1, char color2);
        
        position_index get_piece_position(char color, char name);
        bool is_piece_of_color(int start_row, int start_column, char color);
        bool is_piece_of_opposite_color(int start_row, int start_column, char color);
        bool is_allowed_square(int start_row, int start_column, int end_row, int end_column, char color);
        void move_piece(int start_row, int start_column, int end_row, int end_column);
        int increase_move_counter(int start_row, int start_column);

        bool king_in_check(char color);
        bool puts_king_in_check(int start_row, int start_column, int end_row, int end_column, char color);
        bool king_can_move(char color);
        bool can_take_attacker(char color);
        bool any_piece_can_move(char color);
        
        bool is_checkmate(char color);
        bool is_stalemate(char color);
        
        void check_pawn_promotion();
        bool castling_king_side_allowed(int start_row, int start_column, int end_row, int end_column, char color);
        bool castling_queen_side_allowed(int start_row, int start_column, int end_row, int end_column, char color);
        void castle_king_side(int start_row, int start_column, int end_row, int end_column);
        void castle_queen_side(int start_row, int start_column, int end_row, int end_column);
    
    };
}

#endif