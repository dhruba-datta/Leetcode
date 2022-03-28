class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(), n=t.size();
        unordered_map<char, int> mp;
        
        int ans = INT_MAX; // length of ans
        int start = 0; // starting index of ans
        
        for(auto x:t)
            mp[x]++;
        
        int count = mp.size();
        
        // References of Window
        int i = 0, j = 0;

        // Traversing the window
        while (j < s.length()) {
            // Calculations
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;

            // Condition matching
            if (count == 0) {
                while (count == 0) {
                    // Sorting ans
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    // Sliding I
                    // Calculation for removing I
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;

                    i++;
                }
            }
            j++;
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "";
    }
};