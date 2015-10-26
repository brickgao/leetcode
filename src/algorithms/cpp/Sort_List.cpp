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
private:
    ListNode* mergesort(ListNode *beg, ListNode *end, int len) {
        if (beg == end) {
            beg->next = NULL;
            return beg;
        }
        ListNode *node = beg;
        for (int i = 0; i < len / 2 - 1; ++ i)
            node = node->next;
        ListNode *mid = node, *mid_next = node->next;
        ListNode *l_node = mergesort(beg, mid, len / 2), *r_node = mergesort(mid_next, end, len - len / 2);
        ListNode *new_head = new ListNode(0);
        node = new_head;
        while (l_node && r_node) {
            if (l_node->val < r_node->val) {
                node->next = l_node;
                node = node->next;
                l_node = l_node->next;
            }
            else {
                node->next = r_node;
                node = node->next;
                r_node = r_node->next;
            }
        }
        while (l_node) {
            node->next = l_node;
            node = node->next;
            l_node = l_node->next;
        }
        while (r_node) {
            node->next = r_node;
            node = node->next;
            r_node = r_node->next;
        }
        node->next = NULL;
        return new_head->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)   return NULL;
        ListNode *node = head;
        int len = 0;
        while (node->next) {
            ++ len;
            node = node->next;
        }
        return mergesort(head, node, len + 1);
    }
};

int main() {
    ListNode *node1 = new ListNode(3), *node2 = new ListNode(4), *node3 = new ListNode(2), *node4 = new ListNode(1);
    node1->next = node2, node2->next = node3, node3->next = node4;
    Solution solution = Solution();
    ListNode *result = solution.sortList(node1);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
