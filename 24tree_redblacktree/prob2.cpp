//
//  prob2.cpp
//  C++
//
//  Created by 김혜진 on 2020. 4. 6..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

enum Color { RED, BLACK, DOUBLE_BLACK };

struct Node{
    int data;
    int color;
    Node *left, *right, *parent;
    
    explicit Node(int);
};

Node::Node(int data){
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

class RBTree{
private:
    Node* root;
protected:
    Node* Insert(Node* &root, Node *&ptr);
    Node* Delete(Node* &root, int data);
    Node* minNode(Node* &node);
    
    void fixInsert(Node* &ptr);
    void fixDelete(Node* &node);
    
    int getColor(Node* &node);
    void setColor(Node* &node, int color);
    
    void Showtree(Node* &ptr);
    
    void rotateLeft(Node* &ptr);
    void rotateRight(Node* &ptr);
    
    int getBlackHeight(Node* node);
    
public:
    RBTree();
    void insertRBT(int);
    void deleteRBT(int);
    void showRBT();
};

RBTree::RBTree(){
    root = nullptr;
}

int RBTree::getColor(Node *&node){
    if (node == nullptr)
        return BLACK;
    return node->color;
}

void RBTree::setColor(Node *&node, int color){
    if (node == nullptr)
        return;
    node->color = color;
}

Node* RBTree::Insert(Node *&root, Node *&ptr){
    if (root == nullptr)
        return ptr;
    if (ptr->data == root->data)
        cout << ptr->data << " ALREADY EXISTS" << endl;
    if (ptr->data < root->data){
        root->left = Insert(root->left, ptr);
        root->left->parent = root;
    }
    else if (ptr->data > root->data){
        root->right = Insert(root->right, ptr);
        root->right->parent = root;
    }
    
    return root;
}

void RBTree::rotateLeft(Node *&ptr){
    Node *right_child = ptr->right;
    ptr->right = right_child->left;
    
    if (ptr->right != nullptr)
        ptr->right->parent = ptr;
    
    right_child->parent = ptr->parent;
    
    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;
    
    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBTree::rotateRight(Node *&ptr){
    Node *left_child = ptr->left;
    ptr->left = left_child->right;
    
    if (ptr->left != nullptr)
        ptr->left->parent = ptr;
    
    left_child->parent = ptr->parent;
    
    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;
    
    left_child->right = ptr;
    ptr->parent = left_child;
}

void RBTree::fixInsert(Node *&ptr){
    Node *parent = nullptr;
    Node *grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED){
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left){
            Node *uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else{
                if (ptr == parent->right){
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
        else{
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED){
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else{
                if (ptr == parent->left){
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}

void RBTree::fixDelete(Node *&node){
    if (node == nullptr)
        return;
    
    if (node == root){
        root = nullptr;
        return;
    }
    
    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED){
        Node *child = node->left != nullptr ? node->left : node->right;
        
        if (node == node->parent->left){
            node->parent->left = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
        else{
            node->parent->right = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    }
    else{
        Node *sibling = nullptr;
        Node *parent = nullptr;
        Node *ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK){
            parent = ptr->parent;
            if (ptr == parent->left){
                sibling = parent->right;
                if (getColor(sibling) == RED){
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                }
                else{
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK){
                        setColor(sibling, RED);
                        if (getColor(parent) == RED) setColor(parent, BLACK);
                        else setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else{
                        if (getColor(sibling->right) == BLACK){
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            }
            else {
                sibling = parent->left;
                if (getColor(sibling) == RED){
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                }
                else{
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK){
                        setColor(sibling, RED);
                        if (getColor(parent) == RED) setColor(parent, BLACK);
                        else setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else{
                        if (getColor(sibling->left) == BLACK){
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete(node);
        setColor(root, BLACK);
    }
}

Node* RBTree::Delete(Node *&root, int data){
    if (root == nullptr)
        return root;
    
    if (data < root->data)
        return Delete(root->left, data);
    
    if (data > root->data)
        return Delete(root->right, data);
    
    if (root->left == nullptr || root->right == nullptr)
        return root;
    
    Node *temp = minNode(root->right);
    if (root->data != data)
        cout << data << " NOT FOUND" << endl;
    root->data = temp->data;
    return Delete(root->right, temp->data);
}

void RBTree::Showtree(Node *&ptr){
    int depth = 0;
    char indent[6] = "    ";
    char id[100] = { '\0' };
    Node *s = ptr->parent;
    
    while (s != nullptr){
        depth++;
        s = s->parent;
    }
    
    for (int i = 0; i < depth; i++){
        strcat(id, indent);
    }
    
    //color: 0 red, 1 black
    if (ptr->color == 0)
        cout << id << ptr->data << " " << "(RED)" << endl;
    else
        cout << id << ptr->data << " " << "(BLACK)" << endl;
    
    //leaf
    strcat(id, indent);
    if (ptr->left != nullptr)
        Showtree(ptr->left);
    else
        cout << id << "LEAF" << " " << "(BLACK)" << endl;
    
    if (ptr->right != nullptr)
        Showtree(ptr->right);
    else
        cout << id << "LEAF" << " " << "(BLACK)" << endl;
    
}

Node *RBTree::minNode(Node *&node){
    
    Node *ptr = node;
    
    while (ptr->left != nullptr)
        ptr = ptr->left;
    return ptr;
}

int RBTree::getBlackHeight(Node *node){
    int h = 0;
    while (node != nullptr) {
        if (getColor(node) == BLACK)
            h++;
        node = node->left;
    }
    return h;
}

void RBTree::insertRBT(int n){
    Node *node = new Node(n);
    root = Insert(root, node);
    fixInsert(node);
}

void RBTree::deleteRBT(int data){
    Node *node = Delete(root, data);
    fixDelete(node);
}

void RBTree::showRBT(){
    if (root == nullptr) {
        cout << "NO KEYS" << endl;
        return;
    }
    Showtree(root);
}

int main(){
    int key;
    char input[20], c[20], k[20];
    RBTree rbtree;
    
    while (1){
        cin.getline(input, 20, '\n');
        sscanf(input, "%s %s", c, k);
        key = atoi(k);
        
        if (!strncmp(c, "INSERT", 6)) rbtree.insertRBT(key);
        else if (!strncmp(c, "DELETE", 6)) rbtree.deleteRBT(key);
        else if (!strncmp(c, "SHOWTREE", 8)) rbtree.showRBT();
        else if (!strncmp(c, "QUIT", 4)) exit(0);
    }
    return 0;
}
