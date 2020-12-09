//implementing binary search
#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int A[100000];

int binarysearch(int l, int u, int key){
    
    if(l <= u){
    
        int mid = (l + u) / 2;
        if(A[mid] > key) return binarysearch(l, mid-1, key);
        else if(A[mid] < key) return binarysearch(mid+1, u, key);
        else return 1;
    }
    return 0;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    cin >> M;
    int val;
    for(int i = 0; i < M; i++){
        cin >> val;
        cout << binarysearch(0, N-1, val) << '\n';
    }
}
