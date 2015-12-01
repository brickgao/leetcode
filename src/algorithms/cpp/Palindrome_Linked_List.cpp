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
private:
    ListNode *rec_node;
    bool result;

private:
    void search(ListNode *node) {
        if (node->next)     search(node->next);
        if (rec_node->val != node->val)     result = false;
        rec_node = rec_node->next;
    }

public:
    bool isPalindrome(ListNode* head) {
        result = true;
        rec_node = head;
        search(head);
        return result;
    }
};

int main() {
    return 0;
}
