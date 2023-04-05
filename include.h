#ifndef INCLUDE_H
#define INCLUDE_H

#include<iostream>
#include<memory>
#include<array>
#include<map>
#include<limits>
#include<string>

//definition of the size of a square in the board
#define size_square 6

#define white_square ' '
#define black_square '*'

//definition of the two dimensional array of pointers for the board to ease readability of code
#define array_pieces std::array<std::array<std::shared_ptr<piece>,8>,8> 

#endif
