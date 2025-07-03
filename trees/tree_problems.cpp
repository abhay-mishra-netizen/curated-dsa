// ===== Leetcode 230: Kth Smallest Element in a BST =====
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Approach: Inorder traversal (left-root-right), decrement k on visit.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class KthSmallestInBST {
public:
    void easy(TreeNode* root, int& k, int& save) {
        if (root == NULL) return;

        easy(root->left, k, save);
        k--;
        if (k == 0) {
            save = root->val;
            return;
        }
        easy(root->right, k, save);
    }

    int kthSmallest(TreeNode* root, int k) {
        int save = 0;
        easy(root, k, save);
        return save;
    }
};

// ===== Leetcode 437: Path Sum III =====
// https://leetcode.com/problems/path-sum-iii/
// Approach: For each node, do DFS to count paths with sum equal to targetSum

class PathSumIII {
public:
    void easy(TreeNode* root, int& target, long long targetsum) {
        if (root == NULL) return;

        long long remaining = targetsum - root->val;
        if (remaining == 0) target++;

        easy(root->left, target, remaining);
        easy(root->right, target, remaining);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;

        int target = 0;
        easy(root, target, (long long)targetSum);

        target += pathSum(root->left, targetSum);
        target += pathSum(root->right, targetSum);

        return target;
    }
};

// ===== Leetcode 199: Binary Tree Right Side View =====
// https://leetcode.com/problems/binary-tree-right-side-view/
// Approach: BFS level-order traversal, keep track of last node in each level.

class RightSideView {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        q.push(NULL);
        TreeNode* prev = NULL;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                if (prev) ans.push_back(prev->val);
                if (!q.empty()) q.push(NULL);
            } else {
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                prev = curr;
            }
        }

        return ans;
    }
};
