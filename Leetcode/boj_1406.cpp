//
//  1406.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 5..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//Implementation of linked list with STL LIST

#include <string.h>
#include <iostream>
#include <list>

using namespace std;
//L : move the cursor to the left
//D : move the cursor to the right
//B : delete the character left to the cursor
//P : add the character at next to the curosr

int main(){
    std::ios::sync_with_stdio(0);
    
    list<char> editor = {};
    char inputstr[100000];
    int M;
    char command, $;
    
    cin >> inputstr;
    cin >> M;
    
    int inputlen = strlen(inputstr);
    for(int i = 0; i < inputlen; i++){
        editor.push_back(inputstr[i]);
    }
    list<char>::iterator cursor = editor.end();
    
    cin.ignore();
    for(int i = 0; i < M; i++){
        cin >> command;
        if(command == 'L'){
            if(cursor != editor.begin()) cursor--;
        }
        else if(command == 'D'){
            if(cursor != editor.end()) cursor++;
        }
        else if(command == 'B'){
            //erase
            if(cursor != editor.begin()){
                cursor--;
                cursor = editor.erase(cursor);
            }
        }
        else{
            cin >> $;
            //add $
            editor.insert(cursor, $);
        }
        
    }
    //print all the elements
    for(list<char>::iterator it = editor.begin(); it != editor.end(); it++){
        cout << *it;
    }
    cout << '\n';
}
