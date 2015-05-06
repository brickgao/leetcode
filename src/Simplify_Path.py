# -*- coding: utf-8 -*-


class Solution:
    # @param {string} path
    # @return {string}
    def simplifyPath(self, path):
        l, ret = path.split('/'), []
        for elem in l:
            if elem == '..':
                if ret != []:
                    ret.pop()
            elif elem == '.' or elem == '':
                pass
            else:
                ret.append(elem)
        return '/' + '/'.join(ret)


if __name__ == '__main__':
    solution = Solution()
    print solution.simplifyPath('/home/')
    print solution.simplifyPath('/a/./b/../../c')
    print solution.simplifyPath('/../')
