//
//  Cell.hpp
//  Program 3
//
//  Created by Kevin Ip on 8/27/16.
//  Copyright © 2016 Kevin Ip. All rights reserved.
//

#ifndef Cell_h
#define Cell_h

#include <stdio.h>


class CCell
{
public:
  CCell();
  ~CCell();
  
  bool CheckTop();
  bool CheckLeft();
  bool CheckRight();
  bool CheckBottom();
  
  void OpenTop();
  void OpenLeft();
  void OpenRight();
  void OpenBottom();
  
  void SetLabel(int l);
  int GetLabel();
  
  // pointers to parent/child for union
  CCell* parent;
  CCell* child;
  
  bool path; // used for solving maze
  
private:
  
  // 1 if open, 0 if closed
  bool topWall;
  bool leftWall;
  bool rightWall;
  bool bottomWall;
  
  // label is same as index in array
  int label;
  

  
};

#endif /* Cell_h */
