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
    vector<vector <int> > levelOrder(TreeNode* root) {
        vector <vector <int> > result;
        if (root == NULL)
            return result;
        vector <int> tmp;
        queue <TreeNode *> q;
        TreeNode *end = root, *next_end = root;
        q.push(root);
        while (!q.empty()) {
            TreeNode *front = q.front();
            tmp.push_back(front->val);
            if (front->left) {
                next_end = front->left;
                q.push(front->left);
            }
            if (front->right) {
                next_end = front->right;
                q.push(front->right);
            }
            if (front == end) {
                result.push_back(tmp);
                end = next_end;
                tmp.clear();
            }
            q.pop();
        }
        return result;
    }
};

int main() {
    TreeNode *node11 = new TreeNode(3), *node21 = new TreeNode(9), *node22 = new TreeNode(20);
    TreeNode *node33 = new TreeNode(15), *node34 = new TreeNode(7);
    node11->left = node21, node11->right = node22;
    node22->left = node33, node22->right = node34;
    Solution solution = Solution();
    vector <vector <int> > result = solution.levelOrder(node11);
    for (auto v: result) {
        for (auto num: v)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
