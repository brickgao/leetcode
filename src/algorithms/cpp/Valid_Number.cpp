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
private:
    bool isValid(string s) {
        int i = 0;
        bool tag1 = false, tag2 = false;
        while (i < SZ(s) && s[i] == ' ')
            ++ i;
        if (i == SZ(s))                        return false;
        else if(s[i] == '-' || s[i] == '+')    ++ i;
        while (i < SZ(s) && s[i] != '.' && s[i] != ' ')
            if ('0' <= s[i] && s[i] <= '9') ++ i, tag1 = true;
            else                            return false;
        if (i < SZ(s) && s[i] == ' ') {
            while (i < SZ(s))
                if (s[i] == ' ')    ++ i;
                else                return false;
            return true;
        }
        if (tag1 && i == SZ(s))            return true;
        else                               ++ i;
        while (i < SZ(s) && s[i] != ' ')
            if ('0' <= s[i] && s[i] <= '9') ++ i, tag2 = true;
            else                            return false;
        if (!tag1 && !tag2)  return false;
        while (i < SZ(s))
            if (s[i] == ' ')    ++ i;
            else                return false;
        return true;
    }

public:
    bool isNumber(string s) {
        int cnt = 0, pos = -1;
        for (int i = 0; i < SZ(s); ++ i)
            if (s[i] == 'e')
                ++ cnt, pos = i;
        if (cnt >= 2)    return false;
        if (cnt == 0)   {
            return isValid(s);
        }
        else {
            string part1 (s.begin(), s.begin() + pos), part2 (s.begin() + pos + 1, s.end());
            for (int i = 0; i < SZ(part2); ++ i)
                if (part2[i] == '.')
                    return false;
            if (SZ(part1) != 0 && part1[SZ(part1) - 1] == ' ')  return false;
            if (SZ(part2) != 0 && part2[0] == ' ')              return false;
            return isValid(part1) && isValid(part2);
        }
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.isNumber("+") << endl;
    cout << solution.isNumber("46.e3") << endl;
    cout << solution.isNumber("3.") << endl;
    cout << solution.isNumber(" ") << endl;
    cout << solution.isNumber("0e ") << endl;
    cout << solution.isNumber("0e") << endl;
    cout << solution.isNumber("e") << endl;
    cout << solution.isNumber(" .") << endl;
    cout << solution.isNumber("0") << endl;
    cout << solution.isNumber("0.1") << endl;
    cout << solution.isNumber(".1") << endl;
    cout << solution.isNumber("abc") << endl;
    cout << solution.isNumber("1 a") << endl;
    cout << solution.isNumber("2e10") << endl;
    cout << solution.isNumber("1 ") << endl;
    return 0;
}
