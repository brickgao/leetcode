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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector <int> > levelOrderBottom(TreeNode* root) {
        vector <vector <int> > result;
        if (root == NULL)   return result;
        TreeNode *end = root, *next_end = root;
        vector <int> tmp_v;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *now = q.front();
            q.pop();
            tmp_v.push_back(now->val);
            if (now->left) {
                q.push(now->left);
                next_end = now->left;
            }
            if (now->right) {
                q.push(now->right);
                next_end = now->right;
            }
            if (now == end) {
                end = next_end;
                result.push_back(tmp_v);
                tmp_v.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;
}
