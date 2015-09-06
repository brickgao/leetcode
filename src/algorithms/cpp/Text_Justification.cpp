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

class Solution {
public:
    vector <string> fullJustify(vector <string> &words, int maxWidth) {
        vector <string> result;
        int i = 0, beg = 0, total = 0;
        words.push_back(string (maxWidth + 1, ' '));
        while (i < SZ(words)) {
            if (total + SZ(words[i]) <= maxWidth) {
                total += SZ(words[i]) + 1;
            }
            else {
                total -= i - beg;
                int total_word_length = 0;
                for (int j = beg; j < i; ++ j)
                    total_word_length += SZ(words[j]);
                int space_length = -1;
                if (i - beg - 1 >= 1) {
                    space_length = (maxWidth - total_word_length) / (i - beg - 1);
                }
                int left_space = maxWidth - total_word_length - space_length * (i - beg - 1);
                if (i == SZ(words) - 1 && space_length != -1) {
                    space_length = 1;
                    left_space = 0;
                }
                string tmp_s = "";
                for (int j = beg; j < i; ++ j) {
                    tmp_s += words[j];
                    if (space_length == -1 && i != SZ(words) - 1) {
                        tmp_s += string(maxWidth - total_word_length, ' ');
                    }
                    if (j != i - 1) {
                        if (left_space > 0) {
                            tmp_s += string (space_length + 1, ' ');
                            -- left_space;
                        }
                        else {
                            tmp_s += string (space_length, ' ');
                        }
                    }
                }
                if (i == SZ(words) - 1) {
                    tmp_s += string(maxWidth - total_word_length - space_length * (i - beg - 1), ' ');
                }
                result.push_back(tmp_s);
                beg = i;
                total = SZ(words[i]) + 1;
            }
            ++ i;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <string> v = {"a", "b", "c", "d", "e"};
    vector <string> result = solution.fullJustify(v, 3);
    for (auto s: result) {
        cout << s << endl;
    }
    return 0;
}
