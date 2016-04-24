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
    vector<int> countBits(int num) {
        vector <int> result = {0};
        if (num == 0)   return result;
        result.push_back(1);
        int last_end = 1, step = 1;
        while (SZ(result) <= num) {
            for (int i = step - 1; i >= 0; -- i) {
                if (SZ(result) <= num)  result.push_back(result[last_end - i]);
                else                    break;
            }
            for (int i = step - 1; i >= 0; -- i) {
                if (SZ(result) <= num)  result.push_back(result[last_end - i] + 1);
                else                    break;
            }
            last_end = SZ(result) - 1;
            step <<= 1;
        }
        return result;
    }
};


int main() {
    return 0;
}
