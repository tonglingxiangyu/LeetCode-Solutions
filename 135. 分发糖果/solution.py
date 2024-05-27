class Solution:
    def candy(self, ratings: List[int]) -> int:
        # 需要分别考虑右孩子大于左孩子的情况和左孩子大于右孩子的情况
        # 从前到后考虑右孩子大于左孩子，从后到前考虑左孩子大于右孩子，然后最后取两种情况的最大值作为结果
        candies = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        for j in range(len(ratings)-2, -1, -1):
            if ratings[j] > ratings[j+1]:
                candies[j] = max(candies[j], candies[j+1] + 1)
        return sum(candies)