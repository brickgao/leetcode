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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *node = head, *pre = NULL, *beg = NULL, *end = NULL;
        for (int i = 0; i < m - 1; ++ i)
            pre = node, node = node->next;
        beg = pre, end = node;
        for (int i = 0; i < n - m + 1; ++ i) {
            ListNode *nxt = node->next;
            if (pre) {
                node->next = pre;
            }
            pre = node, node = nxt;
        }
        if (beg) {
            beg->next = pre;
            end->next = node;
        }
        else {
            head = pre;
            end->next = node;
        }
        return head;
    }
};

int main() {
    Solution solution = Solution();
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3), *node4 = new ListNode(4), *node5 = new ListNode(5);
    node1->next = node2, node2->next = node3, node3->next = node4, node4->next = node5;
    solution.reverseBetween(node1, 2, 4);
    ListNode *node = node1;
    while (node) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}
