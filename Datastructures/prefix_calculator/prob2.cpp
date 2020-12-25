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

//** operator priority **//
// '+', '-' == 1
// '*', '/' == 2
int calPriority(string op){
    if(op == "(") return 0;
    else if(op == "+" || op == "-") return 1;
    else if(op == "*" || op == "/") return 2;
    else return -1;
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

void printPostfix(string *input, int inputlen){
    Stack<string> stack;
    stack.push("#");
    for(int i = 0; i < inputlen; i++){
        // if operand, print
        if(isInteger(input[i])){
            cout << input[i] << " ";
        }
        // if open parenthesis, push to the stack
        else if(input[i] == "("){
            stack.push(input[i]);
        }
        // if closed parenthesis, pop the operators until meeting open parenthesis
        else if(input[i] == ")"){
            while(stack.top() != "("){
                cout << stack.top() << " ";
                stack.pop();
            }
            stack.pop();
        }
        // else, stack up the operators by their priority
        else if(input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/"){
            while(calPriority(stack.top()) >= calPriority(input[i])){
                cout << stack.top() << " ";
                stack.pop();
            }
            stack.push(input[i]);
        }
        else cout << "unknown value" << endl;
    }
    // print all the remaining operators in the stack
    while(!stack.empty()){
        if(stack.top() == "#") stack.pop();
        else{
            cout << stack.top() << " ";
            stack.pop();
        }
    }
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

        printPostfix(input_array, index + 1);
        cout << endl;
    }
    
}

