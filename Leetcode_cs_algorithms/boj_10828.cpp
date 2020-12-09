//
//  10828.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 7..
//  Copyright © 2020년 김혜진. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

//Stack using class and array

using namespace std;

//push, pop, size, empty, top
class Stack{
    
private:
    int size;
    int vals[10000];

public:
    Stack(){
        size = 0;
    }
    void push(int val){
        vals[size] = val;
        size++;

    }
    void pop(){
        if(size != 0){
            cout << vals[size - 1] << '\n';
            size--;
        }
        else cout << -1 << '\n';
    }
    int getsize(){
        return size;
    }
    int isempty(){
        return (size == 0);
    }
    int top(){
        if(size != 0) return vals[size - 1];
        else return -1;
    }
    
};

int main(){
    
    Stack s;
    char input[100010];
    string cmd[2];
    char *ptr;
    int N;
    
    cin >> N;
    
    cin.ignore();
    for(int i = 0; i < N; i++){
        cin.getline(input, 100010);
        
        //parse the input string
        ptr = strtok(input, " ");
        int idx = 0;
        
        while(ptr != NULL){
            cmd[idx] = ptr;
            ptr = strtok(NULL, " ");
            idx++;
        }

        //execute the command
        if(cmd[0] == "push"){
            s.push(stoi(cmd[1]));
        }
        else if(cmd[0] == "pop"){
            s.pop();
        }
        else if(cmd[0] == "size"){
            cout << s.getsize() << '\n';
        }
        else if(cmd[0] == "empty"){
            cout << s.isempty() << '\n';
        }
        else if(cmd[0] == "top"){
            cout << s.top() << '\n';
        }
        else{
            cout << "command error" << '\n';
            return -1;
        }
    }
    
    
}
