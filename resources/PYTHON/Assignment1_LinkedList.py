class Node:
                        def __init__(self, data=None, next=None):
                                                self.data = data
                                                self.next = next
      
      
# Helper function to print a given linked list
def printList(head):
      
                        ptr = head
                        while ptr:
                                                print(ptr.data, end=' —> ')
                                                ptr = ptr.next
      
                        print('None')
      
      
# Remove duplicates from a sorted list
def removeDuplicates(head):
      
                        # do nothing if the list is empty
                        if head is None:
                                                return None
      
                        current = head
      
                        # compare the current node with the next node
                        while current.next:
                                                if current.data == current.next.data:
                                                                        nextNext = current.next.next
                                                                        current.next = nextNext
                                                else:
                                                                        current = current.next                                                # only advance if no deletion
      
                        return head
      
      
if __name__ == '__main__':
      
                        # input keys
                        keys = [1, 2, 2, 2, 3, 4, 4, 5]
      
                        # construct a linked list
                        head = None
                        for i in reversed(range(len(keys))):
                                                head = Node(keys[i], head)
      
                        head = removeDuplicates(head)
      
                        # print linked list
                        printList(head)