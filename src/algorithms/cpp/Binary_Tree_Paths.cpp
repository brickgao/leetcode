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
private:
    vector <int> tmp_paths;
    vector <string> result;
    
private:
    void dfs(TreeNode *node) {
        tmp_paths.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            string tmp_s = "";
            for (int i = 0; i < SZ(tmp_paths); ++ i) {
                if (i > 0)  tmp_s += "->";
                tmp_s += to_string(tmp_paths[i]);
            }
            result.push_back(tmp_s);
        }
        else {
            if (node->left)         dfs(node->left);
            if (node->right)        dfs(node->right);
        }
        tmp_paths.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {        
        if (root)   dfs(root);
        return result;
    }
};

int main() {
    return 0;
}
