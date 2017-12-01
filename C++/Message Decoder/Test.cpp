/* Test.cpp
 * 
 * Author: Kevin Ip
 * 
 */

#include "Test.h"
#include "SecretDecoderTree.h"
#include "BTNode.h"
#include "DecoderTree.h"
#include <iostream>
#include <sstream>

using namespace std;

void CTest::RunTests(){
  cout << "Note to Instructor: Many of the safekeeping practices were already "
   << "implemented in SecretDecoderTree. The file has \"graceful\" "
   << "continuation of certain cases, particularly with unacceptable input. "
  << "Please note the output when running special cases!" << endl << endl;
  
  testConstruct();
  testRotate();
  testRetrieve();
}// RunTests()


void CTest::testConstruct(){
  cout << "..." << endl
    << "Moving onto test: Construct a working tree.\n";
  
  if (constructSmallTree())
    cout << "Successful construction of a basic tree!\n";
  else
    cout << "Unsuccessful construction of a basic tree. You should be ashamed.\n";
  
  cout << "..." << endl
    << "Moving onto test: Construct an illegal tree...\n";
  
  if (constructIllegalTree())
    cout << "Successful breakage from construction of illegal tree!\n";
  else
    cout << "Unsuccessful breakage from construction of illegal tree. Repent immediately.\n";
  
}// testBase()



/* constructSmallTree()
 
   Conditions:
     1) Success dependent on cout statements,
 
 */
bool CTest::constructSmallTree(){
  int tick = 0;
  
  
  cout << "\nBegin single left mutate...\n";
  CSecretDecoderTree s;
  s.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "025L");
  
  cout << "Output for Tree s: \n";
  s.InorderPrint();
  s.InorderPrintLeafLetters();

  
  cout << "\nBegin single right mutate...\n";
  CSecretDecoderTree s2;
  s2.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "065R");
  
  cout << "Output for Tree s: \n";
  s2.InorderPrint();
  s2.InorderPrintLeafLetters();
  
  
  cout << "\nBegin combination mutate...\n";
  CSecretDecoderTree s3;
  s3.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "025L065R");
  
  cout << "Output for Tree s: \n";
  s3.InorderPrint();
  s3.InorderPrintLeafLetters();
  
  return 1;
}// constructSmallTree()


bool CTest::constructIllegalTree(){
  /*
    Note from Professor: input will always be 30 chars, but mutation may be invalid.
   */
   
   
  int tick = 0;
  
  CSecretDecoderTree t;
  t.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "065j029L");
  
  cout << "Output for Tree t: \n";
  t.InorderPrint();
  t.InorderPrintLeafLetters();
  
  return 1;
}// constructIllegalTree()


void CTest::testRotate(){
  cout << "..." << endl
    << "Moving onto test: Do a left, then right rotation on same node...\n";
  
  if (rotateLR())
    cout << "Successful left-right rotation!\n";
  else
    cout << "Unsuccessful left-right rotation. Please go home.\n";
  
  cout << "..." << endl
  << "Moving onto test: Do a right, then left rotation on same node...\n";
  
  if (rotateRL())
    cout << "Successful right-left rotation!\n";
  else
    cout << "Unsuccessful right-left rotation. Please go home.\n";
  
}// testRotate()



bool CTest::rotateLR(){
  cout << "The following cases intentionally break the prefix rule."
    << " They are not valid rotations.\n";
  cout << "Begin LR mutate...\n";
  CSecretDecoderTree s;
  s.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "165L165R");
  
  cout << "Output for Tree s: \n";
  s.InorderPrint();
  s.InorderPrintLeafLetters();
  
  return 1;
}// rotateLR()


bool CTest::rotateRL(){
  cout << "The following cases intentionally break the prefix rule."
    << " They are not valid rotations.\n";
  cout << "Begin RL mutate...\n";
  CSecretDecoderTree s2;
  s2.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "205R205L");
  
  cout << "Output for Tree s: \n";
  s2.InorderPrint();
  s2.InorderPrintLeafLetters();
  return 1;
  
}// rotateRL()

void CTest::testRetrieve(){
  cout << "..." << endl
    << "Moving onto test: Get labels...\n";
  
  if (retrieveIllegal())
    cout << "Successful label retrieval!\n";
  else
    cout << "Unsuccessful label retrieval. You're a terrible AVL tree gardener.\n";
}// testRetrieve()


bool CTest::retrieveIllegal(){
  CSecretDecoderTree s;
  s.BuildTree("abcdefghijklmnopqrstuvwxyz.!? ", "085R");
  
  cout << "The labels for a and ' ' are " << s.GetCode("a")
    << " and " << s.GetCode(" ") << endl;
  
  
  cout << "An illegal extraction for '[' will result in the following error messages: \n";
  s.GetCode("[");
  
  return 1;
}// retrieveIllegal()