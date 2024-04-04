class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # 使用哈希表来建立每一个数字的出现次数
        # 维护一个数目为k的最小堆，每次将最新的元素与堆顶元素（最小值）进行比较，只要比堆顶元素大就弹出堆顶元素添加新的元素
        # 最后留下了的k个元素即为所求
        # 使用哈希表统计元素频率
        freq_map = Counter(nums)
        # 初始化最小堆
        min_heap = []
        # 遍历频率映射
        for num, freq in freq_map.items():
            # 如果堆的大小小于k，直接添加
            if len(min_heap) < k:
                heapq.heappush(min_heap, (freq, num))
            else:
                # 如果当前数字的频率大于堆顶元素的频率，则替换
                if freq > min_heap[0][0]:
                    heapq.heappop(min_heap)
                    heapq.heappush(min_heap, (freq, num))
        # 提取堆中的元素
        return [num for freq, num in min_heap]



        # ans = []
        # record = {}
        # for i, v in enumerate(nums):
        #     if v in record.keys():
        #         record[v] += 1
        #     else:
        #         record[v] = 1
        # for i in range(k):
        #     Max = float('-inf')
        #     result = 0
        #     for i, v in record.items():
        #         if v > Max:
        #             Max = v
        #             result = i
        #     ans.append(result)
        #     record[result] = 0
        # return ans