//
//  15651.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 20..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M;
int arr[10];
int isused[10];

void backtrack(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = 1; i < N+1; i++){
        arr[k] = i;
        backtrack(k+1);
    }
}

int main(){
    cin >> N >> M;
    
    backtrack(0);
}
