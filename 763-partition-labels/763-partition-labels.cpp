class Solution {
public:
    vector<int> partitionLabels(string s)
    {
         int M[256]{0};   
         vector<int> out;

         for(int i{0}; i<size(s); ++i) M[s[i]]=i;

         for(int i{0}, j{-1}, MM{0}; i<size(s); ++i)
             if((MM = max(MM, M[s[i]]))==i)
                 out.push_back(i-j), j=i; 

         return out;
    }
};