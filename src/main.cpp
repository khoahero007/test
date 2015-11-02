#include <iostream>
#include "test.hpp"

using namespace std;

int main () {
  ConcCell *test1,*test2;
  test1 = new INVCell();
  test2 = new NANDCell();
  cout << test1->get_type() << test2->get_type() << endl;
  return 0;
}
