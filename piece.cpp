#include "piece.h"

using namespace chess; 

//Function for base class piece to check if the end position (different than starting position) is empty or of opposite color, and if the move is allowed by the specific inherited piece
bool piece::allowed_move(int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    if (position[end_row][end_column] == 0 || color != position[end_row][end_column]->get_color()){
        if (start_row != end_row || start_column != end_column){
            return allowed_squares(start_row, start_column, end_row, end_column, position);
        }
    }
    return false;     
}

//Allowed moves for the pawn including double starting move and en passant
bool pawn::allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    if (color == 'w'){
        if (end_row == start_row - 1){
            if (start_column == end_column && position[end_row][end_column] == 0){
                return true;
            } else if (position[end_row][end_column] != 0){
                if (end_column == start_column + 1 || end_column == start_column - 1){
                    return true;
                }
            } else if (start_row == 3 && end_row == 2 && abs(start_column - end_column) == 1){
                if (position[start_row][end_column]!= 0 && position[start_row][end_column]->get_number_moves() == 1){
                    if (position[start_row][end_column]->get_name() == 'p' && position[start_row][end_column]->get_color() == 'b'){
                        position[start_row][end_column] == 0;
                        return true;
                    }
                }
            }
        } else if (start_row == 6 && start_column == end_column && end_row == 4){
            if(position[5][start_column] == 0 && position[4][start_column] == 0){
                return true;
            }
        }
    } else if (color == 'b'){
        if (end_row == start_row + 1){
            if (start_column == end_column && position[end_row][end_column] == 0){
                return true;
            } else if (position[end_row][end_column] != 0){
                if (end_column == start_column + 1 || end_column == start_column - 1){
                    return true;
                }
            } else if (start_row==4 && end_row == 5 && abs(start_column - end_column) == 1){
                if (position[start_row][end_column]!= 0 && position[start_row][end_column]->get_number_moves() == 1){
                    if (position[start_row][end_column]->get_name() == 'p' && position[start_row][end_column]->get_color() == 'w'){
                        position[start_row][end_column] == 0;
                        return true;
                    }
                }
            }
        } else if (start_row == 1 && start_column == end_column && end_row == 3){
            if(position[2][start_column] == 0 && position[3][start_column] == 0){
                return true;
            }
        }
    } 
    return false;     
}

//Allowed moves for the knight (L shaped movement, allowed to "jump" pieces)
bool knight::allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    if (abs(start_row - end_row) == 1 && abs(start_column - end_column) == 2){
        return true;
    } else if (abs(start_row - end_row) == 2 && abs(start_column - end_column) == 1){
        return true;
    } else {
        return false;
    }
}

//Allowed moves for the rook (horizontal or vertcal)
bool rook::allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    if (start_column == end_column){
        if (start_row > end_row){
            for (int row{start_row - 1}; row > end_row; row--){
                if (position[row][start_column] != 0){
                    return false;
                } 
            } 
            return true;
        } else if (start_row < end_row){
            for (int row{start_row+1}; row < end_row; row++){
                if (position[row][start_column] != 0){
                    return false;
                }
            } 
            return true;
        }
    } else if (start_row == end_row){
        if (start_column > end_column){
            for (int column{start_column-1}; column > end_column; column--){
                if (position[start_row][column] != 0){
                    return false;
                }
            }
            return true;
        } else if (start_column < end_column){
            for (int column{start_column+1}; column < end_column; column++){
                if (position[start_row][column] != 0){
                    return false;
                }
            }
            return true; 
        }
    }
    return false;
}

//Allowed moves for the bishop (along diagonals)
bool bishop::allowed_squares (int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    int row_difference{end_row - start_row};
    int column_difference{end_column - start_column};
    
    if (abs(row_difference) == abs(column_difference)){
        if (row_difference > 0 && column_difference > 0){
            for (int increment{1}; increment < row_difference; increment++){
                if (position[start_row+increment][start_column+increment] != 0){
                    return false;
                }
            }
            return true;
        } else if (row_difference > 0 && column_difference < 0){
            for (int increment{1}; increment < row_difference; increment++ ){
                if ( position[start_row+increment][start_column - increment] != 0){
                    return false;
                }
            }
            return true;
        } else if ( row_difference < 0 && column_difference > 0){
            for (int increment{1}; increment < column_difference; increment++ ){
                if ( position[start_row-increment][start_column+increment] != 0){
                    return false;
                }
            }
            return true;
        } else if ( row_difference < 0 && column_difference < 0){
            for (int increment{1}; increment < abs(row_difference); increment++ ){
                if ( position[start_row-increment][start_column-increment] != 0){
                    return false;
                }
            }
            return true;
        }  
    }
    return false; 
}

//Allowed moves for queen (bishop and rook moves)
bool queen::allowed_squares (int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    int row_difference{end_row - start_row};
    int column_difference{end_column - start_column};

    if (start_column == end_column){
        if (start_row > end_row){
            for (int row{start_row - 1}; row > end_row; row--){
                if (position[row][start_column] != 0){
                    return false;
                }
            }
            return true;
        } else if (start_row < end_row){
            for (int row{start_row + 1}; row < end_row; row++){
                if (position[row][start_column] != 0){
                    return false;
                }
            }
            return true;
        }
    } else if (start_row == end_row){
        if (start_column > end_column){
            for (int column{start_column - 1}; column > end_column; column--){
                if (position[start_row][column] != 0){
                    return false;
                }
            }
            return true;
        } else if (start_column < end_column){
            for (int column{start_column + 1}; column < end_column; column++){
                if (position[start_row][column] != 0){
                    return false;
                }
            }
            return true; 
        }
    } else if (abs(row_difference) == abs(column_difference)){
        if (row_difference > 0 && column_difference > 0){
            for (int increment{1}; increment < row_difference; increment++){
                if (position[start_row+increment][start_column+increment] != 0){
                    return false;
                }
            }
            return true;
        } else if (row_difference > 0 && column_difference < 0){
            for (int increment{1}; increment < row_difference; increment++ ){
                if ( position[start_row+increment][start_column - increment] != 0){
                    return false;
                }
            }
            return true;
        } else if ( row_difference < 0 && column_difference > 0){
            for (int increment{1}; increment < column_difference; increment++ ){
                if ( position[start_row-increment][start_column+increment] != 0){
                    return false;
                }
            }
            return true;
        } else if ( row_difference < 0 && column_difference < 0){
            for (int increment{1}; increment < abs(row_difference); increment++ ){
                if ( position[start_row-increment][start_column-increment] != 0){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

//Allowed moves for the king
bool king::allowed_squares(int start_row, int start_column, int end_row, int end_column, array_pieces position)
{
    int row_difference{end_row - start_row};
    int column_difference{end_column - start_column};

    if ((abs(row_difference) == 1 || row_difference == 0) && (abs(column_difference) == 1 || column_difference == 0)){
        return true;
    } else{
        return false;
    }
}