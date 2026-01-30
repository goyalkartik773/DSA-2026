#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int count = 0;
  int solve(TreeNode *root) {
    if (root == nullptr)
      return 1;

    int left = solve(root->left);
    int right = solve(root->right);
    if (left == 0 || right == 0) {
      // root ki jimadari hai ki wo camera lekar
      count += 1;
      return 2;
    } else if (left == 1 && right == 1) {
      return 0;
    } else if (left == 2 || right == 2) {
      return 1;
    }
    return 0;
  }
  int minCameraCover(TreeNode *root) {
    int x = solve(root);
    if (x == 0)
      count += 1; // root node needs to capture so put camera here
    return count;
  }
};