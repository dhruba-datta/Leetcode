class RandomizedSet {
private:
    unordered_map<int, int> lookup;
    vector<int> nums;
    int vsize; // Virtual size of nums.
    
public:
    RandomizedSet() : vsize(0) {
        
    }
    
    bool insert(int val) {
        if (lookup.count(val))
            return false;
        
        ++vsize;
        if (vsize <= nums.size()) {
            nums[vsize - 1] = val;
        } else {
            nums.push_back(val);
        }
        
        lookup[val] = vsize - 1;
        return true;  
    }
    
    bool remove(int val) {
        auto itr = lookup.find(val);
        if (itr == lookup.end())
            return false;
        
		// Copy the last element to victim and remove the last element.
        int last = nums[vsize - 1];
        nums[itr->second] = last;
        lookup[last] = itr->second;
        
        --vsize;
        lookup.erase(itr);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % vsize];
    }
};