#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "include.h"

//Map to transfor the files (letter of the board) into integer indices
typedef std::map<char, int> files;
int find_file_number (char letter);

//Class to store the user input and check if within board
class user_input
{
private:
    int row;
    int column;
public:
    user_input() {}
    ~user_input() {};

    int get_row() const {return row;}
    int get_column() const {return column;}

    friend std::istream& operator >>(std::istream &input, user_input& position);
};

#endif