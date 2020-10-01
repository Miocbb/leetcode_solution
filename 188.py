import math
class Solution:
    def maxProfit(self, k, prices) -> int:
        """
        There are three status parameters: which day, number of used transaction,
        and stock status (having a stock or not). So the dynamic table is
        dp[day][used_transaction][stock_status]

        starting condition:
        dp[0][0][0] = 0
        dp[0][0][1] = -princes[0]

        all the possible status changing process from day i - 1 to i.
        1. already hold a stock and will keep current status
           dp[i][j][1] = dp[i-1][j][1]
        2. not hold a stock and will keep current status
           dp[i][j][0] = dp[i-1][j][0]
        3. selling
           dp[i][j][0] = dp[i-1][j][1] + prices[i]
        4. buying
           dp[i][j][1] = dp[i-1][j-1][0] - prices[i]

        dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])

        Finally, we want the max dp[N][j][0] for j in [1, k].
        """
        N = len(prices)
        if N == 0 or k == 0:
            return 0

        if 2 * k > N:
            rst = 0
            for i in range(N - 1):
                rst += max(0, prices[i+1] - prices[i])
            return rst

        dp = [[[-float("INF")] * 2 for _ in range(k + 1)] for _ in range(N)]

        # dp[i][used_k][ishold] = profit
        dp[0][0][0] = 0
        dp[0][1][1] = -prices[0]

        for i in range(1, N):
            #for j in range(k+1):
            for j in range(min(i+2, k+1)):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
                if j > 0:
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])

        candi = [dp[N - 1][j][0] for j in range(k+1)]
        print(candi)
        return max(candi)


class Solution2:
    def maxProfit(self, k, prices) -> int:
        n = len(prices)

        # solve special cases
        if not prices or k==0:
            return 0

        if 2*k > n:
            res = 0
            for i, j in zip(prices[1:], prices[:-1]):
                res += max(0, i - j)
            return res

        # dp[i][used_k][ishold] = balance
        # ishold: 0 nothold, 1 hold
        dp = [[[-math.inf]*2 for _ in range(k+1)] for _ in range(n)]

        # set starting value
        dp[0][0][0] = 0
        dp[0][1][1] = -prices[0]

        # fill the array
        for i in range(1, n):
            for j in range(k+1):
                # transition equation
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i])
                # you can't hold stock without any transaction
                if j > 0:
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])

        res = max(dp[n-1][j][0] for j in range(k+1))
        return res

class Solution3:
    def maxProfit(self, k: int, prices) -> int:
        n = len(prices)

        # solve special cases
        if not prices or k == 0:
            return 0

        # find all consecutively increasing subsequence
        transactions = []
        start = 0
        end = 0
        for i in range(1, n):
            if prices[i] >= prices[i-1]:
                end = i
            else:
                if end > start:
                    transactions.append([start, end])
                start = i
        if end > start:
            transactions.append([start, end])

        while len(transactions) > k:
            # check delete loss
            delete_index = 0
            min_delete_loss = math.inf
            for i in range(len(transactions)):
                t = transactions[i]
                profit_loss = prices[t[1]] - prices[t[0]]
                if profit_loss < min_delete_loss:
                    min_delete_loss = profit_loss
                    delete_index = i

            # check merge loss
            merge_index = 0
            min_merge_loss = math.inf
            for i in range(1, len(transactions)):
                t1 = transactions[i-1]
                t2 = transactions[i]
                profit_loss = prices[t1[1]] - prices[t2[0]]
                if profit_loss < min_merge_loss:
                    min_merge_loss = profit_loss
                    merge_index = i

            # delete or merge
            if min_delete_loss <= min_merge_loss:
                transactions.pop(delete_index)
            else:
                transactions[merge_index - 1][1] = transactions[merge_index][1]
                transactions.pop(merge_index)

        return sum(prices[j]-prices[i] for i, j in transactions)

s = Solution()
s2 = Solution2()
print(s.maxProfit(1, [1,2,3]))
print(s.maxProfit(0, [1,3]))
#print(s.maxProfit(2, [1,2,4,2,5,7,2,4,9,0]))
