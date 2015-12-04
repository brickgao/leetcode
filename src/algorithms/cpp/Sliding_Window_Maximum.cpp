#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (SZ(nums) == 0)              return vector <int> {};
        priority_queue <int> heap;
        map <int, int> mp;
        for (int i = 0; i < k; ++ i)
            heap.push(nums[i]);
        vector <int> result = {heap.top()};
        for (int i = k; i < SZ(nums); ++ i) {
            if (heap.top() == nums[i - k]) {
                heap.pop();
                heap.push(nums[i]);
            }
            else {
                mp[nums[i - k]] += 1;
                heap.push(nums[i]);
            }
            while (mp[heap.top()] >= 1) {
                mp[heap.top()] -= 1;
                heap.pop();
            }
            result.push_back(heap.top());
        }
        return result;
    }
};

int main() {
    return 0;
}
