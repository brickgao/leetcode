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

class MedianFinder {
private:
    vector <int> nums;

public:
    MedianFinder() : nums(vector <int> {}) {}

    // Adds a number into the data structure.
    void addNum(int num) {
        if (SZ(nums) == 0) {
            nums.push_back(num);
        }
        else {
            int pos = -1;
            int l = 0, r = SZ(nums) - 1;
            while (l < r - 1) {
                int mid = (l + r) >> 1;
                if (nums[mid] == num) {
                    pos = mid;
                    break;
                }
                else if (nums[mid] > num) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            if (pos == -1) {
                if (nums[r] <= num)         pos = r;
                else if (nums[l] <= num)    pos = l;
            }
            nums.insert(nums.begin() + pos + 1, num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int mid = SZ(nums) / 2;
        if (SZ(nums) % 2 == 0) 
            return static_cast <double> (nums[mid] + nums[mid - 1]) / 2.0;
        else
            return static_cast <double> (nums[mid]);
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
    return 0;
}
