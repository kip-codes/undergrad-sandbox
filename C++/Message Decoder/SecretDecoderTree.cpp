/* SecretDecoderTree.cpp
 * 
 * Author: Kevin Ip
 * 
 */

#include <iostream>
#include <sstream>
#include <queue>
#include "SecretDecoderTree.h"
#include "BTNode.h"

using namespace std;

string alphabetCopy;
BTNode* shelfOne[32];
BTNode* shelfTwo[16];
BTNode* shelfThree[8];
BTNode* shelfFour[4];
BTNode* shelfFive[2];
BTNode* shelfSix[1];

/* BuildTree()
 * 
 * Parameters:
 *   1) string alphabet - list of 30 unique characters within western ASCII range.
 *   2) string mutations - commands for mutation methodology,
 *     with an m_label and a direction to mutate.
 */
void CSecretDecoderTree::BuildTree(string alphabet, string mutations)
{
// Step 0: Copy alphabet globally for search usage
  alphabetCopy = alphabet;

//  queue<BTNode*> shelf;
//  string s;

/* Step 1.1: Construct nodes
 * Conditions:
 *   1) @param alphabet must be exactly 30 characters.
 */
  for (int i = 0; i < alphabet.length(); i++){
    string s;
    BTNode* leaf;
    if (i < 28) leaf = new BTNode((i+1)*10);
    else leaf = new BTNode((i+2)*10);

    s = alphabet[i];
    leaf->SetChar(s);

//FIXME
//cout << "shelfOne label " << leaf->m_label << endl;
//    shelf.push(leaf);

    shelfOne[i] = leaf;
  }//for
/* END Step 1.1 */

/* Step 1.2: Link leaves to parent
 * Conditions:
 *   1) Leaves m_label = <10-280> will have a parent for each pair.
 *   2) Leaves 300 and 310 will have its parent separate from the rest
 *     during initial linking stage.
 */

// Step 1.2.1: Link first 28 leaves at L = 5
  for (int i = 0, j = 0; i < alphabet.length()-2; i += 2, j++){
    BTNode* parent = new BTNode;
    
    BTNode* L = shelfOne[i];
    parent->m_left = L;
    L->m_parent = parent;
//    shelf.pop();

    BTNode* R = shelfOne[i+1];
    parent->m_right = R;
    R->m_parent = parent;
//    shelf.pop();

    parent->m_label = ((L->m_label + R->m_label)/2);

//FIXME
//cout << "shelfTwo label " << parent->m_label << endl;
//    shelf.push(parent);
    shelfTwo[j] = parent;
  }//for
// END Step 1.2.1

//Step 1.2.1a: Move n29 and n30 to the back of the queue.
//  BTNode* temp = shelf.front();
//  shelf.push(temp);
//  temp = shelf.front();
//  shelf.push(temp)
   shelfTwo[14] = shelfOne[28];
   shelfTwo[15] = shelfOne[29];
// END Step 1.2.1a

// Step 1.2.2: Link all leaves at L > 5, starting at L = 4
// Condition:
//   Assume n29 and n30 have not been linked yet (i.e., they contain m_char)
//   Assume n29 and n30 are at the back of the queue
  for (int i = 0, j = 0; i < 16; i+= 2, j++) {
    BTNode* parent = new BTNode;
    
    BTNode* L = shelfTwo[i];
    parent->m_left = L;
    L->m_parent = parent;
//    shelf.pop();

    BTNode* R = shelfTwo[i+1];
    parent->m_right = R;
    R->m_parent = parent;
//    shelf.pop();
    
    parent->m_label = ((L->m_label + R->m_label)/2);

//FIXME
//cout << "shelfThree label " << parent->m_label << endl;
//    shelf.push(parent);
    shelfThree[j] = parent;
  }//while

  for (int i = 0, j = 0; i < 8; i += 2, j++) {
    BTNode* parent = new BTNode;

    BTNode* L = shelfThree[i];
    parent->m_left = L;
    L->m_parent = parent;

    BTNode* R = shelfThree[i+1];
    parent->m_right = R;
    R->m_parent = parent;

   parent->m_label = ((L->m_label + R->m_label)/2);

//cout << "shelfFour label " << parent->m_label << endl;
   shelfFour[j] = parent;
  }//for

  for (int i = 0, j = 0; i < 4; i += 2, j++) {
    BTNode* parent = new BTNode;

    BTNode* L = shelfFour[i];
    parent->m_left = L;
    L->m_parent = parent;

    BTNode* R = shelfFour[i+1];
    parent->m_right = R;
    R->m_parent = parent;

   parent->m_label = ((L->m_label + R->m_label)/2);

//cout << "shelfFour label " << parent->m_label << endl;
   shelfFive[j] = parent;
  }//for

  for (int i = 0, j = 0; i < 2; i += 2, j++) {
    BTNode* parent = new BTNode;

    BTNode* L = shelfFive[i];
    parent->m_left = L;
    L->m_parent = parent;

    BTNode* R = shelfFive[i+1];
    parent->m_right = R;
    R->m_parent = parent;

   parent->m_label = ((L->m_label + R->m_label)/2);

//cout << "shelfFive label " << parent->m_label << endl;
   shelfSix[j] = parent;
  }//for

// STEP 1.2.2a: Establish root.
  root = shelfSix[0];

// END Step 1.2.2

/* Step 2.1: Extract data for mutation orders 
 * Conditions:
 *   1) Mutation string may be invalid. Handle "gracefully."
 */
  if (mutations.size() % 4 != 0)
    cout << "Warning! Incomplete orders. "
        << "Mutations extraction method will be unstable.\n";

  string mutationsCopy = mutations;
  int commandNodeInt = 0;

  for (int i = 0; i < mutationsCopy.size(); i += 4) {
    string command = mutationsCopy.substr(i, 4);
    string commandNode = command.substr(0, 3);

//FIXME
//cout << "before stream declaration\n";    
//cout << "mutation is " << mutations << endl;
//cout << "command substring is " << command << endl;
//cout << "command[3] is " << command[3] << endl;
//cout << "commandNode substring is " << commandNode << endl;

// Convert string [0,2] into int
  stringstream ss(commandNode);
  ss >> commandNodeInt;

//cout << "commandNodeInt is " << commandNodeInt << ".\n";
//cout << "before rotates\n";

    if (command[3] == 'L')
      RotateLeft(commandNodeInt);

    else if (command[3] == 'R')
      RotateRight(commandNodeInt);
    else { // value is not L, or R
      cout << "The extracted chunk was invalid. These are its contents:" << endl
           << "commandNode = " << commandNode << endl
           << "Left/Right operation (expected L or R): " << command[3] << endl;
    }//else

  }//for

}// BuildTree()


/*
 The following information has been redacted.
 ....
*/