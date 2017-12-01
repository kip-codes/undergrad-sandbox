//
//  Maze.cpp
//  Program 3
//
//  Created by Kevin Ip on 8/19/16.
//  Copyright © 2016 Kevin Ip. All rights reserved.
//

#include "Maze.h"
#include "Cell.h"

/* CMaze()
 
 
 
 */
CMaze::CMaze(int numRows, int numColumns) : maxVal(numRows*numColumns)
{
// STEP 1: Create the nodes in their own equivalence class. 
  for (int i = 0; i < maxVal; i++){
    s.push_back(-1);
    
    CCell ccell;
    cells.push_back(ccell);
    cells[i].SetLabel(i);
  }//for i
  
  rows = numRows;
  cols = numColumns;
}// CMaze() constructor


/*
   May just be empty destructor since we are not removing any elements.
 */
CMaze::~CMaze(void)
{
}// CMaze() destructor


void CMaze::MakeMaze(int seed)
{
  
// PREPARATION: Open Enter and Exit cells
  cells[0].OpenTop();
  cells[0].OpenLeft();
  cells[maxVal-1].OpenRight();
  cells[maxVal-1].OpenBottom();
  
// STEP 1: Setup the RNG
  srand(seed);

  while (s[maxVal-1] != 0){
    int randNode = (int)maxVal * (float)(rand()/((double)RAND_MAX + 1));
    
    // 0 top, 1 right, 2 bot, 3 left
    int randWall = rand()%4;
           
     if (randWall == 0){
       //CONDITION: Top row, so cannot union
       if (randNode < cols)
         continue;
       
       //CONDITION: Already unionized
       if (Find(randNode) == Find(randNode-cols))
         continue;
       
       //SUCCESS: Unionize the adjacent node
       cells[randNode].OpenTop();
       cells[randNode-cols].OpenBottom();
       
       Union(randNode, randNode-cols);
       
     }// if TOP
           
     else if (randWall == 1){
       //CONDITION: Rightmost node, so cannot union
       if ((randNode+1)%cols == 0)
         continue;
       
       //CONDITION: Already unionized
       if (Find(randNode) == Find(randNode+1))
         continue;
       
       //SUCCESS: Unionize the adjacent node
       cells[randNode].OpenRight();
       cells[randNode+1].OpenLeft();
       
       Union(randNode, randNode+1);
       
     }// if RIGHT
           
     else if (randWall == 2){
       //CONDITION: Bottom row, so cannot union
       if (randNode >= (rows-1)*cols)
         continue;
       
       //CONDITION: Already unionized
       if (Find(randNode) == Find(randNode+cols))
         continue;
       
       
     }// if BOTTOM
           
     else if (randWall == 3){
       //CONDITION: Leftmost node, so cannot union
       if (randNode == 0 || randNode%cols == 0)
         continue;
       
       //CONDITION: Already unionized
       if (Find(randNode) == Find(randNode-1))
         continue;
       
       //SUCCESS: Unionize the adjacent node
       cells[randNode].OpenRight();
       cells[randNode-1].OpenLeft();
       
       Union(randNode, randNode-1);
       
     }// if LEFT
  }// while

}// MakeMaze()


void CMaze::PrintMaze()
{
  cells[0].OpenTop();
  cells[0].OpenLeft();
  cells[maxVal-1].OpenRight();
  cells[maxVal-1].OpenBottom();
  
  int i = 0, k = 0;
  for (; i < rows*2; i++){
    int temp;
    if (i == 0 || i % 2 == 0){//even for intersections
      // CONDITION 1: Print roofs
      temp = k;
      for (int j = 0; j < cols; j++){
        if (cells[k].CheckTop()) // open
          cout << "+   ";
        else // closed
          cout << "+ - ";
        
        k++;
      }// for j
      
      cout << "+" << endl;
    }// if ROOF
    
    else{
      // CONDITION 2: Print halls
      k = temp;
      for (int j = 0; j < cols; j++){
        if (cells[k].CheckLeft()) // open
          cout << "    ";
        else // closed
          cout << "|   ";
        
        k++;
      }// for j
      
      if (k == maxVal)
        cout << endl;
      else
        cout << "|" << endl;
    }// else HALL
    
  }// for i
  
  k = (rows-1) * cols;
  // CONDITION 3: Print floor
  for (int j = 0; j < cols; j++){
    if (cells[k].CheckBottom()) // open
      cout << "+   ";
    else // closed
      cout << "+ - ";
    
    k++;
  }// for j
  
  cout << "+" << endl;
  
}// PrintMaze()


/* SolveMaze()
 
 Contains a queue of nodes from start to end
 Should already be organized by shortest distance.
 
 */
void CMaze::SolveMaze()
{
  
}// SolveMaze()

/*
 *
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */

void CMaze::Union(int item1, int item2){
  
  if(s[item2] < s[item1]){
    s[item1] = item2;
  }//if
  
    // root2 is deeper
    // Make root2 new root
    // Update height if same // Make root1 new root
  
  else {
    if(s[item1] == s[item2])
      --s[item1];
    s[item2] = item1;
  }// else
} // Union()


int CMaze::Find(int itemIndex)
{
  if (s[itemIndex] < 0)
    return itemIndex;
  
  else
    return Find(s[itemIndex]);
  return 0;
}// Find()