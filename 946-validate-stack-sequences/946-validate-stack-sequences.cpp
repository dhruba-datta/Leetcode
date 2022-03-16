class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s ;   // an empty stack
        int j = 0;
        for(int i= 0; i<pushed.size(); ++i)
        {
            s.push(pushed[i]);
            
			// check if pushed values is next to pe popped out.
            while(!s.empty() && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
        }
		// if stack is empty means sequence is correct.
        return s.empty();
    }
};