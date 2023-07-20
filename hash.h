#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

class Hash {  // The class
 private:
  // number of buckets in hash table
  uint64_t num_buckets;
  uint64_t num_elts;
  static const float saturation_threshold = 0.7;
  static const uint32_t bucket_length_threshold = 3;
  struct Entry {
    string f_name;
    string l_name;
    Entry* next;
  };
  struct Bucket {
    uint32_t length;
    Entry* first;
    Bucket() : length(0), first(nullptr) {}
  };

  // hash_table is a pointer to an array of buckets
  Bucket* hash_table;

 public:
  // constructor
  Hash(uint64_t num_buckets = 13);

  // DESTRUCTOR

  // empty

  uint64_t get_num_buckets() const;
  uint64_t get_num_elts() const;

  // hash function
  uint64_t hash(string key);

  void get_tab();

  void insert_in_bucket(Bucket* b, Entry* new_elt);

  bool resize_check(const Bucket* curr_bucket) const;
  void resize();

  // these all need to be const time(below)
  // insert
  void insert(string first, string last);
  // get
  string get(string key);
  // erase
};
