#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)       return;
        queue <TreeLinkNode*> q;
        TreeLinkNode *now = NULL, *end = root, *next_end = root;
        q.push(root);
        while (!q.empty()) {
            TreeLinkNode *front = q.front();
            q.pop();
            if (front->left)
                q.push(front->left), next_end = front->left;
            if (front->right)
                q.push(front->right), next_end = front->right;
            if (now == NULL) {
                now = front;
            }
            else {
                now->next = front;
                now = front;
            }
            if (front == end) {
                end = next_end;
                now = NULL;
            }
        }
    }
};

int main() {
    return 0;
}
