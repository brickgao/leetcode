#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
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
    int findDuplicate(vector<int>& nums) {
        int fast = SZ(nums) - 1, slow = SZ(nums) - 1;
        while (true) {
            fast = nums[nums[fast] - 1] - 1;
            slow = nums[slow] - 1;
            if (fast == slow)   break;
        }
        slow = SZ(nums) - 1;
        while (slow != fast) {
            fast = nums[fast] - 1;
            slow = nums[slow] - 1;
        }
        return slow + 1;
    }
};

int main() {
    return 0;
}
