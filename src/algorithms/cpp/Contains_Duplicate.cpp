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
    bool containsDuplicate(vector<int>& nums) {
        map <int, bool> mp;
        for (auto &num: nums) {
            if (mp.count(num) >= 1)
                return true;
            else
                mp[num] = true;
        }
        return false;
    }
};

int main() {
    return 0;
}
