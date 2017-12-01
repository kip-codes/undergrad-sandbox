/* Test.h
 * 
 * Author: Kevin Ip
 * 
 * Note to Instructor: Many of the safekeeping practices were already
 * implemented in SecretDecoderTree. The file has "graceful" continuation of
 * certain cases, particularly with unacceptable input. Please note the
 * output when running special cases!
 */

#ifndef TEST_H
#define TEST_H

#include "BTNode.h"
#include "SecretDecoderTree.h"
#include <iostream>
#include <sstream>

class CTest : public CSecretDecoderTree
{
public:
  /* Some tests were already implemented into SecretDecoderTree */

  void RunTests();

private:
  void testConstruct(); // calls a construct
  
  void testRotate(); // tests for undo rotations
  
  void testRetrieve(); // tests encoding and decoding
  
  bool constructSmallTree(); // tests for construction of 3-level tree
  
  bool constructIllegalTree(); // tests for illegal construction
  
  bool rotateLR(); //tests to see if rotation is done properly
  bool rotateRL();
  // Check:
  //   1) Rotate parent with one child
  //   2) Rotate parent with two children
  //   3) Illegal rotate with leaves (contains a char)
  
  
  bool retrieveIllegal(); // tests for illegal encoding/decoding
  // Check:
  //   1) Unknown letter in encoding string
  //   2) Unknown node access when decoding
  //   3) Hanging traversals
  
};

#endif