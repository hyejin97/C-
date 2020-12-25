//
//  1182.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 21..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>

using namespace std;

int intarray[20];
int N, S;
int cnt;

void partialarr(int n, int sum){
    if(n == N){
        if(sum == S) cnt++;
        return;
    }
    //two cases : add or not add item intarray[n]
    partialarr(n+1, sum);
    partialarr(n+1, sum + intarray[n]);

}

int main(){
    cin >> N >> S;
    
    for(int i = 0; i < N; i++) cin >> intarray[i];
    partialarr(0, 0);
    if(S == 0) cnt--;
    cout << cnt;
}
