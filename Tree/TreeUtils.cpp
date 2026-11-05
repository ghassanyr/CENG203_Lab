#include "TreeUtils.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode* makeNode(int value)
{
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void preorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int countNodes(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int height(const TreeNode* node)
{
    if (node == nullptr)
        return -1;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void levelOrder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    queue<const TreeNode*> nodes;
    nodes.push(node);
    while (!nodes.empty()) {
        const TreeNode* current = nodes.front();
        nodes.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
            nodes.push(current->left);
        if (current->right != nullptr)
            nodes.push(current->right);
    }
}

bool isBalanced(const TreeNode* node)
{
    if (node == nullptr)
        return true;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int difference = leftHeight - rightHeight;
    if (difference < -1 || difference > 1)
        return false;
    return isBalanced(node->left) && isBalanced(node->right);
}

void destroy(TreeNode* node)
{
    if (node == nullptr)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
