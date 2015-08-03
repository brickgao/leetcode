# -*- coding: utf-8 -*-


class Solution:
    def get_seg_result(self, _s):
        _tmp, _now, _pre = 0, "", ""
        for ch in _s + "-":
            if ch == "+" or ch == "-":
                if _pre == "-":
                    _tmp -= int(_now)
                else:
                    _tmp += int(_now)
                _now, _pre = "", ch
            else:
                _now += ch
        return _tmp

    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        st, _tmp_s = [], ""
        for ch in s:
            if ch == "(":
                st.append(_tmp_s)
                _tmp_s = ""
            elif ch == ")":
                _seg_result = self.get_seg_result(_tmp_s)
                _pop_s = "" if st == [] else st.pop().strip()
                if _seg_result < 0:
                    _seg_result = - _seg_result
                    if _pop_s == "":
                        _tmp_s = "0-" + str(_seg_result)
                    elif _pop_s[-1] == "+":
                        _tmp_s = _pop_s[:-1] + "-" + str(_seg_result)
                    elif _pop_s[-1] == "-":
                        _tmp_s = _pop_s[:-1] + "+" + str(_seg_result)
                else:
                    _tmp_s = _pop_s + str(_seg_result)
            else:
                _tmp_s += ch
        return self.get_seg_result(_tmp_s)


if __name__ == "__main__":
    solution = Solution()
    print solution.calculate("1 + 1")
    print solution.calculate("2-1 + 2")
    print solution.calculate("(1+(4+5+2)-3)+(6+8)")
    print solution.calculate("1-(5)")
    print solution.calculate("2-(5-6)")
    print solution.calculate("(5-(1+(5)))")
