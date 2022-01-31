class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if (numRows == 1) return s;
        
        int step = 2 * numRows - 2;
        
        for(int i=0; i<numRows; i++){
            if(i==0 || i==numRows-1){
                for(int j=i; j<s.size(); j+=step){
                     ans.push_back(s[j]);
                }
            }
            
            else{
                int j = i;
                bool flag = true;
                int step1 = 2 * (numRows - 1 - i);
                int step2 = step - step1;

                while (j < s.length()) {
                     ans.push_back(s[j]);
                    if (flag)
                        j = j + step1;
                    else
                        j = j + step2;
                    flag = !flag;
                }
            }
        }
        return ans;
    }
};
