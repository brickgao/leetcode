#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = SZ(height) - 1;
        int result = (r - l) * min(height[l], height[r]);
        while (l < r) {
            if (height[l] > height[r]) {
                int tmp = (r - l) * height[r];
                result = max(result, tmp);
                r -= 1;
            }
            else {
                int tmp = (r - l) * height[l];
                result = max(result, tmp);
                l += 1;
            }
        }
        return result;
    }
};


int main() {
    Solution solution = Solution();
    vector <int> v;
    v.push_back(5), v.push_back(2), v.push_back(12);
    v.push_back(1), v.push_back(5), v.push_back(3);
    v.push_back(4), v.push_back(11), v.push_back(9);
    v.push_back(4);
    cout << solution.maxArea(v) << endl;
    return 0;
}
