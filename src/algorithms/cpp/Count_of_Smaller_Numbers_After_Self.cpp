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
    vector <int> sums;
    map <int, int> mp;
    int n;

private:
    void init() {
        int upper = (this->n << 2) + 10;
        for (int i = 0; i < upper; ++ i)
            this->sums.push_back(0);
    }

    void pushUp(int rt) {
        this->sums[rt] = this->sums[rt << 1] + this->sums[rt << 1 | 1];
    }

    void update(int pos, int l, int r, int rt) {
        if (l == r && l == pos) {
            ++ this->sums[rt];
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            this->update(pos, l, mid, rt << 1);
        else
            this->update(pos, mid + 1, r, rt << 1 | 1);
        this->pushUp(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return this->sums[rt];
        }
        int mid = (l + r) >> 1, ret = 0;
        if (L <= mid)
            ret += this->query(L, R, l, mid, rt << 1);
        if (mid < R)
            ret += this->query(L, R, mid + 1, r, rt << 1 | 1);
        return ret;
    }

    
public:
    vector<int> countSmaller(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->n = 1;
        for (int num: nums)
            if (this->mp[num] == 0) {
                this->mp[num] = this->n;
                ++ this->n;
            }
        this->init();
        vector <int> result;
        for (int i = SZ(nums) - 1; i >= 0; -- i) {
            result.push_back(this->query(1, this->mp[nums[i]], 1, this->n, 1));
            this->update(this->mp[nums[i]], 1, this->n, 1);
        }
        return result;
    }
};

int main() {
    return 0;
}
