#ifndef PIECE_H
#define PIECE_H

#include "include.h"

namespace chess
{
    //Abstract class to contain the piece color, name, and amount of moves done
    //Virtual function overridden ineach inherited class: allowed_square 
    class piece
    {
    protected:
        const char color;
        const char name;
        int number_moves;
    public:
        piece(const char c, const char n) : color{c}, name{n} , number_moves{0} {}
        virtual ~piece() {};
        virtual bool allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position) = 0;
        bool allowed_move(int start_row, int start_column, int end_row, int end_column, array_pieces position);

        char get_color() const {return color;}
        char get_name() const {return name;}
        int get_number_moves() const {return number_moves;}
        int increase_times_moved() {return number_moves = number_moves + 1;}
    };

    class pawn: public piece
    {
    public:
        pawn(char c) : piece{c, 'p'} {}
        ~pawn() {};
        
        bool allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position);
    };

    class knight: public piece
    {
    public:
        knight(char c) : piece {c, 'n'} {} 
        ~knight() {}
        
        bool allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position);
    };

    class rook: public piece 
    {
    public:
        rook(char c) : piece{c, 'r'} {}
        ~rook() {}

        bool allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position);
    };

    class bishop: public piece
    {
    public:
        bishop(char c) : piece{c, 'b'} {}
        ~bishop() {};

        bool allowed_squares (int start_row, int start_column, int end_row, int end_column, array_pieces position);
    };

    class queen : public piece
    {
    public:
        queen(char c) : piece{c, 'q'} {}
        ~queen() {}
        bool allowed_squares (int start_row, int start_column, int end_row, int end_column, array_pieces position);
    };

    class king: public piece
    {
    public:
        king (char c) : piece{c, 'k'} {}
        ~king() {}

        bool allowed_squares (int start_row, int start_column, int end_row, int end_column, array_pieces position);
    };
}

#endif