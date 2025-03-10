// LEETCODE 2149
TC O(N)
SC O(N)


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>odd;
        vector<int>even;
        for(int i=0; i<n; i++) {
            if(nums[i]>0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        int j=0,k=0;
        for(int i=0; i<n; i++) {
            nums[i++] = even[j++];
            nums[i]= odd[k++];
        }
        return nums;
        
    }
};


//LEETCODE 31 
TC O(N)
SC O(1)
  class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int i;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j;
        for (j = n - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};





  // leetcode 121
  approach 1 -> TC O(N2)
                SC O(1)
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                ans= max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
    }
};


approach 2 -> 
  TC O(n)
  SC O(1)
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int minprice =prices[0];
        for(int i=1; i<n; i++) {
            
                ans= max(ans,prices[i]-minprice);
                minprice = min(minprice, prices[i]);
            
        }
        return ans;
    }
};
