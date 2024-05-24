class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，因为这个区间选择任何一个位置作为起点，到i这里都会断油，那么起始位置从i+1算起，再从0计算curSum。
        cursum = 0
        totalsum = 0
        start = 0
        for i in range(len(gas)):
            cursum += gas[i] - cost[i]
            totalsum += gas[i] - cost[i]
            if cursum < 0:
                cursum = 0
                start = i + 1
        if totalsum < 0:
            return -1
        return start

            
