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
    vector <vector <int> > generate(int numRows) {
        vector <vector <int> > result;
        if (numRows >= 1)   result.push_back(vector <int> {1});
        if (numRows >= 2) {
            for (int i = 1; i < numRows; ++ i) {
                vector <int> tmp;
                tmp.push_back(1);
                for (int j = 1; j < SZ(result[i - 1]); ++ j)
                    tmp.push_back(result[i - 1][j] + result[i - 1][j - 1]);
                tmp.push_back(1);
                result.push_back(tmp);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
