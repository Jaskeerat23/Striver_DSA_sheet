#include<iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
public:
    int val;
    struct Node* left;
    struct Node* right;
    
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
    Node(int val, struct Node* right, struct Node* left) : val(val), right(right), left(left) {}
}Node;

Node* addNode(struct Node* root, int val) {
    Node* newNode = new Node(val);
    // cout << "new node created\n";
    if(root == nullptr) { 
        root = newNode;
        // cout << "Condition met\n";
        return root;
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
    return root;
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

class Solution {
public:
    static vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*, int>> q;
        vector<vector<int>> ans;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            pair<Node*, int> poped = q.front();
            q.pop();

            if(ans.size() == poped.second) {
                ans.push_back({});
            }
            
            ans[poped.second].push_back(poped.first->val);

            if(poped.first->left != nullptr)
                q.push({poped.first->left, poped.second + 1});
            if(poped.first->right != nullptr)
                q.push({poped.first->right, poped.second + 1});
        }
        return ans;
    }
};

int main() {
    Node* root = nullptr;
    int n, val;
    cout << "Enter no. of nodes : ";
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> val;
        root = addNode(root, val);
    }

    cout << "Inorder Traversal of the root" << endl;
    showInOrder(root);
    cout << endl << endl;

    cout << "PreOrder traversal of the root" << endl;
    showPreOrder(root);
    cout << endl << endl;

    cout << "PostOrder traversal of the root" << endl;
    showPostOrder(root);
    cout << endl << endl;

    vector<vector<int>> ans = Solution :: levelOrder(root);

    for(const auto& it1 : ans) {
        for(const auto& it2 : it1) cout << it2 << " ";
        cout << endl;
    }
}