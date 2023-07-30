#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

class Hash {
 private:
  // number of buckets in hash table
  // can be a very large amount, so we don't limit to just integers
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
  // CONSTRUCTOR
  Hash(uint64_t num_buckets = 13);

  // DESTRUCTOR
  ~Hash();

  // EMPTY
  bool empty();

  // RETURNS THE NUMBER OF BUCKETS
  uint64_t get_num_buckets() const;

  // RETURNS THE NUMBER OF ELEMENTS
  uint64_t get_num_elts() const;

  // HASH FUNCTION
  uint64_t hash(string key);

  // PRINTS TABLE
  void get_tab();

  // helper to resize and insert
  void insert_in_bucket(Bucket* b, Entry* new_elt);

  // helper to resize
  bool resize_check(const Bucket* curr_bucket) const;

  // RESIZE
  void resize();

  // INSERT
  void insert(string first, string last);

  // GET
  string get(string key);

  // ERASE
  void erase();
};
