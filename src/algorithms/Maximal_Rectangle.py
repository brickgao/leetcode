# -*- coding: utf-8 -*-


class Solution:
    # @param {character[][]} matrix
    # @return {integer}
    def maximalRectangle(self, matrix):
        if matrix == []:
            return 0
        m, n = len(matrix), len(matrix[0])
        ret = 0
        rec = [0 for i in range(m + 1)]
        for i in range(n):
            for j in range(m):
                if matrix[j][i] == "1":
                    rec[j] += 1
                else:
                    rec[j] = 0
            st = []
            for j in range(m + 1):
                if st == []:
                    st.append((rec[j], j))
                else:
                    if rec[j] >= st[-1][0]:
                        st.append((rec[j], j))
                    else:
                        while st != [] and rec[j] < st[-1][0]:
                            top = st.pop()
                            pre = -1 if st == [] else st[-1][1]
                            w, h = j - pre - 1, top[0]
                            ret = max(ret, w * h)
                        st.append((rec[j], j))
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maximalRectangle(["100",
                                     "010",
                                     "011"])
    print solution.maximalRectangle(["1"])
