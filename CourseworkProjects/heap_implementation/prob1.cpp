//
//  prob1.cpp
//  C++
//
//  Created by 김혜진 on 2020. 3. 27..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#define N   100

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    int key;
    int value;
};

//min heap
class Heap{
private:
    Node *heap;
    int standard_value;
    int index;
    
public:
    Heap(const int x, int cap);
    ~Heap();
    void Swap(Node* a, Node* b);
    void Insert(int input);
    void ShowKth(const int k);
};

Heap::Heap(const int x, int cap){
    heap = new Node[cap];
    standard_value = x;
    index = 0;
}

Heap::~Heap(){
    delete[] heap;
}

void Heap::Swap(Node* a, Node* b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void Heap::Insert(int input){
    index++;
    heap[index].value = input;
    heap[index].key = abs(standard_value - input);
    
    ////////////////////  upheap   //////////////////////
    int child_idx = index;
    int parent_idx = child_idx / 2;
    
    while(child_idx > 1 && heap[parent_idx].key >= heap[child_idx].key){
        //**if equal keys**//
        //make the smaller value become parent node
        if(heap[parent_idx].key == heap[child_idx].key && heap[parent_idx].value < heap[child_idx].value){
            child_idx = parent_idx;
            parent_idx = child_idx / 2;
            continue;
        }
        
        Swap(&heap[child_idx], &heap[parent_idx]);
        
        child_idx = parent_idx;
        parent_idx = child_idx / 2;
    }
    
}

void Heap::ShowKth(const int k){
    
    if(index < k) throw std::runtime_error("the number of inputs below K");
    
    Node *heap_tmp = new Node[index + 1];
    int index_tmp = index;
    for(int i = 1 ; i < index + 1; i++){
        heap_tmp[i].value = heap[i].value;
        heap_tmp[i].key = heap[i].key;
    }
    
    for(int i = 1; i < k; i++){
        
        Swap(&heap_tmp[1], &heap_tmp[index_tmp]);
        index_tmp--;
        
        ////////////////////  downheap   //////////////////////
        int parent_idx = 1;
        int child_idx = parent_idx * 2;
        
        //when have both left and right children
        if (child_idx + 1 <= index_tmp){
            //set the child_idx to the node with smaller key
            if(heap_tmp[child_idx].key > heap_tmp[child_idx + 1].key){
                child_idx = child_idx + 1;
            }
            //**if equal keys**//
            //set the child_idx to the node with smaller value
            else if(heap_tmp[child_idx].key == heap_tmp[child_idx + 1].key){
                if(heap_tmp[child_idx].value > heap_tmp[child_idx + 1].value){
                    child_idx = child_idx + 1;
                }
            }
        }
        
        while(child_idx <= index_tmp && heap_tmp[parent_idx].key > heap_tmp[child_idx].key){
            Swap(&heap_tmp[child_idx], &heap_tmp[parent_idx]);
            parent_idx = child_idx;
            child_idx = child_idx * 2;
            
            if (child_idx + 1 <= index_tmp){
                if(heap_tmp[child_idx].key > heap_tmp[child_idx + 1].key){
                    child_idx = child_idx + 1;
                }
                else if(heap_tmp[child_idx].key == heap_tmp[child_idx + 1].key){
                    if(heap_tmp[child_idx].value > heap_tmp[child_idx + 1].value){
                        child_idx = child_idx + 1;
                    }
                }
            }
        }
        ///////////////////////////////////////////////////////
    }
    
    int result = heap_tmp[1].value;
    
    cout << result << endl;
    
    delete[] heap_tmp;

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
