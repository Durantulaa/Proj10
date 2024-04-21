#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

#include "calc.h"
#include <cstdlib> // for exit()

Calc::Calc(char* argvIn)
{
  // Initialize stack
  stk = new Stack();

  // Initialize value table
  valueTbl = new int[26]; // 26 positions for variables A-Z
  valueIdx = 0;

  // Check tokens
  if (!CheckTokens()) {
    cout << "Error: Invalid tokens in input expression.\n";
    //exit(EXIT_FAILURE);
  }

  // Make value table
  MakeValueTbl();

  // Parse input expression
  Parse();

  // Check parentheses
  if (!CheckParens()) {
    std::cerr << "Error: Unbalanced parentheses in input expression.\n";
    exit(EXIT_FAILURE);
  }
}

Calc::~Calc()
{
  // Deallocate dynamically allocated memory
  delete[] valueTbl;
  delete stk;
}


bool Calc::CheckTokens()
{
 return true;
}

void Calc::MakeValueTbl()
{}

void Calc::Parse()
{}

bool Calc::CheckParens()
{
 return true;
}

void Calc::DisplayInFix()
{}
