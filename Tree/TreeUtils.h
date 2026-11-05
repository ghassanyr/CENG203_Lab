#pragma once
#include "TreeNode.h"

void preorder(const TreeNode* node);
void inorder(const TreeNode* node);
void postorder(const TreeNode* node);
int countNodes(const TreeNode* node);
int countLeaves(const TreeNode* node);
int height(const TreeNode* node);
void levelOrder(const TreeNode* node);
bool isBalanced(const TreeNode* node);
void destroy(TreeNode* node);
