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
    vector <Interval> insert(vector <Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector <Interval> result;
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
    return 0;
}
