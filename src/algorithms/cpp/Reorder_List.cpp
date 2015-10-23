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
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode *node = head;
        stack <ListNode *> st;
        vector <ListNode *> v;
        while (node)    node = node->next, ++ len;
        if (len <= 1)   return;
        node = head;
        for (int i = 0; i < ceil(len / 2.0); ++ i)  v.push_back(node), node = node->next;
        while (node)    st.push(node), node = node->next;
        int now = 0;
        ListNode *pre = NULL;
        while (!st.empty()) {
            if (pre != NULL)    pre->next = v[now], v[now]->next = st.top();
            else                v[now]->next = st.top();
            pre = st.top();
            ++ now, st.pop();
        }
        if (now < SZ(v))        pre->next = v[now], v[now]->next = NULL;
        else                    pre->next = NULL;
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2);
    node1->next = node2;
    Solution solution = Solution();
    solution.reorderList(node1);
    while(node1) {
        cout << node1->val << endl;
        node1 = node1->next;
    }
    return 0;
}
