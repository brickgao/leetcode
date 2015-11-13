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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *node = head, *pre = new_head;
        while (node) {
            ListNode *nxt = node->next;
            if (node->val == val) {
                pre->next = nxt;
                delete node;
                node = nxt;
            }
            else {
                pre = node;
                node = nxt;
            }
        }
        return new_head->next;
    }
};

int main() {
    return 0;
}
