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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set <int> s;
        for (int i = 0; i < SZ(nums); ++ i) {
            if (SZ(s) <= k) {
                if (s.count(nums[i]) > 0)   return true;
                else                        s.insert(nums[i]);
            }
            else {
                s.erase(nums[i - k - 1]);
                if (s.count(nums[i]) > 0)   return true;
                else                        s.insert(nums[i]);
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
