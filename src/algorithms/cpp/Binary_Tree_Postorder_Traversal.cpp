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
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> result;
        stack <TreeNode *> st, st2;
        map <TreeNode *, bool> mp;
        mp[NULL] = true;
        if (root)       st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st2.push(node), st.pop();
            if (node->right)    st.push(node->right);
            if (node->left)     st.push(node->left);
            while (!st2.empty() && mp[st2.top()->left] && mp[st2.top()->right]) {
                result.push_back(st2.top()->val);
                mp[st2.top()] = true;
                st2.pop();
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
