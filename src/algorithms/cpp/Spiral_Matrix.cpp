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
private:
    bool vis[500][500];
    int m, n;

private:
    bool is_valid(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y])
            return false;
        else
            return true;
    }

public:
    vector <int> spiralOrder(vector <vector <int> >& matrix) {
        vector <int> result;
        if (SZ(matrix) == 0)       return result;
        m = SZ(matrix), n = SZ(matrix[0]);
        for (int i = 0; i <= SZ(matrix); ++ i)
            for (int j = 0; j <= SZ(matrix[0]); ++ j)
                vis[i][j] = false;
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int turn = 0, x = 0, y = 0;
        while (true) {
            vis[x][y] = true;
            result.push_back(matrix[x][y]);
            int nx = x + move[turn][0], ny = y + move[turn][1];
            int tag = 0;
            while (!is_valid(nx, ny)) {
                turn = (turn + 1) % 4;
                nx = x + move[turn][0], ny = y + move[turn][1];
                ++ tag;
                if (tag > 2)    break;
            }
            if (tag > 2)            break;
            x = nx, y = ny;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector < vector <int> > input;
    vector <int> tmp1, tmp2, tmp3;
    tmp1.push_back(1), tmp1.push_back(2), tmp1.push_back(3);
    tmp2.push_back(4), tmp2.push_back(5), tmp2.push_back(6);
    tmp3.push_back(7), tmp3.push_back(8), tmp3.push_back(9);
    input.push_back(tmp1), input.push_back(tmp2), input.push_back(tmp3);
    vector <int> result = solution.spiralOrder(input);
    for (int i = 0; i < SZ(result); ++ i)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
