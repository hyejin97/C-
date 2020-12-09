
//
//  18808.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 25..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
using namespace std;

int N, M, K; //row, col, # of stickers
int laptop[41][41];
int sticker[11][11];

int paste(int x, int y, int r, int c){
    //check eligibility
    for(int i = x; i < x + r; i++){
        for(int j = y; j < y + c; j++){
            if(sticker[i-x][j-y] == 1 && laptop[i][j] == 1) return 0;
        }
    }
    
    //paste the sticker
    for(int i = x; i < x + r; i++){
        for(int j = y; j < y + c; j++){
            if(sticker[i-x][j-y] == 1) laptop[i][j] = 1;
        }
    }
    return 1;
}
//rotate the sticker 90 degree
void rotate(int* r, int* c){
    int tmp[11][11];
    for(int i = 0; i < *r; i++){
        for(int j = 0; j < *c; j++){
            tmp[i][j] = sticker[i][j];
        }
    }
    //////tricky part///////
    for(int i = 0; i < *c; i++){
        for(int j = 0; j < *r; j++){
            sticker[i][j] = tmp[*r - j - 1][i];
        }
    }
    //swap r and c
    int temp = *r;
    *r = *c;
    *c = temp;
}

int count(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(laptop[i][j] == 1) cnt++;
        }
    }
    return cnt;
}

int main(){
    int r, c;
    cin >> N >> M >> K;
    fill(&laptop[0][0], &laptop[N][M], 0);
    
    for(int k = 0; k < K; k++){
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> sticker[i][j];
            }
        }
        //check whether available and paste kth sticker
        for(int rot = 0; rot < 4; rot++){
            int ispos = 0;
            for(int x = 0; x <= N-r; x++){
                if(ispos) break;
                for(int y = 0; y <= M-c; y++){
                    if(paste(x, y, r, c)){
                        ispos = 1;
                        break;
                    }
                }
            }
            if(ispos) break;
            rotate(&r, &c);
        }
    }
    
    cout << count();
}

