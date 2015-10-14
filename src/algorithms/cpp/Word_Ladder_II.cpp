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
#include <unordered_set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    string beginWord;
    vector <vector <string> > result;
    map <string, set <string> > mp;
    vector <string> result_element;
    
private:
    void dfs(string &now) {
        if (now == beginWord) {
            result_element.push_back(now);
            result.push_back(result_element);
            result_element.pop_back();
            return;
        }
        for (auto nxt: mp[now]) {
            result_element.push_back(now);
            dfs(nxt);
            result_element.pop_back();
        }
    }

public:
    vector<vector <string> > findLadders(string beginWord, string endWord, unordered_set <string> &wordList) {
        this->beginWord = beginWord;
        int len = SZ(beginWord);
        map <string, int> vis;
        vector <char> alpha_list;
        queue <string> q;
        if (beginWord == endWord) {
            result.push_back(vector <string> {beginWord});
            return result;
        }
        vis[beginWord] = 1;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        for (char ch = 'a'; ch <= 'z'; ++ ch)   alpha_list.push_back(ch);
        q.push(beginWord);
        while (!q.empty()) {
            string front = q.front();
            q.pop();
            for (int i = 0; i < len; ++ i) {
                string left = string(front.begin(), front.begin() + i);
                string right = string(front.begin() + i + 1, front.end());
                for (char &ch: alpha_list) {
                    if (ch == front[i])   continue;
                    string tmp_s = left + ch + right;
                    if (wordList.count(tmp_s) == 0)  continue;
                    int tmp_cnt = vis[front] + 1;
                    if (vis[tmp_s] != 0 && vis[tmp_s] < tmp_cnt)    continue;
                    vis[tmp_s] = tmp_cnt;
                    if (tmp_s == endWord) {
                        if (vis[endWord] != 0 && tmp_cnt > vis[endWord]) {
                            dfs(endWord);
                            for (auto &v: result)   reverse(v.begin(), v.end());
                            return result;
                        }
                        mp[tmp_s].insert(front);
                    }
                    else {
                        if (vis[endWord] == 0 || tmp_cnt < vis[endWord]) {
                            if (mp[tmp_s].count(front) == 0) {
                                mp[tmp_s].insert(front);
                                q.push(tmp_s);
                            }
                        }
                    }
                }
            }
        }
        dfs(endWord);
        for (auto &v: result)   reverse(v.begin(), v.end());
        return result;
    }
};

int main() {
    Solution solution = Solution();
    string beginWord = "hit", endWord = "cog";
    unordered_set <string> wordList {"hot", "dot", "dog", "lot", "log"};
    vector <vector <string> > result = solution.findLadders(beginWord, endWord, wordList);
    for (auto v: result) {
        for (auto str: v)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
