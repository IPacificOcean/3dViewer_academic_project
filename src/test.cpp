
#include <iostream>
using namespace std;

/* local variable is same as a member's name */
class Test {
 private:
  int age;
  char* sex;

 public:
  void setX(int age) {
    // The 'this' pointer is used to retrieve the object's x
    // hidden by the local variable 'x'
    this->age = age;
  }
  void print() { cout << "x = " << age << endl; }
};

typedef struct Test_c {
  int x;
} t_test;

void _setX(t_test* _this, int x) { _this->x = x; }

int main() {
  int age = 20;
  int t = 0;

  Test obj;
  obj.setX(age);

  t_test test_c;
  _setX(&test_c, age);

  return 0;
}
