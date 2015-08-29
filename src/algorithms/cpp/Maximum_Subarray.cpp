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
const double eps = 1e-6;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    vector <int> sum;
    vector <pair <int, int> > rec;
    vector <pair <int, int> > rec_p;

public:
    int maxSubArray(vector<int>& nums) {
        sum.push_back(0), rec.push_back(make_pair(0, 0));
        rec_p.push_back(make_pair(0, 0));
        int result = nums[0];
        for (int i = 0; i < SZ(nums); ++ i) {
            get_max(result, nums[i]);
            sum.push_back(sum[SZ(sum) - 1] + nums[i]);
            rec.push_back(make_pair(0, 0));
            rec_p.push_back(make_pair(0, 0));
        }
        int minn = sum[0], min_p = 0;
        for (int i = 0; i < SZ(sum); ++ i) {
            if (minn > sum[i])
                minn = sum[i], min_p = i;
            rec[i].first = minn, rec_p[i].first = min_p;
        }
        int maxn = sum[SZ(sum) - 1], max_p = SZ(sum) - 1;
        for (int i = SZ(sum) - 1; i >= 0; -- i) {
            if (maxn < sum[i])
                maxn = sum[i], max_p = i;
            rec[i].second = maxn, rec_p[i].second = max_p;
        }
        for (int i = 0; i < SZ(sum); ++ i) {
            if (rec_p[i].first != rec_p[i].second)
                get_max(result, rec[i].second - rec[i].first);
        }
        return result;
    }
};

int main() {
    vector <int> input;
    input.push_back(-2), input.push_back(1), input.push_back(-3), input.push_back(4);
    input.push_back(-1), input.push_back(2), input.push_back(1), input.push_back(-5);
    input.push_back(4);
    input.push_back(-1);
    Solution solution = Solution();
    cout << solution.maxSubArray(input) << endl;
    return 0;
}
