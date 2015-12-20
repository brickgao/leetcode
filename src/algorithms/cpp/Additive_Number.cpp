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
private:
    bool search(string left, int num1, int num2) {
        if (SZ(left) == 0)      return true;
        long long num3 = num1 + num2;
        string s_num3 = to_string(num3);
        bool is_valid = true;
        for (int i = 0; i < SZ(s_num3); ++ i) {
            if (i >= SZ(left) || left[i] != s_num3[i]) {
                is_valid = false;
                break;
            }
        }
        if (is_valid)   return this->search(string(left.begin() + SZ(s_num3), left.end()), num2, num3);
        else            return false;
    }

public:
    bool isAdditiveNumber(string s_num) {
        if (SZ(s_num) < 3)    return false;
        for (int i = 1; i <= SZ(s_num) - 2; ++ i) {
            string s_num1 (s_num.begin(), s_num.begin() + i);
            if (SZ(s_num1) > 1 && s_num1[0] == '0')     continue;
            for (int j = i + 1; j <= SZ(s_num) - 1; ++ j) {
                string s_num2 (s_num.begin() + i, s_num.begin() + j);
                if (SZ(s_num2) > 1 && s_num2[0] == '0')     continue;
                long long num3 = atoll(s_num1.c_str()) + atoll(s_num2.c_str());
                string s_num3 = to_string(num3);
                bool is_valid = true;
                for (int k = 0; k < SZ(s_num3); ++ k) {
                    if (s_num3[k] != s_num[j + k]) {
                        is_valid = false;
                        break;
                    }
                }
                if (is_valid && this->search(string(s_num.begin() + j + SZ(s_num3), s_num.end()), atoi(s_num2.c_str()), num3))  return true;
            }
        }
    }
};

int main() {
    return 0;
}
