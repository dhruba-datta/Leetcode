class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> a0(n, 0), a1(n,0), a(n,0);
        int c0 =0, c1=0, x=0, len=0;
        
        for(auto i:nums){
            if(i==1) c1++;
            else c0++;
            a0[x] = c0;
            a1[x] = c1;
            x++;
        }
        if(a0[n-1]==a1[n-1]) return n;
        int i = n-1, j;
        for(i; i>=0; i--){
            a[i]= a0[i]- a1[i];
        }
        
        unordered_map<int, int>mp;
        for(int i=n-1; i>=0; i--){
            mp[a[i]]=i;
        }
        i = n-1;
        
        for(i; i>=0; i--){
            if(a0[i]==a1[i]) 
                len = max(len, i+1);
            if(mp.find(a[i]) != mp.end()){
                if((mp[a[i]]) != i)
                    len = max(len, i-mp[a[i]]);
            }
        }
        
        /*
        i = n-1;
        
        for(i; i>=0; i--){
            if(a0[i]==a1[i]) 
                len = max(len, i+1);
            j = i-1;
            while(j>=0){
                if(a[i] == (a[j])) 
                    len = max(len, i-j);
                j--;
            }
        }  
        */
        return len;
    }
};