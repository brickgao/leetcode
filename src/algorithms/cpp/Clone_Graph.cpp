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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    map <int, UndirectedGraphNode*> mp;

private:
    UndirectedGraphNode* dfs(UndirectedGraphNode *node) {
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        mp[node->label] = new_node;
        for (int i = 0; i < SZ(node->neighbors); ++ i) {
            if (mp[node->neighbors[i]->label] == NULL)
                new_node->neighbors.push_back(dfs(node->neighbors[i]));
            else
                new_node->neighbors.push_back(mp[node->neighbors[i]->label]);
        }
        return new_node;
    }

public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)   return node;
        else                return dfs(node);
    }
};

int main() {
    return 0;
}
