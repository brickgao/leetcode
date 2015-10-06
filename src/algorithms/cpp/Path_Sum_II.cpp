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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector <vector <int> > result;
    vector <int> tmp;

private:
    void dfs(TreeNode *root, int sum) {
        tmp.push_back(root->val);
        if (root->left)
            dfs(root->left, sum - root->val);
        if (root->right)
            dfs(root->right, sum - root->val);
        if (root->left == NULL && root->right == NULL && sum - root->val == 0)
            result.push_back(tmp);
        tmp.pop_back();
    }

public:
    vector<vector <int> > pathSum(TreeNode* root, int sum) {
        if (root == NULL)   return result;
        dfs(root, sum);
        return result;
    }
};

int main() {
    return 0;
}
