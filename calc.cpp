/*
Name:
Class: CPSC 122, Section 1
Date Submitted: April 23, 2024
Description: Part 1 of Calculator Assignment
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include "calc.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

Calc::Calc(const char *argvIn) {
  stk = new Stack();
  valueTbl = new int[26];
  valueIdx = 0;
  int len = strlen(argvIn);
  inFix = new char[len + 1]; // Add 1 for the null terminator
  strcpy(inFix, argvIn); 
  Parse();
  CheckTokens();
  CheckParens();
}

Calc::~Calc() {
  delete[] valueTbl;
  delete stk;
} // done

bool Calc::CheckTokens() {
  for (int i = 0; inFix[i] != '\0'; i++) {
    if (!(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' ||
          inFix[i] == '(' || inFix[i] == ')' ||
          ((isalpha(inFix[i]) && isupper(inFix[i]))) || isdigit(inFix[i]))) {
      cout << "Invalid Input\n";
      return false;
    }
  }
  return true;

  
} // done

void Calc::MakeValueTbl() {
  for (int i = 0; i < 26; i++)
    valueTbl[i] = 0;
  for (int i = 0; inFix[i] != '\0'; i++)
    {
      if (isalpha(inFix[i]) && isupper(inFix[i]))
      {
        valueTbl[valueIdx] = i;
        valueIdx++;
      }
    }
}

int Calc::FindLast(int cur) {
  int last = cur;
  // while (isdigit(inFix[last++])) {
  //   if (!isdigit(inFix[last]))
  //     return last;
  // }
  while (isdigit(inFix[last])) {
    last++;
  }
  return last - 1; // return last digit
}

void Calc::Parse() {
  MakeValueTbl();// initialize value table
  int i = 0;
  int j = 0;
  int last = 0;

  while (inFix[i] != '\0')
    {
      if (inFix[i] == '(')
      {
        inFix[j++] = inFix[i];
        stk->Push(inFix[i]);
      }
      else if (inFix[i]==')')
      {
        while (stk->Peek()!='(')
          {
            inFix[j++] = stk->Peek();
            stk->Pop();
          }
        inFix[j++] = inFix[i];
        stk->Pop();
      }
        
      else if (isdigit(inFix[i]))
      {
        last = FindLast(i);
        int num = 0;
        for (int k = i; k <= last; k++)
          {
            num = num*10 + (inFix[k]-'0');
          }
        inFix[j++] = 'A' + valueIdx;
        valueTbl[valueIdx++] = num;
        i = last;
      }
      else
      {
        inFix[j++] = inFix[i];
      }
      i++;
    }
  inFix[j] = '\0';
  for(int i = 0; i<26; i++)
    {
      cout << valueTbl[i] << " ";
    }
  }


bool Calc::CheckParens() {
  int ct = 0;
  for (int i = 0; inFix[i] != '\0'; i++) {
    if (inFix[i] == '(')
      ct++; // on left
    else if (inFix[i] == ')')
      ct--; // on right
  }

  if (ct != 0) { // if ct is unbalanced
    cout << "Unbalanced parens\n";
    return false;
  }
  return true;
}

void Calc::DisplayInFix() 
{ 
  cout << "InFix: " << inFix << endl; 
}

// make
// ./calc