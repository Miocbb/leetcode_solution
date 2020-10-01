class Node:
    def __init__(self, val="", child=[]):
        self.val = val
        self.child = []

class Solution:
    def is_predecessor(self, s1, s2):
        if (abs(len(s1) - len(s2)) != 1):
            return False
        j = 0
        count = 0
        #print(s1, s2)
        for i in range(len(s1)):
            while j < len(s2):
                if s2[j] != s1[i]:
                    count += 1
                    j += 1
                else:
                    j += 1
                    break
            if count > 1:
                return False
        return count <= 1

    def run(self, root):
        num = 0
        for child in root.child:
            num = max(self.run(child), num)
        return num + 1

    def run_list(self, roots):
        num = 0
        for i in roots:
            num = max(self.run(i), num)
        return num

    def longestStrChain_wrong(self, words) -> int:
        """
        Build a tree from the words list, then find the deepest path in the tree.
        This will be too complicated.
        """

        # sort list based on length
        words_dict = {}
        for i in words:
            l = len(i)
            if l not in words_dict.keys():
                words_dict[l] = [i]
            else:
                words_dict[l].append(i)
        word_sort = sorted([(i, j) for i, j in words_dict.items()], key=lambda x: x[0])
        #print(word_sort)

        roots = [Node(i) for i in word_sort[0][1]]
        pre_roots = roots
        cur_roots = []
        for _, word_list in word_sort[1:]:
            cur_roots = []
            for i in pre_roots:
                child = [Node(x) for x in word_list if self.is_predecessor(i.val, x)]
                i.child = child
                cur_roots += child
            pre_roots = cur_roots
            print(f'layer={_}, list: {word_list}, cur_roots={[x.val for x in cur_roots]}')

        return self.run_list(roots)

    def longestStrChain(self, words):
        dp = {}
        for w in sorted(words, key=len):
            dp[w] = max(dp.get(w[:i] + w[i + 1:], 0) + 1 for i in range(len(w)))
        return max(dp.values())

    def dp(self, words):
        """
        Using DP, bottom-up method.
        space complexity: O(N)
        computational complexity: O(NlogN)
        """
        # dp[word] = max length
        dp = {}
        rst = 0
        for w in sorted(words, key=len):
            num = 1
            # check if w is a predecessor of the previous words.
            # iterate all the possible predecessors of the word, check it any
            # predecessor exits.
            for i in range(len(w)):
                nw = w[:i] + w[i+1:]
                if nw in dp.keys():
                    num = dp[nw] + 1
            dp[w] = num
            #print(w, dp)
            rst = max(rst, num)
        return rst





words = ["a","b","ba","bca","bda","bdca"]
words = ["ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"]
print(Solution().dp(words))
print(Solution().is_predecessor('', 'a'))
