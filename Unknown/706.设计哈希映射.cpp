/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
#include "head.h"
// @lc code=start
class MyHashMap {
 private:
  using PII = pair<int, int>;
  const double hash_b = 0.7;
  int hash_size, num_cnt;
  vector<PII> hash_table;
  vector<bool> is_have;
  static vector<int> hash_size_table;

 private:
  inline int get_next_hash_size() {
    int res = hash_size;
    for (auto&& it : hash_size_table)
      if (it > res) {
        res = it;
        break;
      }
    return res;
  }
  inline int check(int hash_num, const int key) {
    while (is_have[hash_num] && hash_table[hash_num].first != key)
      hash_num = (++hash_num) % hash_size;
    return hash_num;
  }
  inline int get_hash(const int num) { return num % hash_size; }
  void check_all() {
    auto b = num_cnt * 1.0 / hash_size;
    if (b <= hash_b) return;
    int new_hash_size = get_next_hash_size();
    if (new_hash_size == hash_size) return;
    vector<PII> old_hash_table(new_hash_size);
    vector<bool> old_is_have(new_hash_size);
    hash_table.swap(old_hash_table);
    is_have.swap(old_is_have);
    num_cnt = 0;
    swap(hash_size, new_hash_size);
    for (int i = 0; i < new_hash_size; i++) {
      if (old_is_have[i]) {
        auto&& [Ky, Val] = old_hash_table[i];
        put(Ky, Val);
      }
    }
  }

 public:
  /** Initialize your data structure here. */
  MyHashMap()
      : num_cnt(0), hash_size(11), hash_table(hash_size), is_have(hash_size) {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    auto hash_num = check(get_hash(key), key);
    auto&& [Ky, Val] = hash_table[hash_num];
    Val = value;
    Ky = key;
    if (!is_have[hash_num]) {
      num_cnt++;
      is_have[hash_num] = true;
      check_all();
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    auto hash_num = check(get_hash(key), key);
    return is_have[hash_num] ? hash_table[hash_num].second : -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    auto hash_num = check(get_hash(key), key);
    is_have[hash_num] = false;
  }
};
vector<int> MyHashMap::hash_size_table = {11,    101,    1009,
                                          10007, 100003, 1000003};

// @lc code=end
