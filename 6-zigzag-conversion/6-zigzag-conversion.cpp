class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if (numRows == 1) return s;
        
        for (int row = 0; row < numRows; row++){
            int i = row;
            while (i < s.length()){
                result.push_back(s[i]);
                i += (numRows - i % (numRows - 1) - 1) * 2;
            }
        }
        return result;
    }
};
