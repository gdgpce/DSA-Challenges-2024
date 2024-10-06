#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int s) {
        val = s;
        left = right = NULL;
    }
};

TreeNode* constructTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);  // First element is the root
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Function to find the height of the binary tree
int findHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    vector<int> arr1 = {5, 12, 25, -1, -1, 8, 10};
    vector<int> arr2 = {2, -1, 9};
    TreeNode* root1 = constructTree(arr1);
    cout << "Height of the binary tree 1: " << findHeight(root1) << endl;

    TreeNode* root2 = constructTree(arr2);
    cout << "Height of the binary tree 2: " << findHeight(root2) << endl;

    return 0;
}
