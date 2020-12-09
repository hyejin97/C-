//
//  1629.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 17..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>

using namespace std;

long long divide(long long a, long long b, long long c){
    if(b == 1) return a % c;
    
    long long value = divide(a, b/2, c);
    value = value * value % c;
    
    if(b % 2 == 0) return value;
    else return value * a % c;
    
}

int main(){
    long long A, B, C;
    
    cin >> A >> B >> C;
    
    cout << divide(A, B, C);
}
