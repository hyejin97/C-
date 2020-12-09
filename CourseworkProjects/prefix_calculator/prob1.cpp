//
//  prob1.cpp
//  C++
//
//  Created by 김혜진 on 2020. 3. 23..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class StackEmpty : public std::runtime_error{
    
public:
    explicit StackEmpty(const string& msg) : runtime_error(msg) {cout << "ERROR" << endl;}
    explicit StackEmpty(const char* msg) : runtime_error(msg) {cout << "ERROR" << endl;}
};

template<class E>
struct Node{
    E data;
    Node<E> *next;
    Node<E> *prev;
};

template<class E>
class Stack{

private:
    Node<E> *head;
    Node<E> *tail;
    int list_len;
    
public:
    Stack();
    ~Stack();
    
    size_t size() const;
    bool empty() const;
    const E& top() const throw(StackEmpty);
    void push(const E& e);
    void pop() throw(StackEmpty);
};

template<class E>
Stack<E>::Stack(){
    head = new Node<E>;
    tail = new Node<E>;
    head->next = tail;
    tail->prev = head;
    list_len = 0;
}

template<class E>
Stack<E>::~Stack(){
    for(int i = 0; i < size(); i++){
        pop();
    }
    delete head;
    delete tail;
}

template<class E>
size_t Stack<E>::size() const{
    return list_len;
}

template<class E>
bool Stack<E>::empty() const{
    if(list_len == 0) return true;
    else return false;
}

template<class E>
const E& Stack<E>::top() const throw(StackEmpty){
    try{
        if(empty()) throw StackEmpty("ERROR");
        else{
            return tail->prev->data;
        }
    }
    catch(std::runtime_error& e) {
        return NULL;
    }
}

template<class E>
void Stack<E>::push(const E& e){
    Node<E> *temp = new Node<E>;
    temp->data = e;
    
    temp->prev = tail->prev;
    tail->prev->next = temp;
    tail->prev = temp;
    temp->next = tail;
    
    list_len++;
}

template<class E>
void Stack<E>::pop() throw(StackEmpty){
    try{
        if(empty()) {throw StackEmpty("ERROR");}
        else{
            Node<E> *target = tail->prev;
            target->prev->next = tail;
            tail->prev = target->prev;

            delete target;
            list_len--;
        }
    }
    catch(std::runtime_error& e) {}
}

int main(){
    Stack<string> stack;
    
    string input, buf;
    string commands[2];
    
    while(1){
        getline(cin, input);
        stringstream pre_parse(input);
        
        for(int i = 0; i < 2; i++){
            if(pre_parse >> buf){
                commands[i] = buf;
            }
        }

        if(commands[0] == "QUIT"){
            return 0;
        }
        else if(commands[0] == "PUSH"){
            stack.push(commands[1]);
        }
        else if(commands[0] == "TOP"){
            cout << stack.top() << endl;
        }
        else if(commands[0] == "SIZE"){
            cout << stack.size() << endl;
        }
        else if(commands[0] == "POP"){
            stack.pop();
        }
        else if(commands[0] == "EMPTY"){
            if(stack.empty()) cout << "TRUE" << endl;
            else cout << "FALSE" << endl;
        }
        else{
            cout << "ERROR!" << endl;
            return -1;
        }
    }
    
}
