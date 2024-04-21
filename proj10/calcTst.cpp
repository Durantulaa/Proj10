#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argv[1]);
//everything written in main function 
 delete C;
 return 0;
}
