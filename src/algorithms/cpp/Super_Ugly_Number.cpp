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
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector <long> uglys (1, 1), ugly_indexes (SZ(primes), 0);
        priority_queue <pair<long, long>, vector <pair<long, long>>, greater<pair<long, long>>> heap;
        for (int i = 0; i < SZ(primes); ++ i)
            heap.push(make_pair(primes[i], i));
        for (int i = 0; i < n; ++ i) {
            pair <long, long> minn = heap.top();
            heap.pop();
            if (minn.first != uglys[SZ(uglys) - 1])   uglys.push_back(minn.first);
            else                                      -- i;
            heap.push(make_pair(uglys[++ ugly_indexes[minn.second]] * primes[minn.second], minn.second));
        }
        return uglys[n - 1];
    }
};

int main() {
    return 0;
}
