class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class BinaryTree {
    Node root;

    // Function to find the height of the binary tree
    int findHeight(Node node) {
        // Base case: if the node is null, return -1
        if (node == null) {
            return -1; // Height of an empty tree is -1
        } else {
            // Recursively find the height of left and right subtrees
            int leftHeight = findHeight(node.left);
            int rightHeight = findHeight(node.right);
            // Return the maximum of the two heights plus one for the current node
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("The height of the binary tree is: " + tree.findHeight(tree.root));
    }
}