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
public:
    vector<int> diffWaysToCompute(string input) {
        vector <int> result;
        bool is_num = true;
        for (auto &c: input)
            if (!isdigit(c))  is_num = false;
        if (is_num)     return vector <int> {atoi(input.c_str())};
        for (int i = 0; i < SZ(input); ++ i) {
            if (!isdigit(input[i])) {
                vector <int> left = diffWaysToCompute(string(input.begin(), input.begin() + i));
                vector <int> right = diffWaysToCompute(string(input.begin() + i + 1, input.end()));
                for (int left_ele: left)
                    for (int right_ele: right) {
                        if (input[i] == '+')        result.push_back(left_ele + right_ele);
                        else if (input[i] == '-')   result.push_back(left_ele - right_ele);
                        else                        result.push_back(left_ele * right_ele);
                    }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;
}
