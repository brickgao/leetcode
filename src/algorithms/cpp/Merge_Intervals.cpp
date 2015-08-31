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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector <Interval> merge(vector <Interval>& intervals) {
        vector <Interval> result;
        if (SZ(intervals) == 0)     return result;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 1; i < SZ(intervals); ++ i) {
            if (start <= intervals[i].start && intervals[i].start <= end) {
                get_max(end, intervals[i].end);
            }
            else {
                result.push_back(Interval(start, end));
                start = intervals[i].start, end = intervals[i].end;
            }
        }
        result.push_back(Interval(start, end));
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <Interval> input;
    input.push_back(Interval(1, 3)), input.push_back(Interval(2, 6));
    input.push_back(Interval(8, 10)), input.push_back(Interval(15, 18));
    vector <Interval> result = solution.merge(input);
    for (int i = 0; i < SZ(result); ++ i) {
        cout << result[i].start << " " << result[i].end << endl;
    }
    return 0;
}
