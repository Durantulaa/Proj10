#include "calc.h"
#include <iostream>

using namespace std;

int main() {
  // Test CheckTokens with valid input
  Calc calculator1("A+B*(C-D)");
  cout << "Testing CheckTokens with valid input...\n";
  if (!calculator1.CheckTokens())
    cout << "CheckTokens test failed\n";
  else
    cout << "CheckTokens test passed\n";

  // Test CheckTokens with invalid input
  Calc calculator2("A&B+C");
  cout << "Testing CheckTokens with invalid input...\n";
  if (calculator2.CheckTokens())
    cout << "CheckTokens test failed\n";
  else
    cout << "CheckTokens test passed\n";

  return 0;
}
