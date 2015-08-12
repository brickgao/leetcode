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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *ret;
    int n;

private:
    int dfs(ListNode *pre, ListNode *now) {
        if (now == NULL)   return 0;
        int nxt_ret = dfs(now, now->next);
        if (nxt_ret == n - 1) {
            if (pre == NULL)    this->ret = now->next;
            else {
                pre->next = now->next;
                free(now);
            }
        }
        return nxt_ret + 1;
    }

public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        this->ret = head;
        this->n = n;
        dfs(NULL, head);
        return this->ret;
    }
};

int main() {
    return 0;
}
