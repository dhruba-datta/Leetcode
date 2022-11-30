class Solution {
public:
bool uniqueOccurrences(vector<int>& arr) 
{
    unordered_map<int,int>freq,chk;
    
    
    //count frequency
    for(auto it:arr)
    {
        freq[it]++;
    }
    
    // check for frequency same or not
    for(auto it:freq)
    {
        if(chk.find(it.second)!=chk.end()) return false;
        else chk[it.second]++;
    }
    
    return true;
}
};