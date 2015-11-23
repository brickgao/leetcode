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
    int len;
    
private:
    int get_high(TreeNode *root, int m) {
        TreeNode *node = root;
        int tmp_len = 1, tmp = (1 << (len - 2));
        for (int i = 0; i < len - 1; ++ i) {
            if ((m & tmp) > 0)   node = node->right;
            else                 node = node->left;
            if (node == NULL)   break;
            ++ tmp_len;
            tmp >>= 1;
        }
        return tmp_len;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == NULL)       return 0;
        len = 0;
        TreeNode *node = root;
        while (node) {
            node = node->left;
            ++ len;
        }
        int l = 0, r = (1 << (len - 1)) - 1;
        cout << l << " " << r << endl;
        while (l < r - 1) {
            int m = (l + r) >> 1, tmp_len = get_high(root, m);
            if (tmp_len < len)  r = m;
            else                l = m;
        }
        int r_high = get_high(root, r), l_high = get_high(root, l);
        if (r_high == l_high)   return pow(2, len) - 1;
        else                    return pow(2, len - 1) + l;
    }
};

int main() {
    return 0;
}
