class LinkedList:

    class ListNode:

        def __init__(self, value, prev=None, next=None):
            self.value = value
            self.next = next
            self.prev = prev

    def __init__(self):
        self.head = LinkedList.ListNode(0)
        self.last = self.head

    def last(self):
        return self.last

    def front(self):
        return self.head.next

    def push_back(self, node):
        self.last.next = node
        node.prev = self.last
        self.last = node
        node.next = None

    def erase(self, node):
        if node is None:
            return
        if node.prev is not None:
            node.prev.next = node.next
        if node.next is not None:
            node.next.prev = node.prev
        if self.last == node:
            self.last = self.last.prev
        node.prev = node.next = None


class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.lru_list = LinkedList()
        self.key_map = {}

    # @return an integer
    def get(self, key):
        if key not in self.key_map:
            return -1
        node = self.key_map[key]
        self.lru_list.erase(node)
        self.lru_list.push_back(node)
        return node.value[1]

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.key_map:
            node = self.key_map[key]
            node.value = (key, value)
            self.lru_list.erase(node)
        else:
            self._ensure_capacity()
            node = LinkedList.ListNode((key, value))
            self.key_map[key] = node
        self.lru_list.push_back(node)

    def _ensure_capacity(self):
        if len(self.key_map) == self.capacity:
            front = self.lru_list.front()
            self.lru_list.erase(front)
            del self.key_map[front.value[0]]


c = LRUCache(1)
c.set(2, 1)
print(c.get(2))
c.set(3, 2)
print(c.get(2))
print(c.get(3))
