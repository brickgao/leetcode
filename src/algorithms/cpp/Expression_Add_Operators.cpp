#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    bool is_valid(string num) {
        if (num[0] == '0' && SZ(num) > 1)       return false;
        return true;
    }

    vector <string> dfs(string now, long long target, string mulexpr = "", long long mulval = 1) {
        vector <string> result;
        if (is_valid(now) && atoll(now.c_str()) * mulval == target)
            result.push_back(now + mulexpr);
        for (int i = 1; i < SZ(now); ++ i) {
            string left = string(now.begin(), now.begin() + i), right = string(now.begin() + i, now.end());
            if (is_valid(right)) {
                string rightexpr = right + mulexpr;
                long long rightval = atoll(right.c_str()) * mulval;
                for (auto &s: dfs(left, target - rightval))
                    result.push_back(s + '+' + rightexpr);
                for (auto &s: dfs(left, target + rightval))
                    result.push_back(s + '-' + rightexpr);
                for (auto &s: dfs(left, target, '*' + rightexpr, rightval))
                    result.push_back(s);
            }
        }
        return result;
    }

public:
    vector<string> addOperators(string num, long long target) {
        if (num == "")       return vector <string> {};
        return dfs(num, target);
    }
};


int main() {
    return 0;
}
