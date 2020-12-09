 //
//  leet_23.cpp
//  algorithms
//
//  Created by 김혜진 on 2020. 10. 15..
//  Copyright © 2020년 김혜진. All rights reserved.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //using pq -> put el in sorted order in the output list
        //maxheap
        priority_queue<int> pq;
        for(int i = 0; i < lists.size(); i++){
            
            if(lists[i] == NULL) continue;
            
            ListNode *trav = lists[i];
            while(trav){ //until last el
                pq.push(trav->val);
                trav = trav->next;
            }
        }
        
        ListNode* output = new ListNode(0);
        
        while(!pq.empty()){
            ListNode *cur = new ListNode(pq.top());
            cur->next = output->next;
            output->next = cur;
            
            pq.pop();
        }
        
        if(!output->next) return NULL;
        return output->next;
        
    }
};
