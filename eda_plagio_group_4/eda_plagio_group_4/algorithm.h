/**************************************************************************
 * @file algorithm.h		                                              *
 * @authors Matias Asmus	                                              *
 *								                                          *
 *								                                          *
 * @brief ...       Declarations for the implementation of the Lee        *
 *					algorithm											  *
 * @version 1                                                             *
 **************************************************************************
 */


#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "file_input_output.h"

void floodFillDistance(const vector<vector<char>>& matrix, int startX, int startY, vector<vector<int>>& distances, vector<vector<pair<int, int>>>& predecessors);
void findShortestPath(std::vector<vector<char>>& matrix, const vector<pair<int, int>>& points);

#endif