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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)     return head;
        ListNode *now = head, *result = head;
        vector <ListNode*> pre (k, NULL);
        int cnt = 0;
        while (now) {
            ListNode *nxt = now->next;
            if (cnt % k == k - 1) {
                if (pre[0]) {
                    for (int i = k - 1; i >= 2; --i)    pre[i]->next = pre[i - 1];
                    now->next = pre[k - 1], pre[1]->next = nxt, pre[0]->next = now;
                }
                else {
                    for (int i = k - 1; i >= 2; --i)    pre[i]->next = pre[i - 1];
                    now->next = pre[k - 1], pre[1]->next = nxt, result = now;
                }
                for (int i = 0; i < k - 1; ++ i)    pre[i] = pre[i + 1];
                pre[k - 1] = now, now = nxt;
                reverse(pre.begin(), pre.end());
            }
            else {
                for (int i = 0; i < k - 1; ++ i)    pre[i] = pre[i + 1];
                pre[k - 1] = now, now = nxt;
            }
            cnt += 1;
        }
        return result;
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4), *node5 = new ListNode(5), *node6 = new ListNode(6);
    node1->next = node2, node2->next = node3;
    node3->next = node4, node4->next = node5, node5->next = node6;
    Solution solution = Solution();
    ListNode *result = solution.reverseKGroup(node1, 3);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
