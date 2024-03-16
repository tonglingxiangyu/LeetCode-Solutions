public class ListNode{
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int val){
        this.val = val;
    }
}

class MyLinkedList {
    int size;
    ListNode head;
    // 这里的head就是dummynode节点
    public MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }
    
    public int get(int index) {
        ListNode current = head;
        if(index < size){
            for(int i = 0; i <= index; i++){
                current = current.next;
            }
            return current.val;
        }
        else{
            return -1;
        }

    }
    
    public void addAtHead(int val) {
        ListNode newnode = new ListNode(val);
        newnode.next = head.next;
        head.next = newnode;
        size++;
    }
    
    public void addAtTail(int val) {
        ListNode newnode = new ListNode(val);
        ListNode current = head;
        for(int i = 0; i < size; i++){
            current = current.next;
        }
        current.next = newnode;
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }
        ListNode newnode = new ListNode(val);
        ListNode current = head;
        for(int i = 0; i < index; i++){
            current = current.next;
        }
        newnode.next = current.next;
        current.next = newnode;
        size++;
    }
    
    public void deleteAtIndex(int index) {
        if(index >= size){
            return;
        }
        ListNode current = head;
        for(int i = 0; i < index; i++){
            current = current.next;
        }
        current.next = current.next.next;
        size--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */