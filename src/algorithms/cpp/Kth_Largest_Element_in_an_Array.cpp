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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, std::vector<int>, std::greater<int>> q;
        for (auto &num: nums) {
            if (SZ(q) < k)
                q.push(num);
            else {
                if (q.top() < num) {
                    q.pop();
                    q.push(num);
                }
            }
        }
        return q.top();
    }
};

int main() {
    vector <int> nums = {1, 2};
    Solution solution;
    cout << solution.findKthLargest(nums, 2) << endl;
    return 0;
}
