class Solution {
public:
    bool checkIfPangram(string sentence) {
    
    unordered_set<char> st (sentence.begin(), sentence.end());         //push all characters of string into set
    return st.size()==26;                                              //check if it's size = 26 or not

}
};