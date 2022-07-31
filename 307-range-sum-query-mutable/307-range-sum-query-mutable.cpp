class SegmentTree {
    SegmentTree *left, *right;
    int L, R, val;
public:
    SegmentTree(vector<int>& nums, int l, int r): L(l), R(r), left(NULL), right(NULL) {
        build(nums);
    }
    void build(vector<int>& nums) {
        if(L == R) val = nums[L];
        else {
            int mid = (L + R) / 2;
            left = new SegmentTree(nums, L, mid);
            right = new SegmentTree(nums, mid + 1, R);
            val = left -> val + right -> val;
        }
    }
    void update(int i, int new_val) {
        if(L == R) val = new_val;
        else {
            int mid = (L + R) / 2;
            if(i <= mid) left -> update(i, new_val);
            else right -> update(i, new_val);
            val = left -> val + right -> val;
        }
    }
    int sum(int l, int r) {
        if(l > r) return 0;
        if(l == L && r == R) return val;
        int mid = (L + R) / 2;
        return left -> sum(l, min(mid, r)) + right -> sum(max(l, mid + 1), r);
    }
};
class NumArray {
    SegmentTree *tree;
public:
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums, 0, size(nums) - 1);
    }
    
    void update(int index, int val) {
        tree -> update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree -> sum(left, right);
    }
};