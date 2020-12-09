//
//  2447.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 18..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
#define mx 2200

int N;
int board[mx][mx];
int result[3] = {0, }; //-1 -> 0, 0 -> 1, 1 -> 2

void calNum(int n, int r, int c){
    if(n == 1){
        result[board[r][c] + 1]++;
        return;
    }
   
    for(int i = r; i < r + n; i++){
        for(int j = c; j < c + n; j++){
            if(board[i][j] != board[r][c]){
                for(int x = 0; x < 3; x++)
                    for(int y = 0; y < 3; y++)
                        calNum(n/3, r + n/3*x, c + n/3*y);
                return;
            }
        }
    }
    result[board[r][c] + 1]++;
    
}

int main(){
    std::cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            std::cin >> board[i][j];
    }
    calNum(N, 0, 0);
    
    for(int i = 0; i < 3; i++) std::cout << result[i] << '\n';
}
