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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre_end = NULL, *pre = NULL, *beg = head, *node = head, *new_head = head;
        int cnt = 0;
        while (node) {
            if (node->val == beg->val) {
                ++ cnt;
            }
            else {
                if (cnt > 1) {
                    if (pre_end)    pre_end->next = node;
                    else            new_head = node;
                }
                else {
                    pre_end = pre;
                }
                beg = node;
                cnt = 1;
            }
            pre = node;
            node = node->next;
        }
        if (cnt > 1) {
            if (pre_end)    pre_end->next = node;
            else            new_head = node;
        }
        return new_head;
    }
};

int main() {
    ListNode *arr[7];
    arr[0] = new ListNode(1);
    arr[1] = new ListNode(1);
    arr[2] = new ListNode(3);
    arr[3] = new ListNode(3);
    arr[4] = new ListNode(4);
    arr[5] = new ListNode(4);
    arr[6] = new ListNode(5);
    for (int i = 0; i < 6; ++ i)
        arr[i]->next = arr[i + 1];
    Solution solution = Solution();
    ListNode *result = solution.deleteDuplicates(arr[0]);
    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
