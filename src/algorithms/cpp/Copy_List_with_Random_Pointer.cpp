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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    map <RandomListNode*, RandomListNode*> old2new;

    RandomListNode* dfs(RandomListNode *root) {
        if (root == NULL)   return NULL;
        RandomListNode *new_root = new RandomListNode(root->label);
        old2new[root] = new_root;
        new_root->next = dfs(root->next);
        return new_root;
    }

    void get_random(RandomListNode *root, RandomListNode *new_root) {
        if (root == NULL || new_root == NULL)   return;
        if (root->random == NULL)   new_root->random = NULL;
        else                        new_root->random = old2new[root->random];
        get_random(root->next, new_root->next);
    }

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)   return NULL;
        RandomListNode *new_head = dfs(head);
        get_random(head, new_head);
        return new_head;
    }
};

int main() {
    return 0;
 }
