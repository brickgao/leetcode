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

class Solution {
private:
    int string2int(string &word) {
        int result = 0;
        for (int i = 0; i < SZ(word); ++ i) {
            result |= 1 << (word[i] - 'a');
        }
        return result;
    }
    
public:
    int maxProduct(vector<string>& words) {
        vector <int> int_words;
        for (string &word: words) {
            int_words.push_back(this->string2int(word));
        }
        int result = 0;
        for (int i = 0; i < SZ(words); ++ i) {
            for (int j = i; j < SZ(words); ++ j) {
                if ((int_words[i] & int_words[j]) == 0) {
                    get_max(result, SZ(words[i]) * SZ(words[j]));
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
