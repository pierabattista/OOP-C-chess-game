#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include "include.h"

namespace chess
{
    //Class to store the printing functions of the game together with the alternate turn function
    class game_interface
    {
    public:
        game_interface() {}
        ~game_interface() {} 
        std::string get_variant_type();
        char alternate_turn(char current_turn);
        void print_welcome_message();
        void print_turn (char current_turn);
        void print_winner (char current_turn);
        void print_stalemate ();
        void print_end_message();
    };
}

#endif