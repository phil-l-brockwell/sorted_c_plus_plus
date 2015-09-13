#include <iostream>
#include <random>
#include <unistd.h>
#include <vector>

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution <int> uni(0, 10000);

using namespace std;

// string get_name() {
//   string name;
//   cout << "Welcome to the "
// }

int get_size() {

  int size;
  cout << "How many numbers would you like to sort?\n";
  cout << "Type a number and hit Enter\n";
  cin >> size;
  return size;
}

vector <int> build_array(int size) {

  int i;
  vector <int> a1;
  for (i = 0; i < size; i++) {
    a1.push_back(uni(rng));
  }
  return a1;
}

vector <int> insertion_sort(vector <int> a) {

  int i, j, temp;
  for (i = 0; i < a.size(); i++) {
    for (j = i; j >= 1; j--) {
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j-1];
        a[j - 1] = temp;
      }
      else
        break;
    }
  }
  return a;
}

void print_array(vector <int> a) {
  int k;
  for (k = 0; k < a.size(); k++) {
    cout << a[k] << ' ';
    usleep(1000);
  }
}

int main() {

  vector <int> a = build_array(get_size());
  a = insertion_sort(a);
  print_array(a);

  return 0;
}
