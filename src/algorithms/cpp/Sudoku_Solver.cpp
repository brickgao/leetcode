#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    vector <vector <char> > board;
    vector <vector <char> > result;
    bool found;

private:
    void dfs(int x, int y) {
        if (found)      return;
        if (x > 8) {
            found = true;
            this->result = board;
        }
        else {
            if (board[x][y] == '.') {
                bool can[10] = {false};
                for (int i = 1; i < 10; ++ i)   can[i] = true;
                for (int i = 0; i < 9; ++ i) {
                    if (board[i][y] != '.')         can[board[i][y] - '0'] = false;
                    if (board[x][i] != '.')         can[board[x][i] - '0'] = false;
                }
                int begx = int(x / 3) * 3, begy = int(y / 3) * 3;
                for (int i = begx; i < begx + 3; ++ i) 
                    for (int j = begy; j < begy + 3; ++ j)
                        if (board[i][j] != '.')     can[board[i][j] - '0'] = false;
                for (int i = 1; i < 10; ++ i)
                    if (can[i]) {
                        board[x][y] = '0' + i;
                        if (y == 8)     dfs(x + 1, 0);
                        else            dfs(x, y + 1);
                        board[x][y] = '.';
                    }
            }
            else {
                if (y == 8)     dfs(x + 1, 0);
                else            dfs(x, y + 1);
            }
        }
    }

public:
    void solveSudoku(vector<vector<char> >& board) {
        this->board = board;
        this->found = false;
        dfs(0, 0);
        board = this->result;
    }
};

int main() {
    vector <string> tmp;
    vector <vector <char> > v;
    tmp.push_back("..9748..."), tmp.push_back("7........");
    tmp.push_back(".2.1.9..."), tmp.push_back("..7...24.");
    tmp.push_back(".64.1.59."), tmp.push_back(".98...3..");
    tmp.push_back("...8.3.2."), tmp.push_back("........6");
    tmp.push_back("...2759..");
    for (int i = 0; i < 9; ++ i) {
        vector <char> v_char;
        for (int j = 0; j < 9; ++ j)
            v_char.push_back(tmp[i][j]);
        v.push_back(v_char);
    }
    Solution solution = Solution();
    solution.solveSudoku(v);
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j)
            cout <<  v[i][j];
        cout << endl;
    }
    return 0;
}
