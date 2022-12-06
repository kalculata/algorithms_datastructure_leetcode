# Notes

## Linear data structures

- Stack is a list with the restriction that insertion and deletion can be performed only one end, called the top (Last-In First-Out).
  - examples
    - Stack of disks
    - Stack of dishes
  - applications:
    - Recursion
    - undo in an editor
    - Parentheses validation

- Queue is a list with the restriction that insertion can be performed at one end (rear or tail) and deletion can be performed at other end (front) (First-In First-out).


## Recursive data structures

### Trees

- Leaf is node with no child.
- In tree with N nodes there will be N-1 link.
- Depth of node x is number of links in path from root to x. (depth of root node is 0).
- Height of node x is greatest number of links in path from x to a leaf.
- Height of tree is height of root node.
- Maximun number of nodes at level i = 2^i
- Maximun number of nodes in tree is 2^(h+1) - 1
