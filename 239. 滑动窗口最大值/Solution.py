class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # 使用双端队列单调队列递减，去除无用的信息，只保留可能是答案的值。
        # 入的时候如果当前元素大于等于队尾的元素，则去掉所有这些元素，确保队首是最大的且最新的值。
        # 出的时候当队首的下标不在长度为k的窗口的范围时。
        # 答案就是每一次循环的队首
        q = deque()
        ans = []
        for i, v in enumerate(nums):
            while q and v >= nums[q[-1]]:
                q.pop()
            q.append(i) # 不管怎么样都要将i存下来，因为不知道i后面的情况
            if i-q[0]+1 > k:
                q.popleft()
            if i >= k-1: # 从第k个位置开始保存答案
                ans.append(nums[q[0]])
        return ans