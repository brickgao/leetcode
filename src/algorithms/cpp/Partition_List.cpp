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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)   return NULL;
        ListNode *large_head = new ListNode(-1), *less_head = new ListNode(-1);
        ListNode *node = head, *lr_node = large_head, *ls_node = less_head;
        while (node) {
            ListNode *nxt = node->next;
            if (node->val < x) {
                ls_node->next = node;
                ls_node = ls_node->next;
                ls_node->next = NULL;
            }
            else {
                lr_node->next = node;
                lr_node = lr_node->next;
                lr_node->next = NULL;
            }
            node = nxt;
        }
        ListNode *new_head = less_head->next;
        if (ls_node != less_head)
            ls_node->next = large_head->next;
        else
            new_head = large_head->next;
        return new_head;
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(1);
    node1->next = node2;
    Solution solution = Solution();
    ListNode *node = solution.partition(node1, 0);
    while (node) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}
