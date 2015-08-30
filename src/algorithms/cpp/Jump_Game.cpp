#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
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
    bool canJump(vector <int>& nums) {
        int reach = 0;
        for (int i = 0; i < SZ(nums); ++ i) {
            if (i <= reach && i + nums[i] > reach)
                reach = i + nums[i];
        }
        return reach >= SZ(nums) - 1;
    }
};

int main() {
    vector <int> input;
    input.push_back(0), input.push_back(1);
    Solution solution = Solution();
    cout << solution.canJump(input) << endl;
    return 0;
}
