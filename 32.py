class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        count = 0
        t = 0
        print(s)
        rst = 0
        for idx, i in enumerate(s):
            if i == '(':
                stack.append(i)
            elif i == ')':
                if stack and stack[-1] == '(':
                    stack.pop()
                    t += 2
                    if len(stack) == 0:
                        count += t
                        t = 0
                else:
                    rst = max(rst, count)
                    count = 0
                    t = 0
        return max(rst, count, t)

    def is_valid(self, s):
        stack = []
        for i in s:
            if i == '(':
                stack.append(i)
            elif i == ')':
                if stack:
                    stack.pop()
                else:
                    return False
        return len(stack) == 0

    def bf(self, s):
        rst = 0
        for i in range(len(s)):
            for j in range(i+2, len(s) + 1, 2):
                if self.is_valid(s[i:j]):
                    rst = max(rst, j - i)
        return rst

    def use_stack(self, s):
        """
        The starint index of a valid parathesis is always the index of some ")".
        ")   (  )  (  )"
         ^            ^
         start        end
        """
        stack = [-1]
        rst = 0
        for idx, i in enumerate(s):
            if i == '(':
                stack.append(idx)
            elif i == ')':
                stack.pop()
                l = idx - stack[-1]
                if len(stack) == 0:
                    stack.append(idx)
                rst = max(rst, l)
        return rst





s = '(())))'
s = '()(()'
s = ')()())'
s = ')()())'
s = '(()'
s = '()'
s = "(()(((()"
print(Solution().bf(s))
print(Solution().use_stack(s))
