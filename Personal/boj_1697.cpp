//
//  1697.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 14..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//bfs on 1-dim array
#include <iostream>
#include <queue>

using namespace std;

int N, K; // N : location of Subin(0 <= N <= 100000), K : location of her sister(0 <= N <= 100000)
// ** NOTE ** : location of Subin is not <= 100000
int dist[100010];

int main(){
    
    cin >> N >> K;
    
    fill(&dist[0], &dist[100010], -1);
    
    queue<int> q;
    dist[N] = 0;
    q.push(N);
    
    while(!q.empty()){

        int cur = q.front();
        q.pop();
        
        //**unfamiliar expression**//
        //range based for//
        for(int nx : {cur-1, cur+1, cur*2}){
            
            if(nx < 0 || nx > 100000) continue;
            //already min value
            if(dist[nx] != -1) continue;
            
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }
    cout << dist[K] << '\n';
}


