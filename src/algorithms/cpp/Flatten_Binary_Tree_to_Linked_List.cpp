#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)   return;
        stack <TreeNode*> st;
        TreeNode *now = NULL;
        st.push(root);
        while (!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            if (now == NULL)    now = top;
            else                now->right = top, now->left = NULL, now = now->right;
            if (top->right)   st.push(top->right);
            if (top->left)    st.push(top->left);
        }
    }
};

int main() {
    return 0;
}
