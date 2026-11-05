#include "BST.h"
#include "TreeUtils.h"

BST::BST()
    : root(nullptr)
{
}

BST::~BST()
{
    destroy(root);
}

bool BST::insert(int value)
{
    bool inserted = false;
    root = insertInto(root, value, inserted);
    return inserted;
}

TreeNode* BST::insertInto(TreeNode* node, int value, bool& inserted)
{
    if (node == nullptr) {
        inserted = true;
        return makeNode(value);
    }
    if (value < node->data)
        node->left = insertInto(node->left, value, inserted);
    else if (value > node->data)
        node->right = insertInto(node->right, value, inserted);
    return node;
}

bool BST::find(int value) const
{
    const TreeNode* current = root;
    while (current != nullptr) {
        if (value == current->data)
            return true;
        current = value < current->data ? current->left : current->right;
    }
    return false;
}

bool BST::findMin(int& value) const
{
    if (root == nullptr)
        return false;
    const TreeNode* current = root;
    while (current->left != nullptr)
        current = current->left;
    value = current->data;
    return true;
}

bool BST::findMax(int& value) const
{
    if (root == nullptr)
        return false;
    const TreeNode* current = root;
    while (current->right != nullptr)
        current = current->right;
    value = current->data;
    return true;
}

bool BST::remove(int value)
{
    bool removed = false;
    root = removeFrom(root, value, removed);
    return removed;
}

TreeNode* BST::removeFrom(TreeNode* node, int value, bool& removed)
{
    if (node == nullptr)
        return nullptr;
    if (value < node->data) {
        node->left = removeFrom(node->left, value, removed);
        return node;
    }
    if (value > node->data) {
        node->right = removeFrom(node->right, value, removed);
        return node;
    }

    removed = true;
    if (node->left == nullptr || node->right == nullptr) {
        TreeNode* child = node->left != nullptr ? node->left : node->right;
        delete node;
        return child;
    }

    TreeNode* successor = node->right;
    while (successor->left != nullptr)
        successor = successor->left;
    node->data = successor->data;
    bool successorRemoved = false;
    node->right = removeFrom(node->right, successor->data, successorRemoved);
    return node;
}

void BST::preorder() const
{
    ::preorder(root);
}

void BST::inorder() const
{
    ::inorder(root);
}

void BST::postorder() const
{
    ::postorder(root);
}

int BST::height() const
{
    return ::height(root);
}

bool BST::isBalanced() const
{
    return ::isBalanced(root);
}

bool BST::isEmpty() const
{
    return root == nullptr;
}
