#include "include.h"
#include "piece.h"
#include "board.h"
#include "user_input.h"
#include "game_interface.h"

int main()
{
    using namespace chess; 

    //Initialize objects needed for the game
    game_interface interface;
    char current_turn{'w'};
    bool bad_input{true};
    bool game_end{false};

    interface.print_welcome_message();

    //Initialize the board with the user given chess variant type
    board current_board{interface.get_variant_type()};

    //Loop that keeps running until the game ends 
    while(game_end == false){
        
        user_input start;
        user_input end;

        current_board.print_board(char(white_square), char(black_square));
        interface.print_turn(current_turn); //Prints which player has to move

        //Loop that keeps running until a good input is passed  
        while(bad_input == true){
            
            std::cout << "\nStarting position: ";
            std::cin >> start;

            std::cout << "End position: ";
            std::cin >> end;
            
            //Check if the input squares contain the right type of piece, if the move or castling is allowed, and if the move puts the king in check
            //For each check, if not met, a different error message is shown  
            if (current_board.is_piece_of_color(start.get_row(), start.get_column(), current_turn)){
                
                if (current_board.is_allowed_square(start.get_row(), start.get_column(), end.get_row(), end.get_column(), current_turn) || 
                    current_board.castling_king_side_allowed(start.get_row(), start.get_column(), end.get_row(), end.get_column(), current_turn) ||
                    current_board.castling_queen_side_allowed(start.get_row(), start.get_column(), end.get_row(), end.get_column(), current_turn)){ 
                    
                    if (!current_board.puts_king_in_check(start.get_row(), start.get_column(), end.get_row(), end.get_column(), current_turn)){
                        
                        //After checks are met the piece is moved and the counter of its moves increased, the pawn promotion checked and the turn is changed
                        if (current_board.castling_king_side_allowed(start.get_row(), start.get_column(), end.get_row(), end.get_column(), current_turn)){
                            
                            current_board.castle_king_side(start.get_row(), start.get_column(), end.get_row(), end.get_column());
                        
                        } else if (current_board.castling_queen_side_allowed(start.get_row(), start.get_column(), end.get_row(), end.get_column(), current_turn)){
                            
                            current_board.castle_queen_side(start.get_row(), start.get_column(), end.get_row(), end.get_column());
                        
                        } else {
                            
                            current_board.move_piece(start.get_row(), start.get_column(), end.get_row(), end.get_column());
                            current_board.increase_move_counter(end.get_row(), end.get_column());
                            current_board.check_pawn_promotion();
                        }

                        //The turn is changed 
                        current_turn = interface.alternate_turn(current_turn);

                        //Check if game is ended (i.e. if checkmate or stalemate)
                        if (current_board.is_checkmate(current_turn)){
                            current_board.print_board(char(white_square), char(black_square));
                            interface.print_winner(current_turn);
                            //Set the input as good input and game as eneded to end both loops 
                            bad_input = false;
                            game_end = true;
                        
                        } else if (current_board.is_stalemate(current_turn)){
                            interface.print_stalemate();
                            //Set the input as good input and game as eneded to end both loops
                            bad_input = false;
                            game_end = true;
                        }
                        //If the game did not end break the bad input loop but keep the game loop running
                        break; 
                        game_end = false;
                    } else {
                        std::cout << "\n✘ This move puts the king in check. Please retry."<<std::endl;
                        bad_input = true;
                    }
                } else {
                    std::cout << "\n✘ The piece selected cannot move there. Please retry."<<std::endl;
                    bad_input = true;
                }
            } else {
                std::cout << "\n✘ The selected piece is not valid. Please retry."<< std::endl;
                bad_input = true;
            }
        }
    }

    interface.print_end_message();

    return 0;
}