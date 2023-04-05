#include"game_interface.h"

using namespace chess;

//Function to get the variant type of chess game requested 
std::string game_interface::get_variant_type()
{
    std::string variant;
    std::cout << "Available variants of chess: standard (standard), charge of the light brigade (charge), peasant's revolt (revolt), weak (weak)" << std::endl;
    std::cout << "\nPlease insert one of the codes in bracket to start the selected game: ";
    
    while(true){
        std::cin >> variant;
        if (variant == "standard" || variant == "charge" || variant == "revolt" || variant == "weak"){
            break;
            } else {
                std::cerr<< "Input not regonized. Please insert one of the codes in brackets: ";
                continue;
        }
    }
    return variant; 
}

//Function that alternates turn
char game_interface::alternate_turn(char current_turn)
{
    if (current_turn == 'w'){
        return 'b';
    } else {
        return 'w';
    }
}

void game_interface::print_welcome_message()
{
    std::cout<<"\n\n\t*************************************************"<< std::endl;
    std::cout<<"\t*                                               *"<<std::endl;
    std::cout<<"\t*             CHESS CONSOLE V 1.01              *"<<std::endl;
    std::cout<<"\t*                                               *"<<std::endl;
    std::cout<<"\t*************************************************\n"<< std::endl;

    std::cout << "⊛  Easy in console chess game." <<std::endl;
    std::cout << "⊛  All the moves have to be pased in the following format: a1 or A1." << std::endl;
    std::cout << "⊛  Black pieces are lowercase characters."<<std::endl;
    std::cout << "⊛  White picese are uppercase characters."<<std::endl;
    std::cout << "⊛  Have fun! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ \n"<<std::endl;
}

void game_interface::print_turn (char current_turn)
{
    if (current_turn == 'w'){
        std::cout << "\n● White's turn (uppercase pieces)" << std::endl;
    } else {
        std::cout << "\n○ Black's turn (lowercase pieces)" << std::endl;
    }
}

void game_interface::print_winner (char current_turn)
{
    if (current_turn == 'w'){
        std::cout << "\n\t\t※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※"<<std::endl;
        std::cout << "\t\t※                             ※"<<std::endl;
        std::cout << "\t\t※    Black wins   <(￣︶￣)>  ※" << std::endl;
        std::cout << "\t\t※                             ※"<<std::endl;
        std::cout << "\t\t※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※\n"<<std::endl;
    } else {
        std::cout << "\n\t\t※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※"<<std::endl;
        std::cout << "\t\t※                             ※"<<std::endl;
        std::cout << "\t\t※    White wins   <(￣︶￣)>  ※" << std::endl;
        std::cout << "\t\t※                             ※"<<std::endl;
        std::cout << "\t\t※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※\n"<<std::endl;
    }   
}

void game_interface::print_stalemate ()
{
    std::cout << "\n\t\t※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※"<<std::endl;
    std::cout << "\t\t※                             ※"<<std::endl;
    std::cout << "\t\t※       Stalemate   (╥_╥)     ※" << std::endl;
    std::cout << "\t\t※                             ※"<<std::endl;
    std::cout << "\t\t※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※ ※\n"<<std::endl;
}

void game_interface::print_end_message()
{
    std::cout << "\nThank you for playing with me! („• ֊ •„)\n" << std::endl;
}