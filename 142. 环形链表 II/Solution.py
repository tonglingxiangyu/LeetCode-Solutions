# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 慢指针走一步，快指针走两步，他们总会在环内相遇，这时让一个新节点从头节点出发与慢指针共同往前走他们会在环的入口相遇
        slow = head
        fast = head
        while fast and fast.next: # 如果到了末尾None说明无环
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                newslow = head
                while slow != newslow:
                    slow = slow.next
                    newslow = newslow.next
                return slow
        return None