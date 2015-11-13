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
    int countPrimes(int n) {
        if (n < 2)  return 0;
        int e = int(sqrt(n)) + 1;
        vector <bool> vis (n, false);
        int result = n - 2;
        vis[0] = true;
        vis[1] = true;
        for (int i = 4; i < n; i += 2) {
            vis[i] = true;
            result -= 1;
        }
        for (int i = 3; i < e; i += 2) {
            for (int j = i * i; j < n; j += i * 2) {
                if (!vis[j])    result -= 1, vis[j] = true;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
