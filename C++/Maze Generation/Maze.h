//
//  Maze.h
//  Program 3
//
//  Created by Kevin Ip on 8/19/16.
//  Copyright © 2016 Kevin Ip. All rights reserved.
//

#ifndef Maze_h
#define Maze_h

#include <iostream>
#include <vector>
#include "Cell.h"

using namespace std;

class CMaze : public CCell
{
public:
  CMaze(int numRows, int numColumns);
  ~CMaze(void);
  
  
  void MakeMaze(int seed);
  void PrintMaze();
  void SolveMaze();
  
private:
  
  //disjoint set methods
  void Union(int item1, int item2);
  int Find(int itemIndex);
  vector<int> s;
  vector<CCell> cells;
  int maxVal;
  
  int rows;
  int cols;
};

#endif /* Maze_h */
