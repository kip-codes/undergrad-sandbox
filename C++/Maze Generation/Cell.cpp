//
//  Cell.cpp
//  Program 3
//
//  Created by Kevin Ip on 8/27/16.
//  Copyright © 2016 Kevin Ip. All rights reserved.
//

#include "Cell.h"
#include <iostream>

using namespace std;

CCell::CCell()
{
  leftWall = rightWall = topWall = bottomWall = 0;
}// CCell()

/*
   Empty destructor because not removing nodes.
 */
CCell::~CCell(){
}// ~CCell()

bool CCell::CheckTop()
{
  if (topWall){
//    cout << "The top wall of node " << GetLabel() << " is open.\n";
    return topWall;
  }
  else{
//    cout << "The top wall of node " << GetLabel() << " is closed.\n";
    return topWall;
  }
  
}// CheckTop()


bool CCell::CheckLeft()
{
  if (leftWall){
//    cout << "The left wall of node " << GetLabel() << " is open.\n";
    return leftWall;
  }
  else{
//    cout << "The left wall of node " << GetLabel() << " is closed.\n";
    return leftWall;
  }
  
}// CheckLeft()


bool CCell::CheckRight()
{
  if (rightWall){
//    cout << "The right wall of node " << GetLabel() << " is open.\n";
    return rightWall;
  }
  else{
//    cout << "The right wall of node " << GetLabel() << " is closed.\n";
    return rightWall;
  }
  
}// CheckRight()


bool CCell::CheckBottom()
{
  if (bottomWall){
 //   cout << "The bottom wall of node " << GetLabel() << " is open.\n";
    return bottomWall;
  }
  else{
//    cout << "The bottom wall of node " << GetLabel() << " is closed.\n";
    return bottomWall;
  }
  
}// CheckBottom()

void CCell::OpenTop()
{
// Step 1: Error base case
  if (topWall)
    cout << "topWall was already open. Setting to TRUE regardless...\n";
  
  topWall = 1;
}// SetTop()


void CCell::OpenLeft()
{
// Step 1: Error base case
  if (leftWall)
    cout << "leftWall was already open. Setting to TRUE regardless...\n";
  
  leftWall = 1;
}// SetLeft()


void CCell::OpenRight()
{
// Step 1: Error base case
  if (rightWall)
    cout << "rightWall was already open. Setting to TRUE regardless...\n";
  
  rightWall = 1;
}// SetRight()


void CCell::OpenBottom()
{
// Step 1: Error base case
  if (bottomWall)
    cout << "bottomWall was already open. Setting to TRUE regardless...\n";
  
  bottomWall = 1;
}// SetBottom()


void CCell::SetLabel(int l)
{
  label = l;
}// SetLabel()


int CCell::GetLabel()
{
  return label;
}// GetLabel()