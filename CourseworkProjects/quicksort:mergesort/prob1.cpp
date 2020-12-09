//
//  prob1.cpp
//  C++
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void printArray(int *array, int n){
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void quickSort(int *array, int low, int high){
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while(i <= j){
        while(array[i] < pivot)
            i++;
        while(array[j] > pivot)
            j--;
        if(i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if(j > low)
        quickSort(array, low, j);
    if(i < high)
        quickSort(array, i, high);
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
    
    char *array_unparsed = new char[num * 3];
    int *array = new int[num];
    
    scanf("%[^\n]s", array_unparsed);
    ctoiParser(num, array_unparsed, array);
    
    quickSort(array, 0, num-1);
    printArray(array, num);
    
    delete[] array_unparsed;
    delete[] array;
    
    return 0;
}
