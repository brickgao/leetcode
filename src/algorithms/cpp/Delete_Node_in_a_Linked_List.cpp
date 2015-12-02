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
    void deleteNode(ListNode* node) {
        ListNode *pre = node, *now = node->next;
        while (true) {
            pre->val = now->val;
            if (now->next == NULL) {
                pre->next = NULL;
                delete now;
                break;
            }
            pre = now;
            now = now->next;
        }
    }
};

int main() {
    Solution solution;
    ListNode *node1= new ListNode(0), *node2 = new ListNode(1);
    node1->next = node2;
    solution.deleteNode(node1);
    while (node1) {
        cout << node1->val << endl;
        node1 = node1->next;
    }
    return 0;
}
