class Solution:
    def trap(self, height) -> int:
        print(height)
        rst = 0
        for i in range(len(height)):
            left = 0 if i == 0 else max(height[:i])
            right = 0 if i+1 >= len(height) else max(height[i+1:])
            print(i, left, right)
            rst += max(0, min(right, left) - height[i])
        return rst

    def trap2(self, height) -> int:
        left_max = [0] * len(height)
        right_max = [0] * len(height)
        rst = 0
        for idx, i in enumerate(height):
            rst = max(rst, i)
            left_max[idx] = rst
        rst = 0
        for idx in range(len(height) - 1, -1, -1):
            rst = max(rst, height[idx])
            right_max[idx] = rst
        #print('inp:\n', height)
        #print(left_max)
        #print(right_max)

        rst = 0
        for i in range(len(height)):
            left = 0 if i == 0 else left_max[i]
            right = 0 if i+1 >= len(height) else right_max[i]
            rst += max(0, min(right, left) - height[i])
        return rst



height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(Solution().trap(height))
print(Solution().trap2(height))
