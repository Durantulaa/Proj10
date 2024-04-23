#include "calc.h"
#include <iostream>

using namespace std; 

int main() {
  // Test CheckTokens with valid input
  Calc calculator1("((A+B)*(C-D))"); 
  Calc calculator2("(A-B)*C"); 
  Calc calculator3("((B*A)-G)"); 
  Calc calculator4("((V-R)+A)"); 
  Calc calculator5("(B-A)*(B*T)");

  if (!calculator1.CheckTokens()) {
    cout << "CheckTokens test failed\n";
  } else {
    cout << "CheckTokens test passed\n";
  }

  if (!calculator1.CheckParens()) {
    cout << "CheckParens test failed\n";
  } else {
    cout << "CheckParens test passed\n";
  }

  calculator1.Parse();
  calculator1.DisplayInFix();
  calculator2.Parse();
  calculator2.DisplayInFix();
  calculator3.Parse();
  calculator3.DisplayInFix();
  calculator4.Parse();
  calculator4.DisplayInFix();
  calculator5.Parse();
  calculator5.DisplayInFix();

  return 0;
}