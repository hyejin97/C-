//
//  prob1.cpp
//  C++
//
//  Created by 김혜진 on 2020. 4. 6..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct Node{
    vector<int> data;
    Node *L, *M1, *M2, *M3, *R; // child pointers
    Node *P; // parent pointers

    explicit Node(int inputdata, Node* parent); // create root node
    explicit Node(int inputdata1, int inputdata2, Node* parent, Node* leftchild, Node* middlechild, Node* rightchild); // create node with three children
    explicit Node(int inputdata, Node* parent, Node* leftchild, Node* rightchild); // create node with two children
    
    int Findkeyindex(int k);
    bool isFull();
    bool isLeaf();
};

Node::Node(int inputdata, Node* parent){
    data.reserve(4);
    data.push_back(inputdata);
    L = M1 = M2 = M3 = R = NULL;
    P = parent;
}

Node::Node(int inputdata1, int inputdata2, Node* parent, Node* leftchild, Node* middlechild, Node* rightchild){
    data.reserve(4);
    data.push_back(inputdata1);
    data.push_back(inputdata2);
    L = leftchild;
    M1 = middlechild;
    M2 = rightchild;
    M3 = R = NULL;
    P = parent;
}

Node::Node(int inputdata, Node* parent, Node* leftchild, Node* rightchild){
    data.reserve(4);
    data.push_back(inputdata);
    L = leftchild;
    M1 = rightchild;
    M2 = M3 = R = NULL;
    P = parent;
}

int Node::Findkeyindex(int k){
    for (int i = 0; i < data.size(); i++){
        if (data[i] == k) return i;
    }
    return NULL;
}
bool Node::isFull(){
    return (data.size() == 4);
}
bool Node::isLeaf(){
    return (NULL == L && NULL == M1 && NULL == M2 && NULL == M3 && NULL == R);
}

class Tree_2_4{
public:
    Node* root; // 루트 노드
    
    Tree_2_4() { root = NULL; };
    ~Tree_2_4(){ delete root; };
    
    bool isInTree(int k);
    void Insert(int k);
    void Split(Node* parent, Node* n_ptr);
    void PrintNode(Node* &n_ptr);
    void Delete(int k);
    void Swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

bool Tree_2_4::isInTree(int input){
    Node* n_ptr = root;
    while(n_ptr){
        int idx = n_ptr->Findkeyindex(input);
        if (n_ptr->data[idx] == input) return true;
        
        // n_ptr의 key 개수 : 1
        if (n_ptr->data.size() == 1){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input > n_ptr->data[0]) n_ptr = n_ptr->M1;
        }
        // n_ptr의 key 개수 : 2
        else if (n_ptr->data.size() == 2){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input < n_ptr->data[1]) n_ptr = n_ptr->M1;
            else if (input > n_ptr->data[1]) n_ptr = n_ptr->M2;
        }
        // n_ptr의 key 개수 : 3
        else if (n_ptr->data.size() == 3){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input < n_ptr->data[1]) n_ptr = n_ptr->M1;
            else if (input < n_ptr->data[2]) n_ptr = n_ptr->M2;
            else if (input > n_ptr->data[2]) n_ptr = n_ptr->M3;
        }
    }
    return false;
}

void Tree_2_4::Insert(int input){
    // tree가 비어 있는 경우(root가 NULL)
    if (!root){
        root = new Node(input, NULL);
        return;
    }
    // input이 이미 tree에 있는 경우
    if (isInTree(input)){
        printf("%d ALREADY EXISTS\n", input);
        return;
    }
    Node* n_ptr = root;  // traversing pointer
    Node* parent = n_ptr;  // previous pointer
    
    // internal node이면 inorder traverse
    while (!n_ptr->isLeaf()){
        parent = n_ptr;
        // n_ptr의 key 개수 : 1
        if (n_ptr->data.size() == 1){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else n_ptr = n_ptr->M1;
        }
        // n_ptr의 key 개수 : 2
        else if (n_ptr->data.size() == 2){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input < n_ptr->data[1]) n_ptr = n_ptr->M1;
            else n_ptr = n_ptr->M2;
        }
        // n_ptr의 key 개수 : 3
        else if (n_ptr->data.size() == 3){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input < n_ptr->data[1]) n_ptr = n_ptr->M1;
            else if (input < n_ptr->data[2]) n_ptr = n_ptr->M2;
            else n_ptr = n_ptr->M3;
        }
    }
    
    // leaf node -> insert
    if (n_ptr->isLeaf()){
        if (n_ptr->data.size() == 1){
            if (input < n_ptr->data[0]){
                n_ptr->data.push_back(n_ptr->data[0]);
                n_ptr->data[0] = input;
            }
            else n_ptr->data.push_back(input);
            return;
        }
        else if (n_ptr->data.size() == 2){
            if (input < n_ptr->data[0]){
                n_ptr->data.push_back(n_ptr->data[1]);
                n_ptr->data[1] = n_ptr->data[0];
                n_ptr->data[0] = input;
            }
            else if (input < n_ptr->data[1]){
                n_ptr->data.push_back(n_ptr->data[1]);
                n_ptr->data[1] = input;
            }
            else n_ptr->data.push_back(input);
            return;
        }
        else{ //overflow
            if (input < n_ptr->data[0]){
                n_ptr->data.push_back(n_ptr->data[2]);
                n_ptr->data[2] = n_ptr->data[1];
                n_ptr->data[1] = n_ptr->data[0];
                n_ptr->data[0] = input;
            }
            else if (input < n_ptr->data[1]){
                n_ptr->data.push_back(n_ptr->data[2]);
                n_ptr->data[2] = n_ptr->data[1];
                n_ptr->data[1] = input;
            }
            else if (input < n_ptr->data[2]){
                n_ptr->data.push_back(n_ptr->data[2]);
                n_ptr->data[2] = input;
            }
            else n_ptr->data.push_back(input);
        }
    }
    // overflow -> split
    if (n_ptr->isFull()){
        while(n_ptr){
            if (n_ptr == root && n_ptr->data.size() == 4){
                Split(parent, n_ptr);
                n_ptr= root;
                break;
            }
            else if (n_ptr->isLeaf() && n_ptr->data.size() == 4){
                Split(parent, n_ptr);
                n_ptr = parent;
            }
            else if (!n_ptr->isLeaf() && n_ptr->data.size() == 4){
                Split(parent, n_ptr);
                n_ptr = parent;
            }
            else break;
        }
    }
}

void Tree_2_4::Split(Node* parent, Node* n_ptr){
    if (n_ptr == root){
        root = new Node(n_ptr->data[2], NULL);
        root->L = new Node(n_ptr->data[0], n_ptr->data[1], root, n_ptr->L, n_ptr->M1, n_ptr->M2);
        root->M1 = new Node(n_ptr->data[3], root, n_ptr->M3, n_ptr->R);
        if (n_ptr->L) n_ptr->L->P = root->L;
        if (n_ptr->M1) n_ptr->M1->P = root->L;
        if (n_ptr->M2) n_ptr->M2->P = root->L;
        if (n_ptr->M3) n_ptr->M3->P = root->M1;
        if (n_ptr->R) n_ptr->R->P = root->M1;
        delete n_ptr;
        return;
    }
    if (parent->data.size() == 1){
        if (parent->data[0] < n_ptr->data[2]){
            parent->data.push_back(n_ptr->data[2]);
            parent->M1 = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M2 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        else{
            parent->data.push_back(parent->data[0]);
            parent->M2 = parent->M1;
            parent->data[0] = n_ptr->data[2];
            parent->L = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M1 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        if (n_ptr->L) n_ptr->L->P = parent->L;
        if (n_ptr->M1) n_ptr->M1->P = parent->L;
        if (n_ptr->M2) n_ptr->M2->P = parent->L;
        if (n_ptr->M3) n_ptr->M3->P = parent->M1;
        if (n_ptr->R) n_ptr->R->P = parent->M1;
        delete n_ptr;
        return;
    }
    else if (parent->data.size() == 2){
        if (parent->data[1] < n_ptr->data[2]){
            parent->data.push_back(n_ptr->data[2]);
            parent->M2 = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M3 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        else if (parent->data[0] < n_ptr->data[2]){
            parent->data.push_back(parent->data[1]);
            parent->M3 = parent->M2;
            parent->data[1] = n_ptr->data[2];
            parent->M1 = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M2 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        else{
            parent->data.push_back(parent->data[1]);
            parent->M3 = parent->M2;
            parent->data[1] = parent->data[0];
            parent->M2 = parent->M1;
            parent->data[0] = n_ptr->data[2];
            parent->L = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M1 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        if (n_ptr->L) n_ptr->L->P = parent->L;
        if (n_ptr->M1) n_ptr->M1->P = parent->L;
        if (n_ptr->M2) n_ptr->M2->P = parent->L;
        if (n_ptr->M3) n_ptr->M3->P = parent->M1;
        if (n_ptr->R) n_ptr->R->P = parent->M1;
        delete n_ptr;
        return;
    }
    else if (parent->data.size() == 3){
        if (parent->data[2] < n_ptr->data[2]){
            parent->data.push_back(n_ptr->data[2]);
            parent->M3 = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->R = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        else if (parent->data[1] < n_ptr->data[2]){
            parent->data.push_back(parent->data[2]);
            parent->R = parent->M3;
            parent->data[2] = n_ptr->data[2];
            parent->M2 = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M3 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        else if (parent->data[0] < n_ptr->data[2]){
            parent->data.push_back(parent->data[2]);
            parent->R = parent->M3;
            parent->data[2] = parent->data[1];
            parent->M3 = parent->M2;
            parent->data[1] = n_ptr->data[2];
            parent->M1 = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M2 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        else{
            parent->data.push_back(parent->data[2]);
            parent->R = parent->M3;
            parent->data[2] = parent->data[1];
            parent->M3 = parent->M2;
            parent->data[1] = parent->data[0];
            parent->M2 = parent->M1;
            parent->data[0] = n_ptr->data[2];
            parent->L = new Node(n_ptr->data[0], n_ptr->data[1], parent, n_ptr->L, n_ptr->M1, n_ptr->M2);
            parent->M1 = new Node(n_ptr->data[3], parent, n_ptr->M3, n_ptr->R);
        }
        if (n_ptr->L) n_ptr->L->P = parent->L;
        if (n_ptr->M1) n_ptr->M1->P = parent->L;
        if (n_ptr->M2) n_ptr->M2->P = parent->L;
        if (n_ptr->M3) n_ptr->M3->P = parent->M1;
        if (n_ptr->R) n_ptr->R->P = parent->M1;
        delete n_ptr;
    }
}

void Tree_2_4::PrintNode(Node *&n_ptr){
    if (!root) {
        cout << "NO KEYS" << endl;
        return;
    }
    static int h = 0;
    for (int i = 0; i < h; i++){
        printf("    ");
    }
    for (int i = 0; i < n_ptr->data.size(); i++){
        if (i == n_ptr->data.size() - 1){
            printf("%d\n", n_ptr->data[i]);
        }
        else if (i == 0 && n_ptr->data.size() == 1){
            printf("%d", n_ptr->data[i]);
        }
        else{
            printf("%d,", n_ptr->data[i]);
        }
    }
    vector<Node*> children;
    children.reserve(4);
    if (n_ptr->L) children.push_back(n_ptr->L);
    if (n_ptr->M1) children.push_back(n_ptr->M1);
    if (n_ptr->M2) children.push_back(n_ptr->M2);
    if (n_ptr->M3) children.push_back(n_ptr->M3);
    if (n_ptr->R) children.push_back(n_ptr->R);
    for (int i = 0; i < children.size(); i++){
        ++h;
        PrintNode(children[i]);
        --h;
    }
}

void Tree_2_4::Delete(int input){
    Node* n_ptr = root;  // traversing pointer
    
    if (!isInTree(input)){
        printf("%d NOT FOUND\n", input);
        return;
    }
    
    //** find key **//
    while(n_ptr){
        int idx = n_ptr->Findkeyindex(input);
        if (n_ptr->data[idx] == input) break;
        
        // n_ptr의 key 개수 : 1
        if (n_ptr->data.size() == 1){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input > n_ptr->data[0]) n_ptr = n_ptr->M1;
        }
        // n_ptr의 key 개수 : 2
        else if (n_ptr->data.size() == 2){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input < n_ptr->data[1]) n_ptr = n_ptr->M1;
            else if (input > n_ptr->data[1]) n_ptr = n_ptr->M2;
        }
        // n_ptr의 key 개수 : 3
        else if (n_ptr->data.size() == 3){
            if (input < n_ptr->data[0]) n_ptr = n_ptr->L;
            else if (input < n_ptr->data[1]) n_ptr = n_ptr->M1;
            else if (input < n_ptr->data[2]) n_ptr = n_ptr->M2;
            else if (input > n_ptr->data[2]) n_ptr = n_ptr->M3;
        }
    }
    
    //** delete **//
    // leaf
    if (n_ptr->isLeaf()){
        int idx = n_ptr->Findkeyindex(input);
        n_ptr->data.erase(n_ptr->data.begin() + idx);
    }
    
    // internal node => inorder successor
    else{
        Node* target = n_ptr; // 찾은 key 노드 저장
        if (n_ptr->data.size() == 1) n_ptr = n_ptr->M1;
        else if (n_ptr->data.size() == 2 && n_ptr->Findkeyindex(input) == 0) n_ptr = n_ptr->M1;
        else if (n_ptr->data.size() == 2 && n_ptr->Findkeyindex(input) == 1) n_ptr = n_ptr->M2;
        else if (n_ptr->data.size() == 3 && n_ptr->Findkeyindex(input) == 0) n_ptr = n_ptr->M1;
        else if (n_ptr->data.size() == 3 && n_ptr->Findkeyindex(input) == 1) n_ptr = n_ptr->M2;
        else if (n_ptr->data.size() == 3 && n_ptr->Findkeyindex(input) == 2) n_ptr = n_ptr->M3;
        
        while (!n_ptr->isLeaf()){
            n_ptr = n_ptr->L;
        }
        int idx = target->Findkeyindex(input);
        Swap(&target->data[idx], &n_ptr->data[0]);
        n_ptr->data.erase(n_ptr->data.begin());
    }
    
    // ** underflow **//
    while (n_ptr->data.size() == 0){
        if (n_ptr == root){
            root = n_ptr->L;
            delete n_ptr;
            return;
        }
        Node* parent = n_ptr->P;
        vector<Node*> parent_child;
        parent_child.reserve(4);
        int index = 0;
        if (parent->L) parent_child.push_back(parent->L);
        if (parent->M1) parent_child.push_back(parent->M1);
        if (parent->M2) parent_child.push_back(parent->M2);
        if (parent->M3) parent_child.push_back(parent->M3);
        if (parent->R) parent_child.push_back(parent->R);
        for (int i = 0; i < parent_child.size(); i++){
            if (n_ptr == parent_child[i]) {
                index = i;
                break;
            }
        }
        Node* left = parent_child[index - 1]; // left sibling
        Node* right = parent_child[index + 1]; // right sibling
        
        if (parent->data.size() == 1){
            // left sibling
            if (index >= 1){
                if (left->data.size() == 1){ // fusion
                    parent->L = new Node(parent->L->data[0], parent->data[0], parent, parent->L->L, parent->L->M1, n_ptr->L);
                    if (parent->L->L) parent->L->L->P = parent->L;
                    if (parent->L->M1) parent->L->M1->P = parent->L;
                    if (n_ptr->L) n_ptr->L->P = parent->L;
                    parent->data.pop_back();
                    parent->M1 = NULL;
                    delete n_ptr;
                    n_ptr = parent;
                }
                else if (left->data.size() == 2){ // transfer
                    n_ptr->M1 = n_ptr->L;
                    n_ptr->L = parent->L->M2;
                    if (parent->L->M2) parent->L->M2->P = n_ptr;
                    parent->L->M2 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.pop_back();
                    parent->data.insert(parent->data.begin(), parent->L->data[1]);
                    parent->L->data.pop_back();
                    return;
                }
                else if (left->data.size() == 3){ // transfer
                    n_ptr->M1 = n_ptr->L;
                    n_ptr->L = parent->L->M3;
                    if (parent->L->M3) parent->L->M3->P = n_ptr;
                    parent->L->M3 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.pop_back();
                    parent->data.insert(parent->data.begin(), parent->L->data[2]);
                    parent->L->data.pop_back();
                    return;
                }
            }
            // right sibling
            else{
                if (right->data.size() == 1){
                    parent->L = new Node(parent->data[0], parent->M1->data[0], parent, n_ptr->L, parent->M1->L, parent->M1->M1);
                    if (n_ptr->L) n_ptr->L->P = parent->L;
                    if (parent->M1->L) parent->M1->L->P = parent->L;
                    if (parent->M1->M1) parent->M1->M1->P = parent->L;
                    parent->data.pop_back();
                    parent->M1 = NULL;
                    delete n_ptr;
                    n_ptr = parent;
                }
                else if (right->data.size() == 2){
                    n_ptr->M1 = parent->M1->L;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    parent->M1->L = parent->M1->M1;
                    parent->M1->M1 = parent->M1->M2;
                    parent->M1->M2 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.pop_back();
                    parent->data.insert(parent->data.begin(), parent->M1->data[0]);
                    parent->M1->data.erase(parent->R->data.begin());
                    return;
                }
                else if (right->data.size() == 3){
                    n_ptr->M1 = parent->M1->L;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    parent->M1->L = parent->M1->M1;
                    parent->M1->M1 = parent->M1->M2;
                    parent->M1->M2 = parent->M1->M3;
                    parent->M1->M3 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.pop_back();
                    parent->data.insert(parent->data.begin(), parent->M1->data[0]);
                    parent->M1->data.erase(parent->R->data.begin());
                    return;
                }
            }
        }
        else if (parent->data.size() == 2){
            if (index >= 1){ //fusion
                if (left->data.size() == 1){
                    if (index == 2) {
                        parent->M1 = new Node(parent->M1->data[0], parent->data[1], parent, parent->M1->L, parent->M1->M1, n_ptr->L);
                        if (parent->M1->L) parent->M1->L->P = parent->M1;
                        if (parent->M1->M1) parent->M1->M1->P = parent->M1;
                        if (n_ptr->L) n_ptr->L->P = parent->M1;
                        parent->data.pop_back();
                        parent->M2 = NULL;
                    }
                    else{
                        parent->L = new Node(parent->L->data[0], parent->data[0], parent, parent->L->L, parent->L->M1, n_ptr->L);
                        if (parent->L->L) parent->L->L->P = parent->L;
                        if (parent->L->M1) parent->L->M1->P = parent->L;
                        if (n_ptr->L) n_ptr->L->P = parent->L;
                        parent->data.erase(parent->data.begin());
                        parent->M1 = parent->M2;
                        parent->M2 = NULL;
                    }
                    delete n_ptr;
                    n_ptr = parent;
                }
                else if (left->data.size() == 2){ // transfer
                    if (index == 2) {
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->M1->M2;
                        if (parent->M1->M2) parent->M1->M2->P = n_ptr;
                        parent->M1->M2 = NULL;
                        n_ptr->data.push_back(parent->data[1]);
                        parent->data.pop_back();
                        parent->data.push_back(parent->M1->data[1]);
                        parent->M1->data.pop_back();
                    }
                    else {
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->L->M2;
                        if (parent->L->M2) parent->L->M2->P = n_ptr;
                        parent->L->M2 = NULL;
                        n_ptr->data.push_back(parent->data[0]);
                        parent->data.erase(parent->data.begin());
                        parent->data.insert(parent->data.begin(), parent->L->data[1]);
                        parent->L->data.pop_back();
                    }
                    return;
                }
                else if (left->data.size() == 3){
                    if (index == 2) {
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->M1->M3;
                        if (parent->M1->M3) parent->M1->M3->P = n_ptr;
                        parent->M1->M3 = NULL;
                        n_ptr->data.push_back(parent->data[1]);
                        parent->data.pop_back();
                        parent->data.push_back(parent->M1->data[2]);
                        parent->M1->data.pop_back();
                    }
                    else {
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->L->M3;
                        if (parent->L->M3) parent->L->M3->P = n_ptr;
                        parent->L->M3 = NULL;
                        n_ptr->data.push_back(parent->data[0]);
                        parent->data.erase(parent->data.begin());
                        parent->data.insert(parent->data.begin(), parent->L->data[2]);
                        parent->L->data.pop_back();
                    }
                    return;
                }
            }
            else{ // right sibling : underflow => 맨 왼쪽일 경우
                if (right->data.size() == 1){ //fusion
                    n_ptr = new Node(parent->data[0], parent->M1->data[0], parent, n_ptr->L, parent->M1->L, parent->M1->M1);
                    if (n_ptr->L) n_ptr->L->P = n_ptr;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    if (parent->M1->M1) parent->M1->M1->P = n_ptr;
                    parent->data.erase(parent->data.begin());
                    parent->M1 = parent->M2;
                    parent->M2 = NULL;
                    delete n_ptr;
                    n_ptr = parent;
                }
                else if (right->data.size() == 2){ // transfer
                    n_ptr->M1 = parent->M1->L;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    parent->M1->L = parent->M1->M1;
                    parent->M1->M1 = parent->M1->M2;
                    parent->M1->M2 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.erase(parent->data.begin());
                    parent->data.insert(parent->data.begin(), parent->M1->data[0]);
                    parent->M1->data.erase(parent->M1->data.begin());
                    return;
                }
                else if (right->data.size() == 3){
                    n_ptr->M1 = parent->M1->L;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    parent->M1->L = parent->M1->M1;
                    parent->M1->M1 = parent->M1->M2;
                    parent->M1->M2 = parent->M1->M3;
                    parent->M1->M3 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.erase(parent->data.begin());
                    parent->data.insert(parent->data.begin(), parent->M1->data[0]);
                    parent->M1->data.erase(parent->M1->data.begin());
                    return;
                }
            }
        }
        else if (parent->data.size() == 3){
            if (index >= 1){
                if (left->data.size() == 1){ //fusion
                    if (index == 3){
                        parent->M2 = new Node(parent->M2->data[0], parent->data[2], parent, parent->M2->L, parent->M2->M1, n_ptr->L);
                        if (parent->M2->L) parent->M2->L->P = parent->M2;
                        if (parent->M2->M1) parent->M2->M1->P = parent->M2;
                        if (n_ptr->L) n_ptr->L->P = parent->M2;
                        parent->data.pop_back();
                        parent->M3 = NULL;
                    }
                    else if (index == 2){
                        parent->M1 = new Node(parent->M1->data[0], parent->data[1], parent, parent->M1->L, parent->M1->M1, n_ptr->L);
                        if (n_ptr->L) n_ptr->L->P = parent->M1;
                        parent->data.erase(parent->data.end()-1);
                        parent->M2 = parent->M3;
                        parent->M3 = NULL;
                    }
                    else{
                        parent->L = new Node(parent->L->data[0], parent->data[0], parent, parent->L->L, parent->L->M1, n_ptr->L);
                        if (n_ptr->L) n_ptr->L->P = parent->L;
                        parent->data.erase(parent->data.end()-2);
                        parent->M1 = parent->M2;
                        parent->M2 = parent->M3;
                        parent->M3 = NULL;
                    }
                    delete n_ptr;
                    n_ptr = parent;
                }
                else if (left->data.size() == 2){ // transfer
                    if (index == 3){
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->M2->M2;
                        if (parent->M2->M2) parent->M2->M2->P = n_ptr;
                        parent->M2->M2 = NULL;
                        n_ptr->data.push_back(parent->data[2]);
                        parent->data.pop_back();
                        parent->data.push_back(parent->M2->data[1]);
                        parent->M2->data.pop_back();
                    }
                    else if (index == 2){
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->M1->M2;
                        if (parent->M1->M2) parent->M1->M2->P = n_ptr;
                        parent->M1->M2 = NULL;
                        n_ptr->data.push_back(parent->data[1]);
                        parent->data.erase(parent->data.end()-1);
                        parent->data.insert(parent->data.end()-1, parent->M1->data[1]);
                        parent->M1->data.pop_back();
                    }
                    else{
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->L->M2;
                        if (parent->L->M2) parent->L->M2->P = n_ptr;
                        parent->L->M2 = NULL;
                        n_ptr->data.push_back(parent->data[0]);
                        parent->data.erase(parent->data.end()-2);
                        parent->data.insert(parent->data.end()-2, parent->L->data[1]);
                        parent->L->data.pop_back();
                    }
                }
                else if (left->data.size() == 3){
                    if (index == 3){
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->M2->M3;
                        if (parent->M2->M3) parent->M2->M3->P = n_ptr;
                        parent->M2->M3 = NULL;
                        n_ptr->data.push_back(parent->data[2]);
                        parent->data.pop_back();
                        parent->data.push_back(parent->M2->data[2]);
                        parent->M2->data.pop_back();
                    }
                    else if (index == 2){
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->M1->M3;
                        if (parent->M1->M3) parent->M1->M3->P = n_ptr;
                        parent->M1->M3 = NULL;
                        n_ptr->data.push_back(parent->data[1]);
                        parent->data.erase(parent->data.end()-1);
                        parent->data.insert(parent->data.end()-1, parent->M1->data[2]);
                        parent->M1->data.pop_back();
                    }
                    else{
                        n_ptr->M1 = n_ptr->L;
                        n_ptr->L = parent->L->M3;
                        if (parent->L->M3) parent->L->M3->P = n_ptr;
                        parent->L->M3 = NULL;
                        n_ptr->data.push_back(parent->data[0]);
                        parent->data.erase(parent->data.end()-2);
                        parent->data.insert(parent->data.end()-2, parent->L->data[2]);
                        parent->L->data.pop_back();
                    }
                }
            }
            else{ // right sibling : underflow => 맨 왼쪽일 경우
                if (right->data.size() == 1){ // fusion
                    n_ptr = new Node(parent->data[0], parent->M1->data[0], parent, n_ptr->L, parent->M1->L, parent->M1->M1);
                    if (n_ptr->L) n_ptr->L->P = n_ptr;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    if (parent->M1->M1) parent->M1->M1->P = n_ptr;
                    parent->data.erase(parent->data.begin());
                    parent->M1 = parent->M2;
                    parent->M2 = parent->M3;
                    parent->M3 = NULL;
                    n_ptr = parent;
                }
                else if (right->data.size() == 2){ //transfer
                    n_ptr->M1 = parent->M1->L;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    parent->M1->L = parent->M1->M1;
                    parent->M1->M1 = parent->M1->M2;
                    parent->M1->M2 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.erase(parent->data.begin());
                    parent->data.insert(parent->data.begin(), parent->M1->data[0]);
                    parent->M1->data.erase(parent->M1->data.begin());
                    return;
                }
                else if (right->data.size() == 3){
                    n_ptr->M1 = parent->M1->L;
                    if (parent->M1->L) parent->M1->L->P = n_ptr;
                    parent->M1->L = parent->M1->M1;
                    parent->M1->M1 = parent->M1->M2;
                    parent->M1->M2 = parent->M1->M3;
                    parent->M1->M3 = NULL;
                    n_ptr->data.push_back(parent->data[0]);
                    parent->data.erase(parent->data.begin());
                    parent->data.insert(parent->data.begin(), parent->M1->data[0]);
                    parent->M1->data.erase(parent->M1->data.begin());
                    return;
                }
            }
        }
    }
}

int main(){
    Tree_2_4 tree;
    char input[10];
    char* key;
    
    while (1){
        cin.getline(input, 10, '\n');
        char* order = strtok_r(input, " ", &key);
        if (strncmp(order, "INSERT", 6) == 0) tree.Insert(stoi(key));
        else if (strncmp(order, "DELETE", 6) == 0) tree.Delete(stoi(key));
        else if (strncmp(order, "SHOWTREE", 7) == 0) tree.PrintNode(tree.root);
        else if (strncmp(order, "QUIT", 4) == 0) return 0;
    }
}

