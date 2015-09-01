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
    int lengthOfLastWord(string s) {
        int result = 0, tmp = 0;
        for (int i = 0; i < SZ(s); ++ i) {
            if (s[i] == ' ') {
                if (tmp != 0)   result = tmp;
                tmp = 0;
            }
            else
                tmp += 1;
        }
        if (tmp != 0)   result = tmp;
        return result;
    }
};

int main() {
    return 0;
}
