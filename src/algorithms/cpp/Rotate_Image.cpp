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
    void rotate(vector <vector <int> >& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < SZ(matrix); ++ i) {
            for (int j = 0; j < i; ++ j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    return 0;
}
