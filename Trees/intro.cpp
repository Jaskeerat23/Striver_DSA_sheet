#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct Node {
public:
    int val;
    struct Node* left;
    struct Node* right;
    
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
    Node(int val, struct Node* right, struct Node* left) : val(val), right(right), left(left) {}
};
class Tree {
public:
    Node* root = nullptr;

    void push(int val) {

        Node* newNode = new Node(val);
        if(root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            Node* ptr = q.front();
            q.pop();

            if(ptr->left == nullptr) {
                ptr->left = newNode;
                break;
            }
            else if(ptr->right == nullptr) {
                ptr->right = newNode;
                break;
            }

            q.push(ptr->left);
            q.push(ptr->right);
        }
    }
    
    void showInOrder(Node* root) {
        if(root == nullptr) return;
        showInOrder(root->left);
        cout << root->val << " ";
        showInOrder(root->right);
    }

    void showPreOrder(Node* root) {
        if(root == nullptr) return;
        cout << root->val << " ";
        showPreOrder(root->left);
        showPreOrder(root->right);
    }

    void showPostOrder(Node* root) {
        if(root == nullptr) return;
        showPostOrder(root->left);
        showPostOrder(root->right);
        cout << root->val << " ";
    }

    void inorder() {
        showInOrder(this->root);
    }

    void preorder() {
        showPreOrder(this->root);
    }

    void postorder() {
        showPostOrder(this->root);
    }

    int returnHeight(Node* root) {
        if(root == nullptr) return 0;
        
        int leftH = returnHeight(root->left);
        int rightH = returnHeight(root->right);

        return max(leftH, rightH) + 1;
    }
    

    int getHeight() {
        return returnHeight(this->root);
    }
};
int main() {
    Tree tree;
    int n, val;
    cout << "Enter no. of nodes : ";
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> val;
        tree.push(val);
    }

    cout << "Inorder Traversal of the tree" << endl;
    tree.inorder();
    cout << endl << endl;

    cout << "PreOrder traversal of the tree" << endl;
    tree.preorder();
    cout << endl << endl;

    cout << "PostOrder traversal of the tree" << endl;
    tree.postorder();
    cout << endl << endl;

    cout << "Height of the tree is " << tree.getHeight() << endl;
}