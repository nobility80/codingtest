#include "BinaryTree.h"
#include <iostream>

BinaryTreeLinkedList::BinaryTreeLinkedList() {}
BinaryTreeLinkedList::~BinaryTreeLinkedList() {}

Node* BinaryTreeLinkedList::CreateNode() {
    Node* newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bool BinaryTreeLinkedList::GetData(Node* node, int& data) {
    if (node == NULL)
        return false;

    data = node->data;
    printf("GetData:%d\n", data);
    return true;
}

bool BinaryTreeLinkedList::SetData(Node* node, int data) {
    if (node == NULL)
    return false;

    node->data = data;
    printf("SetData:%d\n", data);
    return true;
}

bool BinaryTreeLinkedList::GetLeftNode(Node* parent, Node** node) {
    if (parent == NULL || parent->left == NULL) {
        *node = NULL;
        return false;
    }

    *node = parent->left;
    printf("GetLeftNode:%d\n", (*node)->data);
    return true;
}

bool BinaryTreeLinkedList::GetRightNode(Node* parent, Node** node) {
    if (parent == NULL || parent->right == NULL) {
        *node = NULL;
        return false;
    }

    *node = parent->right;
    printf("GetRightNode:%d\n", (*node)->data);
    return true;
}

void BinaryTreeLinkedList::RemoveNode(Node* node) {
    if (node != NULL) {
        node->data = 0;
        RemoveNode(node->left);
        RemoveNode(node->right);
        printf("RemoveNode:%d\n", node->data);
        delete node;
    }
}

bool BinaryTreeLinkedList::SetLeftNode(Node* parent, Node** child) {
    if (parent == NULL || *child == NULL) {
        return false;
    }

//case 1. changing only value;
#ifdef __CHANGE_VALUE__
    if (parent->left != NULL) {
        parent->left->data = (*child)->data;
    }
#else
//case 2. changing value and pointer to 2 children
    if (parent->left != NULL) {
        RemoveNode(parent->left);
        parent->left = *child;
    }
#endif

    printf("SetLeftNode:%d\n", parent->left->data);
    return true;
}

bool BinaryTreeLinkedList::SetRightNode(Node* parent, Node** child) {
    if (parent == NULL || *child == NULL) {
        return false;
    }

//case 1. changing only value;
#ifdef __CHANGE_VALUE__
    if (parent->left != NULL) {
        parent->left->data = (*child)->data;
    }
#else
//case 2. changing value and pointer to 2 children
    if (parent->left != NULL) {
        RemoveNode(parent->left);
        parent->left = *child;
    }
#endif

    printf("SetLeftNode:%d\n", parent->left->data);
    return true;
}

void BinaryTreeLinkedList::PreorderPrint(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("pre:%d\n", node->data);
    PreorderPrint(node->left);
    PreorderPrint(node->right);
}

void BinaryTreeLinkedList::InorderPrint(Node* node) {
    if (node == NULL) {
        return;
    }

    InorderPrint(node->left);
    printf("In:%d\n", node->data);
    InorderPrint(node->right);
}

void BinaryTreeLinkedList::PostorderPrint(Node* node) {
    if (node == NULL) {
        return;
    }

    PostorderPrint(node->left);
    PostorderPrint(node->right);
    printf("post:%d\n", node->data);
}
