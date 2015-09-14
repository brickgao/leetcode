#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int largestRectangleArea(vector <int>& height) {
        stack <pair<int, int> > st;
        int result = 0;
        height.push_back(0);
        for (int i = 0; i < SZ(height); ++ i) {
            while (!st.empty() && height[i] < st.top().first) {
                pair <int, int> top = st.top();
                st.pop();
                int pre;
                if (st.empty())     pre = -1;
                else                pre = st.top().second;
                int w = i - pre - 1, h = top.first;
                get_max(result, w * h);
            }
            st.push(make_pair(height[i], i));
        }
        return result;
    }
};

int main() {
    vector <int> input = {2, 1, 5, 6, 2, 3};
    Solution solution = Solution();
    cout << solution.largestRectangleArea(input) << endl;
    return 0;
}
