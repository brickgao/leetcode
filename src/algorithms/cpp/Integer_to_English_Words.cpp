#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
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
    vector <string> units = {"", "Thousand", "Million", "Billion"};
    map <int, string> num2words;

public:
    string numberToWords(int num) {
        num2words[1] = "One";
        num2words[2] = "Two";
        num2words[3] = "Three";
        num2words[4] = "Four";
        num2words[5] = "Five";
        num2words[6] = "Six";
        num2words[7] = "Seven";
        num2words[8] = "Eight";
        num2words[9] = "Nine";
        num2words[10] = "Ten";
        num2words[11] = "Eleven";
        num2words[12] = "Twelve";
        num2words[13] = "Thirteen";
        num2words[14] = "Fourteen";
        num2words[15] = "Fifteen";
        num2words[16] = "Sixteen";
        num2words[17] = "Seventeen";
        num2words[18] = "Eighteen";
        num2words[19] = "Nineteen";
        num2words[20] = "Twenty";
        num2words[30] = "Thirty";
        num2words[40] = "Forty";
        num2words[50] = "Fifty";
        num2words[60] = "Sixty";
        num2words[70] = "Seventy";
        num2words[80] = "Eighty";
        num2words[90] = "Ninety";
        num2words[100] = "Hundred";
        if (num == 0)       return "Zero";
        vector <string> v_result;
        for (int i = 0; i < 4; ++ i) {
            int left = num % 1000;
            if (left != 0) {
                vector <string> v_string_section;
                if (left / 100 > 0)  {
                    v_string_section.push_back(num2words[left / 100] + " " + num2words[100]);
                    left %= 100;
                }
                if (left > 0) {
                    if (left < 20) {
                        v_string_section.push_back(num2words[left]);
                    }
                    else {
                        v_string_section.push_back(num2words[(int)(left / 10) * 10]);
                        left %= 10;
                        if (left > 0)       v_string_section.push_back(num2words[left]);
                    }
                }
                string string_section = "";
                for (int j = 0; j < SZ(v_string_section); ++ j) {
                    if (j > 0)      string_section += " ";
                    string_section += v_string_section[j];
                }
                if (units[i] != "")     string_section += " " + units[i];
                v_result.push_back(string_section);
            }
            num /= 1000;
            if (num == 0)       break;
        }
        string result = "";
        for (int i = SZ(v_result) - 1; i >= 0; -- i) {
            if (i < SZ(v_result) - 1)      result += " ";
            result += v_result[i];
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.numberToWords(100) << endl;
    cout << solution.numberToWords(123) << endl;
    cout << solution.numberToWords(12345) << endl;
    cout << solution.numberToWords(1234567) << endl;
    cout << solution.numberToWords(2147483647) << endl;
    return 0;
}
