# Definition for a  binary tree node
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def tree_generator(treerepr):
    trim = treerepr.lstrip('{').rstrip('}')
    vals = trim.split(',')
    if not vals:
        return None
    root = TreeNode(int(vals[0]))
    idx = 1
    queue = [root]
    while idx < len(vals):
        cur = queue.pop(0)
        if vals[idx] != '#':
            cur.left = TreeNode(int(vals[idx]))
            queue.append(cur.left)
        idx += 1
        if idx == len(vals):
            break
        if vals[idx] != '#':
            cur.right = TreeNode(int(vals[idx]))
            queue.append(cur.right)
        idx += 1
    return root


def tree_to_str(root):
    nodes = []
    if root is not None:
        queue = [root]
        while queue:
            cur = queue.pop(0)
            nodes.append(str(cur.val) if cur is not None else '#')
            if cur is not None and not (cur.left is None and cur.right is None):
                queue.append(cur.left)
                queue.append(cur.right)
    return '{%s}' % ','.join(nodes)


# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


def list_to_str(head):

    def __recursive(head):
        if head is None:
            return
        yield head.val
        for i in __recursive(head.next):
            yield i

    return '[%s]' % ','.join(__recursive(head))
