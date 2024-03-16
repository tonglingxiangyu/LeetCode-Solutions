class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class MyLinkedList:
    # 增加一个dummynode会更方便操作
    def __init__(self):
        self.dummynode = ListNode()
        self.size = 0 # 记录节点的个数

    def get(self, index: int) -> int:
        if index < self.size:
            current = self.dummynode.next
            for _ in range(index):
                current = current.next
            return current.val
        else:
            return -1


    def addAtHead(self, val: int) -> None:
        newnode = ListNode(val)
        newnode.next = self.dummynode.next
        self.dummynode.next = newnode
        self.size += 1


    def addAtTail(self, val: int) -> None:
        newnode = ListNode(val)
        current = self.dummynode
        while current.next:
            current = current.next
        current.next = newnode
        self.size += 1


    def addAtIndex(self, index: int, val: int) -> None:
        newnode = ListNode(val)
        current = self.dummynode
        if index <= self.size:
            for _ in range(index):
                current = current.next
            newnode.next = current.next
            current.next = newnode
            self.size += 1
        else:
            return


    def deleteAtIndex(self, index: int) -> None:
        current = self.dummynode
        if index < self.size:
            for _ in range(index):
                current = current.next
            current.next = current.next.next
            self.size -= 1
        else:
            return



# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)