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
    vector <int> inorderTraversal(TreeNode* root) {
        TreeNode *node = root;
        stack <TreeNode*> st;
        vector <int> result;
        while (node || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                st.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
