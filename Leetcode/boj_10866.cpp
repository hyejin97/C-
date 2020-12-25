////
////  10866.cpp
////  C++
////
////  Created by 김혜진 on 2020. 9. 11..
////  Copyright © 2020년 김혜진. All rights reserved.
////
//
// deque using stl

#include <iostream>
#include <deque>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int N, val;
    string cmd;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd == "push_back"){
            cin >> val;
            dq.push_back(val);
        }
        else if(cmd == "push_front"){
            cin >> val;
            dq.push_front(val);
        }
        else if(cmd == "pop_front"){
            if(dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == "size"){
            cout << dq.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << dq.empty() << '\n';
        }
        else if(cmd == "front"){
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if(cmd == "back"){
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }

}


