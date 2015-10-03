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
    vector <int> nums;

private:
    TreeNode* build(int l, int r) {
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        if (mid - l)
            root->left = build(l, mid);
        if (r - mid - 1)
            root->right = build(mid + 1, r);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector <int> &nums) {
        if (SZ(nums) == 0)      return NULL;
        this->nums = nums;
        return build(0, SZ(nums));
    }
};

int main() {
    return 0;
}
