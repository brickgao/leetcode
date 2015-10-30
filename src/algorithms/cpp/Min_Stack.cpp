#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class MinStack {
private:
    stack <int> st, min_st;

public:
    void push(int x) {
        st.push(x);
        if (!min_st.empty())    min_st.push(min(min_st.top(), x));
        else                    min_st.push(x);
    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

int main() {
    return 0;
}
