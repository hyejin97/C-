//
//  prob2.cpp
//  C++
//
//  Created by 김혜진 on 2020. 3. 27..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#define N   100

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Heap{
private:
    vector<int> key;
    vector<int> value;
    int capacity;
    int standard_value;

public:
    Heap(const int x, int cap);
    ~Heap();
    void Insert(const int input);
    void ShowKth(const int k);
};

Heap::Heap(const int x, int cap) : capacity(cap), standard_value(x){
    key.reserve(cap);
    value.reserve(cap);
    key.push_back(0);
    value.push_back(standard_value);
}

Heap::~Heap(){
    
}

void Heap::Insert(int x){
    
    // if the vectors are full
    if (key.size() == capacity || value.size() == capacity){
        key.reserve(2*capacity);
        value.reserve(2*capacity);
    }
    
    // 마지막 노드에 element 추가
    int tmp_key = - abs(x - standard_value);
    key.push_back(tmp_key);
    value.push_back(x);
    
    // upheap
    push_heap(key.begin(), key.end());

}


void Heap::ShowKth(int k){
    
    if(key.size() < k) throw std::runtime_error("the number of inputs below K");
    
    // copy vectors
    vector<int> newheap(key);
    
    for(int i = 0; i < k; i++){
        
        // downheap
        pop_heap(newheap.begin(), newheap.end());
        
        // 마지막 노드 제거
        newheap.pop_back();
      
    }
    
    //** for same keys **//
    int cnt_biggervalue = 0;
    int cnt_smallervalue = 0;
    int cnt_samekey = 0;
    
    for (int j = 0; j < value.size() ; j++){
        if (value[j] == standard_value - newheap[0]){
            cnt_biggervalue++;
        }
        else if (value[j] == standard_value + newheap[0]){
            cnt_smallervalue++;
        }
    }
    for (int j = 0; j < newheap.size() ; j++){
        if (newheap[j] == newheap[0]){
            cnt_samekey++;
        }
    }
    
    if (cnt_samekey <= cnt_biggervalue){
        cout << standard_value - newheap[0] << endl;
    }
    else{
        cout << standard_value + newheap[0] << endl;
    }
    
    
    
}

int main(){
    // x : standard value, k : k-nearest-neighbor factor
    int x,k;
    string input;
    
    cin >> x >> k;
    Heap knn(x, N);
    
    while(true){
        cin.ignore();
        cin >> input;
        
        try{
            if(input == "SHOW_K_TH_NEIGHBOR"){
                knn.ShowKth(k);
            }
            else if(input == "EXIT"){
                return 0;
             }
            else{
                knn.Insert(stoi(input));
            }
        }
        catch(std::runtime_error& e){
            cout << e.what() << endl;
        }
    }
    
}


