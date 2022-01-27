class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int sum = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        while(i >= 0 && j >= 0)
        {
            sum += (num1[i--] - '0') + (num2[j--] - '0');
            ans.push_back(char(sum%10 + '0'));
            sum = sum/10;
        }
        
        while(i >= 0)
        {
            sum += (num1[i--] - '0');
            ans.push_back(char(sum%10 + '0'));
            sum = sum/10;
        }
        
        while(j >= 0)
        {
            sum += (num2[j--] - '0');
            ans.push_back(char(sum%10 + '0'));
            sum = sum/10;
        }
        
        if(sum > 0)
            ans.push_back(char(sum%10 + '0'));
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};