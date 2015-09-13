#include <string>
#include <iostream>
#include <array>

using namespace std;

array <string, 8> stuff_to_learn = { "Pointers",
                           "Reference (using &)",
                           "Dereferencing",
                           "Static keyword has many meaning depending on use",
                           "Three types of inheritance",
                           "Polymorphism using pointers",
                           "Pass function as arg using pointers",
                           "Friends" };

int main() {

  for ( int i = 0; i < stuff_to_learn.size(); i++ ) {
    cout << i << ' ' << stuff_to_learn[i] << '\n';
  };

  return 0;
}
