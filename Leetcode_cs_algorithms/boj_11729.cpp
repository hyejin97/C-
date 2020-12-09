//
//  11729.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 17..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
#include <complex>

using namespace std;

void toh(int n, int pos, int ring){
    if(n == 1){
        cout << pos << ' ' << ring << '\n';
        return;
    }
    
    int next = 6 - pos - ring;
    
    toh(n-1, pos, next);
    cout << pos << ' ' << ring << '\n';
    toh(n-1, next, ring);
}

int main(){
    ios::sync_with_stdio();
    cin.tie();
    
    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << '\n';
    toh(n, 1, 3);

}
