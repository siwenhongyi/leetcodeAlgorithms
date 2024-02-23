/*
 * @lc app=leetcode.cn id=1797 lang=cpp
 *
 * [1797] 设计一个验证系统
 */

#include "head.h"
using namespace std;

// @lc code=start
class AuthenticationManager {
  int ttl;
  unordered_map<string, int> rd;

 public:
  AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

  void generate(string tokenId, int currentTime) {
    rd[tokenId] = currentTime + ttl;
  }

  void renew(string tokenId, int currentTime) {
    auto&& it = rd.find(tokenId);
    if (it == rd.end()) return;
    if (it->second <= currentTime) return;
    it->second = currentTime + ttl;
  }

  int countUnexpiredTokens(int currentTime) {
    int res = 0;
    for (auto&& [_, dt] : rd) res += dt > currentTime;
    return res;
  }
};
// @lc code=end
