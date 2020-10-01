class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

def array_to_tree(array):
    if not array:
        return TreeNode()
    nodes = [TreeNode(i) if i else None for i in array]
    for i, node in enumerate(nodes):
        if node:
            if 2 * i + 1< len(nodes):
                node.left = nodes[2 * i + 1]
            if 2 * i + 2< len(nodes):
                node.right = nodes[2 * i + 2]
    return nodes[0]

def tree_to_array(root):
    def to_array_(tree_list):
        array = []
        next_layer = []
        for i in tree_list:
            if i:
                next_layer += [i.left, i.right]
                array.append(i.val)
            else:
                next_layer += [None, None]
                array.append(None)
        return array, next_layer

    if not root:
        return []
    next_layer = [root]
    array = []
    layer = 0
    while (True):
        array_t, next_layer = to_array_(next_layer)
        print(f'layer={layer}, {array_t}')
        if set(array_t) == {None}:
            break
        else:
            array += array_t
        layer += 1
    print(f'Array representation: {array}')
    return array

if __name__ == '__main__':
    t = array_to_tree([2, 1, 3, None, 100, None, None])
    print(tree_to_array(t))
