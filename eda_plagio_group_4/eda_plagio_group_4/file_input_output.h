
/**************************************************************************
 * @file file_input_output.h                                              *
 * @authors Lucas Solar Grillo                                            *
 *          Andrea Enricci                                                *
 *								                                          *
 * @brief ...       This file handles text file input and output using    *
 *                  the functions input_file and						  *
 *                  printMatrix											  *
 * @version 1                                                             *
 **************************************************************************
 */


#ifndef FILE_INPUT_OUTPUT
#define FILE_INPUT_OUTPUT

#include <iostream>
#include <vector>
#include <string>
#include <utility> //para el contenedor pair.
using namespace std;

typedef vector<vector<char>> Matriz;
typedef pair<int, int> Coordenada;
typedef vector<vector<Coordenada>> GruposCoordenadas;	
void input_file(const string& file_name, Matriz& matriz, GruposCoordenadas& grupos);
void printMatrix(const vector<vector<char>>& matrix);

#endif
