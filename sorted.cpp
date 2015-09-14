#include <iostream>
#include <random>
#include <unistd.h>
#include <vector>

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution <int> uni(0, 10000);

using namespace std;

int get_size() {

  int size;
  cout << "How many numbers would you like to sort?\n";
  cin >> size;
  return size;
}

vector <int> build_array(int size) {

  int i;
  vector <int> a;
  for (i = 0; i < size; i++)
    a.push_back(uni(rng));
  return a;
}

vector<int> merge(vector<int> &vec, const vector<int>& left, const vector<int>& right) {
  // Fill the resultant vector with sorted results from both vectors
  vector<int> result;
  unsigned left_it = 0, right_it = 0;

  while (left_it < left.size() && right_it < right.size()) {
    // If the left value is smaller than the right it goes next
    // into the resultant vector
    if (left[left_it] < right[right_it]) {
      result.push_back(left[left_it]);
      left_it++;
    }
    else {
      result.push_back(right[right_it]);
      right_it++;
    }
  }

  // Push the remaining data from both vectors onto the resultant
  while (left_it < left.size()) {
    result.push_back(left[left_it]);
    left_it++;
  }

  while (right_it < right.size()) {
    result.push_back(right[right_it]);
    right_it++;
  }
  //show merge process..
    int i;
    for (i = 0; i < result.size(); i++) {                                
      cout << result[i] << " ";
    }
    // break each line for display purposes..
    cout << "***********" << endl; 

  //take a source vector and parse the result to it. then return it.  
  vec = result;       
  return vec;
}

vector<int> merge_sort(vector<int>& vec) {
  // Termination condition: List is completely sorted if it
  // only contains a single element.
  if (vec.size() == 1)
    return vec;

  // Determine the location of the middle element in the vector
  std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

  vector<int> left(vec.begin(), middle);
  vector<int> right(middle, vec.end());

  // Perform a merge sort on the two smaller vectors
  left = merge_sort(left);
  right = merge_sort(right);

  return merge(vec, left, right);
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
  int i;
  for (i = 0; i < a.size(); i++)
    cout << a[i] << ' ';
}

int main() {

  vector <int> a = build_array(get_size());
  merge_sort(a);
  // a = insertion_sort(a);
  // print_array(a);

  return 0;
}
