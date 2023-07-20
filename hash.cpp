#include "hash.h"

#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

// Constructor

// CHECK THAT NUM_BUCKETS IS NOT A DUMB NUMBER

Hash::Hash(uint64_t num_buckets) : num_buckets(num_buckets), num_elts(0) {
  // hash table points to a list of bucket pointers
  // () initializes everything as nullptrs
  hash_table = new Bucket[num_buckets]();
}

uint64_t Hash::get_num_buckets() const {
  return num_buckets;
}

uint64_t Hash::get_num_elts() const {
  return num_elts;
}

// hashes values to put into appropriate bucket
uint64_t Hash::hash(string key) {
  // for non-string, use std::hash()
  uint64_t hash_val = 0;
  for (size_t i = 0; i < key.length(); i++) {
    // convert key elemtents to integers
    hash_val += (uint64_t) key[i];
  }
  uint64_t index = hash_val % num_buckets;
  return index;
  // MAKE BETTER LATER
}

// prints the hash table and the first value in each bucket
void Hash::get_tab() {
  for (int i = 0; i < num_buckets; i++) {
    Entry* Ptr = hash_table[i].first;
    if (Ptr != nullptr) {
      cout << "-------------------" << endl;
      cout << "index = " << i << endl;
      while (Ptr != nullptr) {
        cout << Ptr->f_name << " " << Ptr->l_name << endl;
        Ptr = Ptr->next;
      }
      cout << "Number of items in bucket = " << hash_table[i].length << endl;
    }
  }
}

void Hash::insert_in_bucket(Bucket* b, Entry* new_elt) {
  new_elt->next = b->first;
  b->first = new_elt;
  b->length += 1;
}

bool Hash::resize_check(const Bucket* curr_bucket) const {
  float curr_thresh = static_cast<float>(num_elts) / num_buckets;
  // cout << curr_thresh << "   " << curr_bucket->length << endl;
  return (curr_thresh >= saturation_threshold &&
          curr_bucket->length >= bucket_length_threshold);
}

void Hash::resize() {
  // to be more optimal, use prime list from abseil flat hash map
  cout << num_buckets << endl;
  uint64_t num_buckets_old = num_buckets;
  num_buckets = 2 * num_buckets - 1;
  Bucket* old_hash = hash_table;
  hash_table = new Bucket[num_buckets]();
  for (uint64_t i = 0; i < num_buckets_old; i++) {
    Entry* Ptr = old_hash[i].first;
    while (Ptr != nullptr) {
      uint64_t bucket_index = hash(Ptr->f_name);
      Entry* curr_ptr = Ptr;
      Ptr = Ptr->next;
      insert_in_bucket(&hash_table[bucket_index], curr_ptr);
    }
  }
  delete[] old_hash;
}

// inserts new key value pair into table
void Hash::insert(string first, string last) {
  int index = hash(first);
  // creating a linked list for names that hash to the same value
  Entry* n = new Entry;
  n->f_name = first;
  n->l_name = last;
  insert_in_bucket(&hash_table[index], n);
  num_elts += 1;
  if (resize_check(&hash_table[index])) {
    resize();
  }
}

// enter key and value is returned
string Hash::get(string key) {
  int index = hash(key);
  Entry* Ptr = hash_table[index].first;
  while (Ptr != nullptr) {
    if (Ptr->f_name != key) {
      Ptr = Ptr->next;
    }
    else {
      return Ptr->l_name;
    }
  }
  // make better later
  return "";
}