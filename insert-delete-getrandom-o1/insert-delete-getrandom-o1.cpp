class RandomizedSet {
public:
    vector<int>a;
    unordered_map<int, int> mp;
    
    /** Initialize your data structure here. */
    RandomizedSet() { }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {   
        auto it=mp.find(val);
        if(it == mp.end())
        {
            a.push_back(val);
            mp[val]=a.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it=mp.find(val);
        if(it != mp.end())
        {
            a[it->second]=a.back();
            a.pop_back();
            mp[a[it->second]]=it->second;
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return a[rand()%a.size()];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */