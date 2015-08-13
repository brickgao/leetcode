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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1), *now  =head;
        while (l1 && l2) {
            if (l1->val < l2->val)
                now->next = l1, l1 = l1->next;
            else
                now->next = l2, l2 = l2->next;
            now = now->next;
        }
        ListNode *tmp = l1;
        if (l2) tmp = l2;
        while (tmp) {
            now->next = tmp, tmp = tmp->next;
            now = now->next;
        }
        return head->next;
    }
};

int main() {
    return 0;
}
