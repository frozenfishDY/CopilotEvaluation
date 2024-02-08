/**https://leetcode.com/problems/n-ary-tree-preorder-traversal/ */
//Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
//Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class NAryTreePreorderTraversal {
    public List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<>();
        if(root == null) return res;
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            Node node = stack.pop();
            res.add(node.val);
            for(int i = node.children.size() - 1; i >= 0; i--){
                stack.push(node.children.get(i));
            }
        }
        return res;
        
        
    }
}

    