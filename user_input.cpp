#include "user_input.h"

//Function that returns the integer number of the file
 
int find_file_number (char letter)
{
    files files_pair;
    files_pair.insert(std::pair<int,char>('a', 0));
    files_pair.insert(std::pair<int,char>('b', 1));
    files_pair.insert(std::pair<int,char>('c', 2));
    files_pair.insert(std::pair<int,char>('d', 3));
    files_pair.insert(std::pair<int,char>('e', 4));
    files_pair.insert(std::pair<int,char>('f', 5));
    files_pair.insert(std::pair<int,char>('g', 6));
    files_pair.insert(std::pair<int,char>('h', 7));
    
    files::iterator files_iter;
    files_iter = files_pair.find(tolower(letter));
    if(files_iter != files_pair.end()){
        return files_iter->second;
    }
    else{
        return 8; //value out of range to throw an error after
    }   
}

//Overloading operator to parse inputed move 
std::istream& operator >>(std::istream &input, user_input& position)
{
    std::string full_line;

    while (true){
        if (input >> full_line && full_line.size() == 2){
            if (isdigit(full_line[0]) == false && isdigit(full_line[1]) == true){
                if (find_file_number(full_line[0]) < 8 && (full_line[1] - '0') <= 8){
                    position.column = find_file_number(full_line[0]);
                    position.row = 8 - (full_line[1] - '0');
                    break;
                }
            } 
        } 
        std::cout << "✘ Not a position on the board. Please try again: ";
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}