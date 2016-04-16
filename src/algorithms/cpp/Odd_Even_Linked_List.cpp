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
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)    return nullptr;
        ListNode *even_head = new ListNode(-1), *odd_head = new ListNode(-1);
        ListNode *now = head, *even_now = even_head, *odd_now = odd_head;
        int cnt = 1;
        while (now != nullptr) {
            ListNode *nxt = now->next;
            now->next = nullptr;
            if (cnt % 2 == 0)   even_now->next = now, even_now = now;
            else                odd_now->next = now, odd_now = now;
            cnt += 1;
            now = nxt;
        }
        odd_now->next = even_head->next;
        return odd_head->next;
    }
            
};


int main() {
    return 0;
}
