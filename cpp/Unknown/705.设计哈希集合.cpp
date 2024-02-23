/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */
#include "head.h"
// @lc code=start
class MyHashSet {
 private:
  template <class Key>
  struct Base_Node {
    Key data;
    Base_Node* next;
    Base_Node(const Key& x) : data(x), next(nullptr) {}
  };

 private:
  const static vector<int> all_table_size;
  const static double hash_b;
  int num_cnt;

 private:
  using T = Base_Node<int>;
  int table_size;
  vector<T*> table;
  inline int get_hash(const int& key) { return key % table_size; }
  inline int get_next_size() {
    for (auto& it : all_table_size)
      if (it > table_size) return it;
    return table_size;
  }
  void check_rehash() {
    if (num_cnt / table_size <= hash_b) return;
    int new_size = get_next_size();
    if (new_size == table_size) return;
    vector<T*> old_table(new_size, nullptr);
    old_table.swap(table);
    num_cnt = 0;
    swap(table_size, new_size);
    for (auto head : old_table) {
      auto temp = head;
      while (head) {
        add(head->data);
        temp = head;
        head = head->next;
        delete temp;
      }
    }
    return;
  }
  pair<T*, T*> get_node(T* head, const int key) {
    if (head == nullptr) return {nullptr, nullptr};
    if (head->data == key) return {nullptr, head};
    while (head->next && head->next->data != key) head = head->next;
    return {head, head->next};
  }

 public:
  /** Initialize your data structure here. */
  MyHashSet() : table_size(11), table(table_size, nullptr), num_cnt(0) {}

  void add(int key) {
    int hash_num = get_hash(key);
    auto&& head = table[hash_num];
    auto&& [parent, child] = get_node(head, key);
    if (child == nullptr) {
      if (parent == nullptr) {
        ++num_cnt;
        head = new T(key);
        check_rehash();
      } else {
        parent->next = new T(key);
      }
    }
  }

  void remove(int key) {
    int hash_num = get_hash(key);
    auto&& head = table[hash_num];
    auto&& [parent, child] = get_node(head, key);
    if (child == nullptr) {
      return;
    }
    auto temp = child->next;
    if (parent == nullptr) {
      head = temp;
    } else {
      parent->next = temp;
    }
    delete child;
    return;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int hash_num = get_hash(key);
    auto&& head = table[hash_num];
    auto&& [parent, child] = get_node(head, key);
    return child != nullptr;
  }
};
const vector<int> MyHashSet::all_table_size = {11,    101,    1009,
                                               10007, 100003, 1000003};
const double MyHashSet::hash_b = 0.7;

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
