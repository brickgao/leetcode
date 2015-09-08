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
    void setZeroes(vector< vector <int> >& matrix) {
        if (SZ(matrix) == 0)    return;
        bool vis_x[500] = {}, vis_y[500] = {};
        int m = SZ(matrix), n = SZ(matrix[0]);
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (matrix[i][j] == 0)
                    vis_x[i] = true, vis_y[j] = true;
        for (int i = 0; i < m; ++ i)
            if (vis_x[i])
                for (int j = 0; j < n; ++ j)
                    matrix[i][j] = 0;
        for (int j = 0; j < n; ++ j)
            if (vis_y[j])
                for (int i = 0; i < m; ++ i)
                    matrix[i][j] = 0;
    }
};

int main() {
    return 0;
}
