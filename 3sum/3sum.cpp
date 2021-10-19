class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
         if(n<3)
            return ans;
        int i=0, low=1, high=n-1, a=nums[0], b=0, c=0, x=0;
        while(i<n){
           if(nums[i]!=a){
                a= nums[i];
                high = n-1;
                low = i+1;
           }
            if(nums[i]==a && low<high){
                x=0-a;
               
                b=nums[low];
                c=nums[high];
                if(b+c==x)
                {
                    ans.push_back({a,b,c});
                    low++;
                    high--;
                    
                    while(low<n && b==nums[low]){
                        
                            low++;
                    }
                    while(high>=0 && b==nums[high]){
                        
                            high--;
                    }
                       
                   
                    continue;
                 
                }
                else if(b+c<x && low<n)
                   { low++;continue;}
                else if(b+c>x && high>=0)
                   { high--;continue;}
            }
            
            if(low>=high || (nums[i]==a && i>0))
                i++;
            
        }
       
        return ans;
    }
};