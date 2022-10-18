class Solution {
public:
    string countAndSay(int n, string s = "1") { // initial value of the string is "1"
    if(n==1) return s; // base case, when n recursive calls are finished
	
    int i=0, j, len = s.size(); // 'len' is the length of the string 's'
    string res = ""; // result after we 'say' the string 's'
	
	// 'i' starts from index 0
    while(i<len) {
        j=i; // fix 'j' as the current position (i)
		
		// increment the value of 'i' till valid position
        while(i<len && s[i]==s[j]) i++;
		
		// substring with same values as s[j] is [j,i-1] & "i-j" is the count of that value
		// add the concatenation of (count + s[j]) to the result 
        res += to_string(i-j) + s[j];
    }
	
	// recursively, call the same function by decrementing the count
	// and update the result 'res', which will be the next string 's'
    return countAndSay(n-1, res);
}
};