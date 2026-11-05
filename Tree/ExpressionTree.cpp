#include "ExpressionTree.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
using namespace std;

bool isOperator(const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

ExprNode* buildFromPostfix(const string& postfix)
{
    stack<ExprNode*> nodes;
    stringstream stream(postfix);
    string token;
    try {
        while (stream >> token) {
            ExprNode* node = new ExprNode{ token, nullptr, nullptr };
            if (isOperator(token)) {
                if (nodes.size() < 2) {
                    delete node;
                    throw runtime_error("Invalid postfix expression");
                }
                node->right = nodes.top();
                nodes.pop();
                node->left = nodes.top();
                nodes.pop();
            }
            nodes.push(node);
        }
        if (nodes.size() != 1)
            throw runtime_error("Invalid postfix expression");
        ExprNode* root = nodes.top();
        nodes.pop();
        return root;
    }
    catch (...) {
        while (!nodes.empty()) {
            destroyExpr(nodes.top());
            nodes.pop();
        }
        throw;
    }
}

void printPrefix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    printPrefix(node->left);
    printPrefix(node->right);
}

void printPostfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    printPostfix(node->left);
    printPostfix(node->right);
    cout << node->data << " ";
}

void printInfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    if (!isOperator(node->data)) {
        cout << node->data;
        return;
    }
    cout << "(";
    printInfix(node->left);
    cout << " " << node->data << " ";
    printInfix(node->right);
    cout << ")";
}

double evaluate(const ExprNode* node)
{
    if (node == nullptr)
        throw runtime_error("Invalid expression");
    if (!isOperator(node->data))
        return stod(node->data);

    double left = evaluate(node->left);
    double right = evaluate(node->right);
    if (node->data == "+")
        return left + right;
    if (node->data == "-")
        return left - right;
    if (node->data == "*")
        return left * right;
    if (right == 0.0)
        throw runtime_error("Division by zero");
    return left / right;
}

void destroyExpr(ExprNode* node)
{
    if (node == nullptr)
        return;
    destroyExpr(node->left);
    destroyExpr(node->right);
    delete node;
}
