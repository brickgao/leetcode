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
    int get_rec_area(int a, int b, int c, int d) {
        return abs((a - c) * (b - d));
    }

public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = get_rec_area(A, B, C, D) + get_rec_area(E, F, G, H);
        if (!(E >= C or G <= A or B >= H or D <= F))
            area -= get_rec_area(max(E, A), max(B, F), min(C, G), min(D, H));
        return area;
    }
};

int main() {
    return 0;
}
