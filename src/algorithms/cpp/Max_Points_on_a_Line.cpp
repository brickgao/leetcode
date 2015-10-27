#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool cmp(Point p1, Point p2) {
    if (p1.x != p2.x)   return p1.x < p2.x;
    else                return p1.y < p2.y;
}

int gcd(int a, int b) {
    int tag = 1;
    if (a * b < 0)  tag = -1;
    if (b > a)      swap(a, b);
    if (b == 0)     return 1;
    int c = a % b;
    while (c != 0) {
        a = b, b = c;
        c = a % b;
    }
    return b * tag;
}

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        sort(points.begin(), points.end(), cmp);
        int i = 0, ret = 0;
        while (i < SZ(points)) {
            map <pair<int, int>, int> mp;
            int same_points = 0;
            if (i > 1 && points[i].x == points[i - 1].x && points[i].y == points[i - 1].y) {
                ++ i;
                continue;
            }
            for (int j = 0; j < SZ(points); ++ j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++ same_points;
                    continue;
                }
                int diff_x = points[i].x - points[j].x;
                int diff_y = points[i].y - points[j].y;
                if (diff_x == 0)    ++ mp[make_pair(0, 0)];
                else {
                    int gcd_ret = gcd(diff_x, diff_y);
                    diff_x /= gcd_ret, diff_y /= gcd_ret;
                    ++ mp[make_pair(diff_y, diff_x)];
                }
            }
            get_max(ret, same_points);
            for (auto it = mp.cbegin(); it != mp.cend(); ++ it)
                get_max(ret, same_points + it->second);
            ++ i;
        }
        return ret;
    }
};

int main() {
    vector <Point> points;
    Solution solution = Solution();
    points.push_back(Point(0, 0));
    points.push_back(Point(0, 0));
    cout << solution.maxPoints(points) << endl;
    return 0;
}
