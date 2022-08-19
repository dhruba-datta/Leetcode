class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int>left;   // key: number, val: how many of key are left unchecked
        unordered_map<int,int>seq;    // key: ending number, val: how many seqs
        for (auto x: nums)
            left[x]++;

        for (auto x: nums)
        {
            if (left[x]==0) continue;   // the number is already in seqs, we don't need to check again
			
            if (seq[x-1]>0)  // If there is sequence before the number, we add the number to the seq
            {                
                left[x]--;
                seq[x-1]-=1;
                seq[x]+=1;                
            }
            else   // If not we create a new seq using the number
            {
                if (left[x+1]==0 || left[x+2]==0)   //  If there aren't two numbers behind to let us create new seq, return False
                    return false;
                left[x]--;
                left[x+1]--;
                left[x+2]--;
                seq[x+2]+=1;
            }
        }
        return true;        
    }
};