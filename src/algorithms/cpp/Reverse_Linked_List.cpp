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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack <ListNode *> st;
        ListNode *node = head, *new_head = new ListNode(0), *pre = new_head;
        while (node) {
            st.push(node);
            node = node->next;
        }
        while (!st.empty()) {
            ListNode *top = st.top();
            pre->next = top;
            pre = top;
            pre->next = NULL;
            st.pop();
        }
        return new_head->next;
    }
};

int main() {
    return 0;
}
