#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

#include "hash.h"
using namespace std;

int main() {
  // use c++ pointers
  // use std::hash<type>{}(thing im hashing)
  // use integers for now, this ^ does not do strings
  Hash h;
  // h.insert("Remy", "Puppy");
  // h.insert("Ollie", "Doggy");
  const int num_elts = 1000000;
  for (int i = 0; i < num_elts; i++) {
    string first = to_string(i);
    string last = to_string(i + 1);
    h.insert(first, last);
  }
  for (int i = 0; i < num_elts; i += 29) {
    string first = to_string(i);
    string last = to_string(i + 1);
    assert(h.get(first) == last);
  }
  // h.get_tab();
  //     h["Remy"];
  //   cout << "Remy " << h.get("empty") << endl;
  return 0;
  // destructor gets called after return automatically
}