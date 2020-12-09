class RandomizedSet {
private:
    map<int, int> m;
    vector<int> v;
public:
    //each operation should run in AVERAGE O(1) time, the idea is to use hashmap storing the items.
    //however, to perform getRandom in the hashmap, we need to traverse all the indices in the hashmap and output one of them. This will take O(n)(n=size of hashmap)
    //so we keep an array that keeps track of items in hashmap and when performing the getRandom operation, we just select a random number among the numbers 0 - sizeofarray and pick the item in that index.
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end()){ //if not contained target val
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int targetidx = m[val];
            int lastval = v.back();
            
            //swap item with the last one and erase
            v[targetidx] = lastval;
            v.pop_back();
            
            //update map
            m[lastval] = targetidx;
            m.erase(val); //this should come at last for the case if only one item was remaining
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r_item = rand() % v.size();
        return v[r_item];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
