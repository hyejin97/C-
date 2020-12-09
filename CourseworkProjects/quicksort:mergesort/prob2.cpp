//
//  prob2.cpp
//  C++
//
//  Created by 김혜진 on 2020. 4. 7..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define N   100

using namespace std;

void printArray(int *array, int n){
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge(int start, int end, int* arr){
    int mid = (start + end) / 2;
    
    int i = start;
    int j = mid + 1;
    
    int k = start;
    int tmp[N]; //temporary array for merging
    
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            tmp[k] = arr[i];
            i++;
        }
        else{
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    //add remaining elements
    int t = (i > mid) ? j : i;
    
    for(k; k <= end; k++, t++){
        tmp[k] = arr[t];
    }
    // 임시배열에서 원래 배열로 복사
    for(k = 0; k <= end; k++){
        arr[k] = tmp[k];
    }
    
}

void mergeSort(int start, int end, int*arr)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(start, mid, arr);
        mergeSort(mid + 1, end, arr);
        merge(start, end, arr);
    }
}

void ctoiParser(int num, char* array_unparsed, int* array){
    
    char* ptr;
    
    ptr = strtok(array_unparsed, " ");
    
    for(int i = 0; i < num; i++){
        array[i] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }
}

int main(){
    
    int num;
    
    cin >> num;
    cin.ignore();
    
    char array_unparsed[num * 3];
    int array[num];
    
    scanf("%[^\n]s", array_unparsed);
    ctoiParser(num, array_unparsed, array);
    
    mergeSort(0, num - 1, array);
    printArray(array, num);
    
    return 0;
}

