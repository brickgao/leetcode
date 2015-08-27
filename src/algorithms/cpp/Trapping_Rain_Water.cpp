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
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> from_left, from_right;
        for (int i = 0; i < SZ(height); ++ i) {
            if (SZ(from_left) == 0)
                from_left.push_back(height[i]);
            else
                from_left.push_back(max(height[i], from_left[i - 1]));
        }
        for (int i = SZ(height) - 1; i >= 0; -- i) {
            if (SZ(from_right) == 0)
                from_right.push_back(height[i]);
            else
                from_right.push_back(max(height[i], from_right[SZ(from_right) - 1]));
        }
        reverse(from_right.begin(), from_right.end());
        for (int i = 0; i < SZ(height); ++ i) {
            result += min(from_right[i], from_left[i]) - height[i];
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input;
    input.push_back(4), input.push_back(2), input.push_back(3);
    cout << solution.trap(input) << endl;
    return 0;
}
