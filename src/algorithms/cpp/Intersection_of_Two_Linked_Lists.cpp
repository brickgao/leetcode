#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *node1 = headA, *node2 = headB;
        while (node1) {
            node1 = node1->next;
            ++ len1;
        }
        while (node2) {
            node2 = node2->next;
            ++ len2;
        }
        node1 = headA, node2 = headB;
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; ++ i)
                node1 = node1->next;
        }
        else {
            for (int i = 0; i < len2 - len1; ++ i)
                node2 = node2->next;
        }
        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};

int main() {
    return 0;
}
