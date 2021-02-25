/*
* @lc app=leetcode.cn id=面试题 16.25 lang=cpp
*
* [面试题 16.25] LRU 缓存
*/

#include"head.h"
using namespace std;
// @lc code=start
struct cache
{
    int key, value;
    cache* next, * pre;
    cache(int x, int y) :key(x), value(y) { next = pre = nullptr; }
};

class LRUCache {
public:
    int size_t, size_n;
    cache* rh, * ta;
    map<int, cache*> book;
    LRUCache(int capacity) {
        size_t = capacity;
        size_n = 0;
        rh = ta = nullptr;
    }
    int get(int key) {
        auto res = book.find(key) == book.end() ? nullptr : book[key];
        if (!res)
            return -1;
        int ret = res->value;
        if (res != rh) {
            if (res == ta) {
                ta = ta->pre;
                res->pre->next = res->next;
                res->next = rh;
                rh->pre = res;
                res->pre = nullptr;
            }
            else {
                res->pre->next = res->next;
                res->next->pre = res->pre;
                res->next = rh;
                rh->pre = res;
                res->pre = nullptr;
            }
            rh = res;
        }
        return ret;
    }
    void put(int key, int value) {
        if (!size_n) {
            rh = new cache(key, value);
            ta = rh;
            size_n++;
            book[key] = rh;
            return;
        }
        auto f = book.find(key) == book.end() ? nullptr : book[key];
        if (!f) {
            rh->pre = new cache(key, value);
            book[key] = rh->pre;
            rh->pre->next = rh;
            rh = rh->pre;
            if (size_n == size_t) {
                f = ta;
                ta = ta->pre;
                ta->next = nullptr;
                book.erase(f->key);
                delete f;
            }
            else
                size_n++;
        }
        else {
            f->value = value;
            if (f == rh);
            else if(f==ta){
                ta = ta->pre;
                f->pre->next = nullptr;
                f->pre = nullptr;
                f->next = rh;
                rh->pre = f;
            }
            else {
                f->pre->next = f->next;
                f->next->pre = f->pre;
                f->pre = nullptr;
                f->next = rh;
                rh->pre = f;
            }
            rh = f;
        }
    }
};


// @lc code=end

