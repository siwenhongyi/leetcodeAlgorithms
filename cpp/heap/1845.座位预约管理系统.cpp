//
// Created by 张明利 on 24-9-30.
//
#include<queue>
using namespace std;
class SeatManager {
    priority_queue<int,vector<int>, greater<>> p;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            p.push(i);
        }
    }

    int reserve() {
        int r = p.top();
        p.pop();
        return r;
    }

    void unreserve(int seatNumber) {
        p.push(seatNumber)
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */