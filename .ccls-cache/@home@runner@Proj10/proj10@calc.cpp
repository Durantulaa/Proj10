/*
Name: Steph Borla, 
Class: CPSC 122, Section 1
Date Submitted: February 25, 2021
Assignment: N/A 
Description: Part 1 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include "calc.h"
#include <cstring>
#include <iostream>

using namespace std;

// Write functions in this order.  Constructor and destructor will be built as
// the functions it invokes are written

Calc::Calc(char *argvIn) {
  stk = new Stack();
  valueTbl = new int[26];
  valueIdx = 0;
  int len = strlen(argvIn);
  inFix = new char[len];
}

Calc::~Calc() {
  delete[] inFix;
  delete[] valueTbl;
  delete stk;
}

bool Calc::CheckTokens() {
  for (int i = 0; inFix[i] != '\0'; i++) {
    if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' ||
        inFix[i] == '(' || inFix[i] == ')' ||
        ((isalpha(inFix[i]) && isupper(inFix[i]))) || isdigit(inFix[i]))
      return true;
  }

  cout << "Invalid Input\n";
  return false;
}

void Calc::MakeValueTbl() {
for(int i =0; i < 26; i++)
  valueTbl[i] = 0; 
}

int FindLast(int cur){
  int last = cur;
  while(isdigit())
  {
    
  }
}

void Calc::Parse() {

MakeValueTbl();
  int len = strlen(inFix);
for (int i = 0; i < len; i++){
  if (isalpha(inFix[i])){
    //find the last digit in the current digit string 
    int lastIndex = FindLast(i);
    //convert the digit string to an int
    int num = 0;
    for (int j = i; j <= lastIndex; j++){
      num = num * 10 + (inFix[j] - '0');
    }
    valueTbl[valueIdx] = num;
    valueIdx++;
    i = lastIndex;
  }
  }
}
  
}

bool Calc::CheckParens() {
  int ct;

  for (int i = 0; inFix[i] != '\0'; i++) {
    if (inFix[i] == '(')
      ct++;
    else if (inFix[i] == ')')
      ct--;
    return true;
  }

  if (ct != 0) {
    cout << "invalid input\n";
    return false;
  }
  return ct;
}

void Calc::DisplayInFix() { cout << "InFix: " << inFix << endl; }