//
//  10845.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 10..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//Queue using array
#include <iostream>
#include <string.h>

using namespace std;

//push X, pop, size, empty, front, back
int queue[10001];
//set pointer as index
int head, tail = 0;

int main(){
    
    int N, val;
    string command;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> command;
        
        if(command == "push"){
            cin >> val;
            queue[tail] = val;
            tail++;
        }
        else if(command == "pop"){
            if(head != tail){
                cout << queue[head] << '\n';
                head++;
            }
            else cout << -1 << '\n';
        }
        else if(command == "size"){
            
            cout << tail - head << '\n';
        }
        else if(command == "empty"){
            
            cout << (head == tail) << '\n';
        }
        else if(command == "front"){
            if(head != tail){
                cout << queue[head] << '\n';
            }
            else cout << -1 << '\n';
        }
        else if(command == "back"){
            if(head != tail){
                cout << queue[tail-1] << '\n';
            }
            else cout << -1 << '\n';
        }
//        else{
//            cout << "cmd error!";
//        }
        
    }
    
    
}
