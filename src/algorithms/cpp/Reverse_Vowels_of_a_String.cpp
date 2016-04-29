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
    string reverseVowels(string s) {
        set <char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector <int> pos;
        for (int i = 0; i < SZ(s); ++ i) {
            if (vowels.find(s[i]) != vowels.end())
                pos.push_back(i);
        }
        for (int i = 0; i < SZ(pos) / 2; ++ i)
            swap(s[pos[i]], s[pos[SZ(pos) - i - 1]]);
        return s;
    }
};


int main() {
    return 0;
}
