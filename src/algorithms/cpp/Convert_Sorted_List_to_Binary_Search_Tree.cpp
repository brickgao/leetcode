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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    ListNode *node;

private:
    TreeNode *build(int l, int r) {
        if (l == r)     return NULL;
        if (l == r - 1) {
            TreeNode *root = new TreeNode(node->val);
            node = node->next;
            return root;
        }
        int mid = (l + r) >> 1;
        TreeNode *left = build(l, mid);
        TreeNode *root = new TreeNode(node->val);
        node = node->next;
        TreeNode *right = build(mid + 1, r);
        root->left = left;
        root->right = right;
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        int length = 0;
        node = head;
        while (node) {
            length += 1;
            node = node->next;
        }
        node = head;
        return build(0, length);
    }
};

int main() {
    return 0;
}
