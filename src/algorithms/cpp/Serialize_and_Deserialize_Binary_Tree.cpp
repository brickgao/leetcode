#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
private:
    int cnt = 1;
    map <TreeNode *, int> mp;
    map <int, TreeNode *> mp2;

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        this->cnt = 1;
        this->mp.clear();
        vector <string> result;
        if (root == nullptr)        return "";
        this->_serialize(root, result);
        string s_result = "";
        for (string s: result)
            s_result += s + " ";
        return s_result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")     return nullptr;
        vector <string> v_data;
        string tmp;
        for (auto &ch: data) {
            if (ch == ' ') {
                if (tmp != "")  v_data.push_back(tmp);
                tmp = "";
            }
            else {
                tmp += ch;
            }
        }
        this->mp2.clear();
        this->mp2[0] = nullptr;
        for (int i = 0; i < SZ(v_data); ++ i) {
            string tmp = "";
            int val = 0, id = i + 1, left_child_id = 0, right_child_id = 0;
            int j = 0;
            for (; j < SZ(v_data[i]); ++ j) {
                if (v_data[i][j] == ',')      break;
                else                          tmp += v_data[i][j];
            }
            ++ j;
            val = atoi(tmp.c_str());
            tmp = "";
            for (; j < SZ(v_data[i]); ++ j) {
                if (v_data[i][j] == ',')      break;
                else                          tmp += v_data[i][j];
            }
            ++ j;
            left_child_id = atoi(tmp.c_str());
            right_child_id = atoi(string(v_data[i].begin() + j, v_data[i].end()).c_str());
            this->_deserialize_node(val, id, left_child_id, right_child_id);
        }
        return this->mp2[SZ(v_data)];
    }

private:
    void _serialize(TreeNode *root, vector <string> &result) {
        if (root->left)         this->_serialize(root->left, result);
        if (root->right)        this->_serialize(root->right, result);
        result.push_back(this->_serialize_node(root));
        this->mp[root] = this->cnt ++;
    }

    string _serialize_node(TreeNode *root) {
        string s_node = "";
        s_node += to_string(root->val);
        s_node += "," + to_string(this->mp[root->left]);
        s_node += "," + to_string(this->mp[root->right]);
        return s_node;
    }

    void _deserialize_node(int val, int id, int left_child_id, int right_child_id) {
        TreeNode *node = new TreeNode(val);
        node->left = this->mp2[left_child_id];
        node->right = this->mp2[right_child_id];
        this->mp2[id] = node;
    }
};

int main() {
    // Your Codec object will be instantiated and called as such:
    TreeNode *root = nullptr;
    Codec codec;
    codec.deserialize(codec.serialize(root));
    return 0;
}
