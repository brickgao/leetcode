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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode *node = head;
        while (node) {
            node = node->next;
            ++ length;
        }
        if (length)                        k %= length;
        if (head == NULL || length == 1)   return head;
        if (k == 0)                        return head;
        ListNode *k_node = head, *k_pre_node = NULL;
        node = head;
        for (int i = 0; i < length - k; ++ i) {
            k_pre_node = k_node;
            k_node = k_node->next;
        }
        node = k_node;
        while (node->next)
            node = node->next;
        if (node != head)   node->next = head;
        if (k_pre_node)     k_pre_node->next = NULL;
        return k_node;
    }
};

int main() {
    ListNode *l1 = new ListNode(1), *l2 = new ListNode(2);
    l1->next = l2;
    Solution solution = Solution();
    ListNode *result = solution.rotateRight(NULL, 0);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
