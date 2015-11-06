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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

bool cmp(string &a, string &b) {
    return atoll((a + b).c_str()) > atoll((b + a).c_str());
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> v;
        for (auto &num: nums)   v.push_back(to_string(num));
        sort(v.begin(), v.end(), cmp);
        string result = "";
        for (auto &s: v)        result += s;
        int beg = 0;
        while (beg < SZ(result) - 1 && result[beg] == '0')  ++ beg;
        return result.substr(beg);
    }
};

int main() {
    Solution solution = Solution();
    vector <int> v = {3, 30, 34, 5, 9};
    cout << solution.largestNumber(v) << endl;
    vector <int> vv = {0, 0};
    cout << solution.largestNumber(vv) << endl;
    return 0;
}
