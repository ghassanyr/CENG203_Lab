#pragma once
#include <string>

struct ExprNode
{
    std::string data;
    ExprNode* left;
    ExprNode* right;
};

bool isOperator(const std::string& token);
ExprNode* buildFromPostfix(const std::string& postfix);
void printPrefix(const ExprNode* node);
void printPostfix(const ExprNode* node);
void printInfix(const ExprNode* node);
double evaluate(const ExprNode* node);
void destroyExpr(ExprNode* node);
