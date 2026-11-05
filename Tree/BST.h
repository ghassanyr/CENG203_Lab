#pragma once
#include "TreeNode.h"

class BST
{
private:
    TreeNode* root;

    static TreeNode* insertInto(TreeNode* node, int value, bool& inserted);
    static TreeNode* removeFrom(TreeNode* node, int value, bool& removed);

public:
    BST();
    ~BST();

    bool insert(int value);
    bool find(int value) const;
    bool findMin(int& value) const;
    bool findMax(int& value) const;
    bool remove(int value);

    void preorder() const;
    void inorder() const;
    void postorder() const;
    int height() const;
    bool isBalanced() const;
    bool isEmpty() const;
};
