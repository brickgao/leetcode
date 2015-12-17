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
    string getHint(string secret, string guess) {
        map <char, int> mp;
        int a = 0, b = 0;
        for (int i = 0; i < SZ(secret); ++ i)
            ++ mp[secret[i]];
        for (int i = 0; i < SZ(secret); ++ i)
            if (secret[i] == guess[i]) {
                ++ a;
                -- mp[secret[i]];
            }
        for (int i = 0; i < SZ(secret); ++ i)
            if (secret[i] != guess[i]) {
                if (mp[guess[i]] > 0) {
                    -- mp[guess[i]];
                    ++ b;
                }
            }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};

int main() {
    return 0;
}
