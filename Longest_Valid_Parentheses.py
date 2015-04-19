# -*- coding: utf-8 -*-


class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        st, maxn = [], 0
        for index, ch in enumerate(s):
            if ch == '(':
                st.append((ch, index))
            else:
                if st != [] and st[-1][0] == '(':
                    tmp = st.pop()
                    maxn = max(maxn, index - (-1 if st == [] else st[-1][1]))
                else:
                    st.append((ch, index))
        return maxn


if __name__ == '__main__':
    solution = Solution()
    print solution.longestValidParentheses('(()')
    print solution.longestValidParentheses(')()())')
    print solution.longestValidParentheses('()(()')
    print solution.longestValidParentheses('()')
