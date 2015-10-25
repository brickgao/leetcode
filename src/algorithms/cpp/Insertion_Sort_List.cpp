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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *new_head = new ListNode(-2147483648);
        ListNode *node1 = head;
        while (node1 != NULL) {
            ListNode *nxt = node1->next;
            ListNode *pre = NULL, *node2 = new_head;
            while (node2 != NULL && node2->val <= node1->val) {
                pre = node2;
                node2 = node2->next;
            }
            pre->next = node1;
            node1->next = node2;
            node1 = nxt;
        }
        return new_head->next;
    }
};

int main() {
    ListNode *node1 = new ListNode(-2147483648), *node2 = new ListNode(-2147483647);
    node1->next = node2;
    Solution solution = Solution();
    ListNode *result = solution.insertionSortList(node1);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
