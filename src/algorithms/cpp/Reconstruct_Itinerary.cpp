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
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map <string, vector <string>> mp;
        vector <string> result, paths = {"JFK"};
        for (auto ticket: tickets)
            mp[ticket.first].push_back(ticket.second);
        for (auto mp_it = mp.begin(); mp_it != mp.end(); ++ mp_it)
            sort(mp_it->second.begin(), mp_it->second.end());
        while (SZ(paths) != 0) {
            string now = paths.back();
            if (SZ(mp[now]) != 0) {
                paths.push_back(mp[now][0]);
                mp[now].erase(mp[now].begin());
            }
            else {
                result.push_back(paths.back());
                paths.pop_back();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    return 0;
}
