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
    vector <int> nums;
    vector <vector <int> > result;
    vector <int> tmp;

private:
    void get_subsets(int now, int &cnt) {
        if (SZ(tmp) == cnt) {
            result.push_back(tmp);
            return;
        }
        if (now >= SZ(nums) || SZ(nums) - now + SZ(tmp) < cnt)  return;
        for (int i = now; i < SZ(nums); ++ i) {
            tmp.push_back(nums[i]);
            get_subsets(i + 1, cnt);
            tmp.pop_back();
        }
    }
    
public:
    vector <vector <int> > subsets(vector <int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        result.push_back(vector <int> {});
        for (int i = 1; i <= SZ(nums); ++ i) {
            get_subsets(0, i);
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input = {1, 2, 3};
    vector <vector <int> > result = solution.subsets(input);
    for (auto v: result) {
        for (auto num: v)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
