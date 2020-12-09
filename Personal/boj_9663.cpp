//
//  9663.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 20..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
int N;
int isused_col[15];
int isused_tr[30]; //top-right
int isused_br[30]; //bottom-right
int cnt = 0;

using namespace std;

//idea : never put the queen on the same row
void nqueen(int row){
    if(row == N){
        cnt++;
        return;
    }
    
    for(int col = 0; col < N; col++){
        if(isused_col[col] || isused_tr[col + row] || isused_br[(N-1 - col) + row]) continue;
        
        isused_col[col] = 1;
        isused_tr[col + row] = 1;
        isused_br[(N-1 - col) + row] = 1;
        nqueen(row + 1);
        isused_col[col] = 0;
        isused_tr[col + row] = 0;
        isused_br[(N-1 - col) + row] = 0;
        
    }
    
}

int main(){
    cin >> N;
    nqueen(0);
    cout << cnt;
}
