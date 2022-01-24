class Solution {
public:
    int strStr(string haystack, string needle) {
        auto found = haystack.find(needle);
        if (found != string::npos)
            return found;
        return -1;
    }
};