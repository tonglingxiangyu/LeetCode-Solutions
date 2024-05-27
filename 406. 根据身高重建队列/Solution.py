class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # 从身高和前面人数两个维度考虑。首先考虑身高，从高到低排；然后优先按身高高的people的k来插入，后序插入节点也不会影响前面已经插入的节点，最终按照k的规则完成了队列。
        ans = []
        people.sort(key=lambda x: (-x[0], x[1]))
        for man in people:
            position = man[1]
            ans.insert(position, man)
        return ans