//
//  1074.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 18..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
int N, R, C;

int searchZ(int N, int r, int c){
    if(N == 0){
        return 0;
    }
    
    //which quadrant (r,c) is in
    int q = 1 << (N-1); //2^N / 2
    int count;
    if(r < q && c < q) count = searchZ(N-1, r, c);
    else if(r < q && c >= q) count = q * q + searchZ(N-1, r, c-q);
    else if(r >= q && c < q) count = q * q * 2 + searchZ(N-1, r-q, c);
    else count = q * q * 3 + searchZ(N-1, r-q, c-q);
    
    return count;
}

int main(){
    std::cin >> N >> R >> C;
    
    std::cout << searchZ(N, R, C) << '\n';
}
