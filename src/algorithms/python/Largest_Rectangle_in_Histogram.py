# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} height
    # @return {integer}
    def largestRectangleArea(self, height):
        st, ret = [], 0
        height.append(0)
        for i in range(len(height)):
            if st == []:
                st.append((height[i], i))
            else:
                if height[i] >= st[-1][0]:
                    st.append((height[i], i))
                else:
                    while st != [] and height[i] < st[-1][0]:
                        top = st.pop()
                        pre = -1 if st == [] else st[-1][1]
                        w, h = i - pre - 1, top[0]
                        ret = max(ret, w * h)
                    st.append((height[i], i))
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.largestRectangleArea([2, 1, 5, 6, 2, 3])
    print solution.largestRectangleArea([2, 1, 2])
    print solution.largestRectangleArea([2, 0, 2])
