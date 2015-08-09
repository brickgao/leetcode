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
    string intToRoman(int num) {
        string s = "";
        if (num / 1000 != 0) {
            s += string (num / 1000, 'M');
            num %= 1000;
        }
        if (num / 100 != 0) {
            if (num / 100 == 9) s += "CM";
            else if (num / 100 >= 5)  s += "D" + string ((num - 500) / 100, 'C');
            else if (num / 100 == 4)  s += "CD";
            else s += string ((num / 100), 'C');
            num %= 100;
        }
        if (num / 10 != 0) {
            if (num / 10 == 9) s += "XC";
            else if (num / 10 >= 5) s += "L" + string ((num - 50) / 10, 'X');
            else if (num / 10 == 4) s += "XL";
            else s += string ((num / 10), 'X');
            num %= 10;
        }
        if (num / 1 != 0) {
            if (num / 1 == 9) s += "IX";
            else if (num / 1 >= 5) s += "V" + string((num - 5) / 1, 'I');
            else if (num / 1 == 4) s += "IV";
            else s += string ((num / 1), 'I');
        }
        return s;
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.intToRoman(19) << endl;
    cout << solution.intToRoman(1) << endl;
    cout << solution.intToRoman(7) << endl;
    cout << solution.intToRoman(1000) << endl;
    return 0;
}
