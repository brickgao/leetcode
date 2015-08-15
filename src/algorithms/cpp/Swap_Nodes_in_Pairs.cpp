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
    ListNode* swapPairs(ListNode* head) {
        int cnt = 0;
        ListNode *now = head, *pre = NULL, *ppre = NULL, *result = head;
        while (now) {
            ListNode *nxt = now->next;
            if (cnt % 2 == 1) {
                if (ppre) {
                    pre->next = now->next, now->next = pre, ppre->next = now;
                }
                else {
                    pre->next = now->next, now->next = pre, result = now;
                }
                ppre = now, now = nxt;
            }
            else {
                ppre = pre, pre = now, now = nxt;
            }
            cnt += 1;
        }
        return result;
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3);
    node1->next = node2, node2->next = node3;
    Solution solution = Solution();
    ListNode *result = solution.swapPairs(node1);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
