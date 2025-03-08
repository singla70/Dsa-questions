// leetcode 283
// approach 1 -> TC O(n2)
// SC  O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-1; j++)
            if(nums[j]==0 ) swap(nums[j],nums[j+1]);
        }
        
    }
};

//approach 2
//TC O(n)
// SC  O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n=nums.size();
        int j = 0; // Position to place next non-zero element
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};


//leetcode 189
// TC  O(n)
// SC  O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int x=nums.size();
        k=k%x;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.begin()+k);
        
    }
};
