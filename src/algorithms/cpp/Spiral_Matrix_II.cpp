#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
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
    vector<vector <int> > generateMatrix(int n) {
        vector <vector <int> > result;
        if (n == 0)             return result;
        for (int i = 0; i < n; ++ i) {
            vector <int> tmp_v (n, 0);
            result.push_back(tmp_v);
        }
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, now = 1, turn = 0;
        while (true) {
            result[x][y] = now;
            int nx = x + move[turn][0], ny = y + move[turn][1];
            int cnt = 0;
            while (nx < 0 || ny < 0 || nx >= n || ny >= n || result[nx][ny] != 0) {
                turn = (turn + 1) % 4;
                nx = x + move[turn][0], ny = y + move[turn][1];
                cnt += 1;
                if (cnt >= 2)   break;
            }
            if (cnt >= 2)       break;
            x = nx, y = ny;
            ++ now;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <vector <int> > result = solution.generateMatrix(4);
    for (int i = 0; i < SZ(result); ++ i) {
        for (int j = 0; j < SZ(result[i]); ++ j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
