//  LEETCODE 704 BINARY SEARCH
TC O(log n)
SC O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int n = nums.size();
        int hi=n-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]== target) return mid;
            else if(nums[mid] > target) hi = mid-1;
            else lo =mid +1;
        }
        return -1;
        
        
    }
};
