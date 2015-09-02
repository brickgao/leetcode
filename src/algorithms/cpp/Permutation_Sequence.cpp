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
    vector <int> nums;

private:
    int factorial(int x) {
        int result = 1;
        for (int i = 1; i <= x; ++ i)
            result *= i;
        return result;
    }

public:
    string getPermutation(int n, int k) {
        int cnt = k, e = n;
        string result;
        for (int i = 1; i <= n; ++ i)
            nums.push_back(i);
        while (true) {
            int sub = factorial(e - 1);
            for (int i = 0; i < e; ++ i) {
                if (cnt > sub)
                    cnt -= sub;
                else {
                    result += '0' + nums[i];
                    nums.erase(nums.begin() + i);
                    e -= 1;
                    break;
                }
            }
            if (SZ(result) == n)
                break;
        }
        return result;
    }
};

int main() {
    return 0;
}
