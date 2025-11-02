#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
}TreeNode;

TreeNode* createTree(vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nums.size() && nums[i] != -1) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nums.size() && nums[i] != -1) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void showInOrder(TreeNode* root) {
    if(root == nullptr) return;
    showInOrder(root->left);
    cout << root->val << " ";
    showInOrder(root->right);
}

void showPreOrder(TreeNode* root) {
    if(root == nullptr) return;
    cout << root->val << " ";
    showPreOrder(root->left);
    showPreOrder(root->right);
}

void showPostOrder(TreeNode* root) {
    if(root == nullptr) return;
    showPostOrder(root->left);
    showPostOrder(root->right);
    cout << root->val << " ";
}

class Solution {
public:
    static int helper(TreeNode* root, int h, int& ans) {
        if(root == nullptr) return 0;

        int leftH = helper(root->left, h, ans);
        int rightH = helper(root->right, h, ans);

        ans = max(leftH + rightH, ans);

        return max(leftH, rightH) + 1;
    }
    static int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int h = helper(root, 0, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements in level order array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (-1 for null nodes): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    TreeNode* root = createTree(nums);

    cout << "\nInOrder Traversal: ";
    showInOrder(root);

    cout << endl;

    cout << "\nPreOrder Traversal: ";
    showPreOrder(root);

    cout << endl;

    cout << "\nPostOrder Traversal: ";
    showPostOrder(root);

    cout << endl;

    cout << "ans is " << Solution :: diameterOfBinaryTree(root);

    return 0;
}