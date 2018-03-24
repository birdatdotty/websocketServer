#include <iostream>
#include <string>

#include <cstring>


using namespace std;

class Int: public string {
  
  friend ostream& operator<< (ostream &os, const Int& ob)
  {
//    return os << ob.i;
    return os << ob.i;
  };
   
  private:
    int i;
  
  public:
  Int(int a)
  :i(a)
  {};
  
  operator int()
  {
    return i;
  };
   
  int get_int()
  {
    return i;
  };

  operator char*() {
    string tmp("str");
//    return tmp.c_str();
    return strdup("str");
  };
   
   int get()
   {
     return i;
   }
   
};

int main () {
  cout << "Hello" << endl;
  Int a(3);
  int iA = a;
  char* sA = a;
//  string as
  cout << "a: " << a << endl;

  return 0;
}
