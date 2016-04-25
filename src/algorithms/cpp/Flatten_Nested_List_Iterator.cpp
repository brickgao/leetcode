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


class NestedIterator {
private:
    stack <pair <vector <NestedInteger> *, int>> st;
    
    void go_to_next_valid() {
        while (!st.empty() && SZ(*(st.top().first)) <= st.top().second) {
            st.pop();
            if (!st.empty()) {
                st.top().second += 1;
            }
        }
    }
    
    void go_to_next_one() {
        while (!st.empty() && !((*(st.top().first))[st.top().second].isInteger())) {
            st.push(make_pair(&((*(st.top().first))[st.top().second].getList()), 0));
            go_to_next_valid();
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push(make_pair(&nestedList, 0));
        go_to_next_valid();
        go_to_next_one();
    }
    
    int next() {
        int result = (*(st.top().first))[st.top().second].getInteger();
        st.top().second += 1;
        go_to_next_valid();
        go_to_next_one();
        return result;
    }

    bool hasNext() {
        return !st.empty() ? true : false;
    }
};


int main() {
    return 0;
}
