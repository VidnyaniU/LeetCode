import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;

class Node{
    int data;
    Node left;
    Node right;

    public Node(int key){
        data = key;
        left = null;
        right = null;
    }
}
public class BinaryTree {
    //perform preorder traversal and store the values in a list
    static void preorder(Node root){
        if(root == null)return;

        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    static void inorder(Node root){
        if(root == null)return;

        inorder(root.left);
        System.out.print(root.data + " ");

        inorder(root.right);
    }
    static void postorder(Node root){
        if(root == null)return;

        postorder(root.left);

        postorder(root.right);
        System.out.print(root.data + " ");

    }

    //height of binary tree(or maximum depth) : number of nodes on the longest path from root to leaf

    //diameter of the binary tree
    //BRUTE FORCE
    static int diameter = 0 ;
    public static int calculateHeight(Node node){
        if(node == null)return 0;
        int leftHeight = calculateHeight(node.left);
        int rightHeight = calculateHeight(node.right);

        diameter = Math.max(diameter , leftHeight+rightHeight);
        return 1+Math.max(leftHeight , rightHeight);
    }
    public static int diameterOfBinaryTree(Node root) {
        calculateHeight(root);
        return diameter;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left= new Node(4);
        root.left.right= new Node(5);

//        preorder(root);
//        inorder(root);
        postorder(root);


    }

}
