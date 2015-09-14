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
    int maximalRectangle(vector <vector <char> > &matrix) {
        if (SZ(matrix) == 0)    return 0;
        int height[200] = {}, result = 0;
        for (int i = 0; i < SZ(matrix); ++ i) {
            for (int j = 0; j < SZ(matrix[i]); ++ j)
                if (matrix[i][j] == '1')    ++ height[j];
                else                        height[j] = 0;
            stack <pair <int, int> > st;
            for (int j = 0; j < SZ(matrix[i]) + 1; ++ j) {
                while (!st.empty() && height[j] < st.top().first) {
                    pair <int, int> top = st.top();
                    st.pop();
                    int pre;
                    if (st.empty())     pre = -1;
                    else                pre = st.top().second;
                    int w = j - pre - 1, h = top.first;
                    get_max(result, w * h);
                }
                st.push(make_pair(height[j], j));
            }
        }
        return result;
    }
};

int main() {
    vector <vector <char> > input = {{'0', '1'}};
    Solution solution = Solution();
    cout << solution.maximalRectangle(input) << endl;
    return 0;
}
