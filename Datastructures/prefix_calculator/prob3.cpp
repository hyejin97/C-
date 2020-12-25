//
//  prob1.cpp
//  C++
//
//  Created by 김혜진 on 2020. 3. 23..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <stdexcept>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cmath>

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

bool isInteger(string value){
    char integers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for(int i = 0; i < value.size(); i++){
        int count = 0;
        for(int j = 0; j < 10; j++){
            if(value[i] == integers[j]) break;
            count++;
        }
        if(count == 10) return false;
    }
    return true;
    
}

void calPostfix(string *input, int inputlen){
    Stack<string> integers;
    Stack<string> operators;
    
    for(int i = 0; i < inputlen; i++){
        if(isInteger(input[i])) integers.push(input[i]);
        else{
            int integer1 = stoi(integers.top());
            integers.pop();
            int integer2 = stoi(integers.top());
            integers.pop();
            
            int result;
            if(input[i] == "+") result = integer2 + integer1;
            else if(input[i] == "-") result = integer2 - integer1;
            else if(input[i] == "*") result = integer2 * integer1;
            else if(input[i] == "/") result = floor(static_cast<double>(integer2) / static_cast<double>(integer1));
            
            integers.push(to_string(result));
        }
    }
    cout << integers.top() << endl;
    
}

int main(){
    int num;
    string input;
    
    cin >> num;
    cin.ignore();
    
    for(int i = 0; i < num; i++){
        getline(cin, input);
        string input_array[input.size()];
        
        int index = 0;
        for(int j = 0; j < input.size(); j++){
            if(input[j] != ' '){
                input_array[index] += input[j];
            }
            else index++;
        }
        input_array[index + 1] = '\0';
        
        calPostfix(input_array, index + 1);
    }
    
}


