class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1])
                return i;
        }
        return -1;
    }
};