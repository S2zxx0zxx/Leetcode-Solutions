class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> indexMap;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (indexMap.count(val)) return false;
        
        nums.push_back(val);
        indexMap[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!indexMap.count(val)) return false;
        
        int idx = indexMap[val];
        int lastVal = nums.back();
        
        nums[idx] = lastVal;
        indexMap[lastVal] = idx;
        
        nums.pop_back();
        indexMap.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */