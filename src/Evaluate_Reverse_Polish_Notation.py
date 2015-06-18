# -*- coding: utf-8 -*-


class Solution:
    # @param {string[]} tokens
    # @return {integer}
    def evalRPN(self, tokens):
        st = []
        for token in tokens:
            if token.isdigit() or (token[0] == '-' and token[1:].isdigit()):
                st.append(int(token))
            else:
                num1, num2 = st.pop(), st.pop()
                if token == '+':
                    st.append(num1 + num2)
                elif token == '-':
                    st.append(num2 - num1)
                elif token == '*':
                    st.append(num1 * num2)
                else:
                    _ret = abs(num2) / abs(num1)
                    if num1 * num2 > 0:
                        st.append(_ret)
                    else:
                        st.append(- _ret)
        return st[0]


if __name__ == "__main__":
    solution = Solution()
    print solution.evalRPN(["2", "1", "+", "3", "*"])
    print solution.evalRPN(["4", "13", "5", "/", "+"])
    print solution.evalRPN(["3", "-4", "+"])
