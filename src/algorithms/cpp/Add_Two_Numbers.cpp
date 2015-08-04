#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int left = 0;
        ListNode *pre = NULL, *node = NULL, *head = l1;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + left;
            pre = l1;
            l1->val = tmp % 10, left = tmp / 10;
            l1 = l1->next, l2 = l2->next;
        }
        if (l1) {
            node = l1;
        }
        else {
            node = l2;
        }
        while (node) {
            int tmp = node->val + left;
            node->val = tmp % 10, left = tmp/ 10;
            pre->next = node;
            pre = node;
            node = node->next;
        }
        if (left) {
            ListNode *new_node = new ListNode(left);
            pre->next = new_node;
        }
        return head;
    }
};

int main() {
    return 0;
}
