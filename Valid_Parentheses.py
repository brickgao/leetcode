# -*- coding: utf-8 *-


class Solution:
    # @param s, a string
    # @return a boolean
    def isValid(self, s):
        st = []
        for ch in s:
            if st != []:
                if ch == ')' and st[-1] == '(':
                    st.pop()
                elif ch == ']' and st[-1] == '[':
                    st.pop()
                elif ch == '}' and st[-1] == '{':
                    st.pop()
                else:
                    st.append(ch)
            else:
                st.append(ch)
        return st == []


if __name__ == '__main__':
    solution = Solution()
    print solution.isValid('()[]{}')
    print solution.isValid('(]')
    print solution.isValid('(]{}')
    print solution.isValid('([)')
