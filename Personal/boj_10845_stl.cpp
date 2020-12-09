//
//  10845_stl.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 10..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//Queue using STL
#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    queue<int> q;
    
    int N, val;
    string command;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> command;
        if(command == "push"){
            cin >> val;
            q.push(val);
        }
        else if(command == "pop"){
            if(q.empty()) cout << -1 << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(command == "size"){
            cout << q.size() << '\n';
        }
        else if(command == "empty"){
            cout << q.empty() << '\n';
        }
        else if(command == "front"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if(command == "back"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}
