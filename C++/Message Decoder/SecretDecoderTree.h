/* SecretDecoderTree.h
 * 
 * Author: Kevin Ip
 * 
 */

#ifndef SECRETDECODER_H
#define SECRETDECODER_H

#include <iostream>
#include <sstream>
#include "DecoderTree.h"
#include "BTNode.h"

using namespace std;

class CSecretDecoderTree : public CDecoderTree
{
public:
    void BuildTree(string alphabet, string mutations);
    string Encode(string raw);
    string Decode(string code);
    string GetCode(string letter);
    void GetCode(BTNode* t, int value, string& result);
    void RotateLeft(int nodeLabel);
    void RotateRight(int nodeLabel);
    string InorderPrint();
    string InorderPrintLeafLetters();
    string InorderPrintLeafLetters(BTNode* t);
    BTNode* GetNode(int label);
    BTNode* root;
 
private:
    //BTNode* root;

    void InorderPrint(BTNode* t, ostringstream& os);
    void InorderPrintLeafLetters(BTNode* t, string& result);
}; //class CSecretDecoderTree


#endif
