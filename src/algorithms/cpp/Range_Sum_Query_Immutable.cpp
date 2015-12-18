#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class NumArray {
private:
    vector <int> sums;

public:
    NumArray(vector<int> &nums) {
        this->sums.push_back(0);
        for (int i = 0; i < SZ(nums); ++ i) {
            this->sums.push_back(this->sums.back() + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return this->sums[j + 1] - this->sums[i];
    }
};

int main() {
    return 0;
}
