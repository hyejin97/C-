/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 Node* random;
 
 Node(int _val) {
 val = _val;
 next = NULL;
 random = NULL;
 }
 };
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //straightforward way : traverse the linkedlist twice. First update next pointers and then random pointers
        //optimized way : traverse the linkedlist once and update both next and random pointers using hashmap of <original node, copied node>
        if(!head) return NULL;
        
        map<Node*, Node*> m;
        map<Node*, Node*>::iterator it;
        
        Node* head_cp = new Node(head->val);
        m.insert({head, head_cp});
        
        Node* cur; //pointer for current node
        
        //update for next/random occurs only for the current node
        while(head){
            //update current node
            if((it = m.find(head)) == m.end()){
                Node* node = new Node(head->val);
                m.insert({head, node});
                cur = node;
            }
            else{
                cur = it->second;
            }
            
            //update next
            if((it = m.find(head->next)) == m.end() && head->next != NULL){ //if not in the map -> create new node and add to the map
                Node* node = new Node(head->next->val);
                m.insert({head->next, node});
                cur->next = node;
            }
            else if(it != m.end() && head->next != NULL){//if in the node -> add it to the next of current node
                cur->next = it->second;
            }
            
            //update random pointer
            if((it = m.find(head->random)) == m.end() && head->random != NULL){
                Node* node = new Node(head->random->val);
                m.insert({head->random, node});
                cur->random = node;
            }
            else if(it != m.end() && head->random != NULL){
                cur->random = it->second;
            }
            
            head = head->next;
            cur = cur->next;
        }
        return head_cp;
    }
};
