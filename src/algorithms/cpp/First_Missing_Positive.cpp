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
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < SZ(nums)) {
            if (nums[i] < 0 || nums[i] == i + 1 || nums[i] > SZ(nums)) {
                ++ i;
            }
            else if (nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
            else
                ++ i;
        }
        i = 0;
        while (i < SZ(nums) && nums[i] == i + 1)
            ++ i;
        return i + 1;
    }
};

int main() {
    return 0;
}
