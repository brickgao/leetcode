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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Queue {
private:
    stack <int> st;

public:
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack <int> tmp_st;
        while (SZ(st) > 1) {
            tmp_st.push(st.top());
            st.pop();
        }
        if (!st.empty())    st.pop();
        while (!tmp_st.empty()) {
            st.push(tmp_st.top());
            tmp_st.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int ret;
        stack <int> tmp_st;
        while (SZ(st) > 1) {
            tmp_st.push(st.top());
            st.pop();
        }
        if (!st.empty()) {
            ret = st.top();
            tmp_st.push(ret);
            st.pop();
        }
        while (!tmp_st.empty()) {
            st.push(tmp_st.top());
            tmp_st.pop();
        }
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};

int main() {
    return 0;
}
