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
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while (i < SZ(nums)) {
            if (i > 0 && nums[i] == nums[i - 1])
                nums.erase(nums.begin() + i);
            else
                i += 1;
        }
        return SZ(nums);
    }
};


int main() {
    return 0;
}
