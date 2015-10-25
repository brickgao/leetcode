#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <list>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class LRUCache{
public:
    list <pair<int, int> > l;
    unordered_map<int, list <pair <int, int> >::iterator> mp;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->l.clear();
        this->mp.clear();
    }
    
    int get(int key) {
        if (mp.count(key) > 0) {
            pair <int, int> ret = *this->mp[key];
            this->l.erase(mp[key]);
            this->l.push_front(ret);
            this->mp[key] = this->l.begin();
            return ret.second;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (mp.count(key) > 0) {
            this->l.erase(mp[key]);
            this->l.push_front(make_pair(key, value));
            this->mp[key] = this->l.begin();
        }
        else {
            if (SZ(this->l) >= this->capacity) {
                this->mp.erase(this->l.back().first);
                this->l.pop_back();
            }
            this->l.push_front(make_pair(key, value));
            this->mp[key] = l.begin();
        }
    }
};

int main() {
    return 0;
}
