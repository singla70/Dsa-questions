LEETCODE 605 
  class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x=flowerbed.size();
        int count=0;
        if(n==0) return true;
        if(n>x) return false;
        for(int i=0; i<x; i++) {
            // if(flowerbed[i]==1 && flowerbed[i+1]==0) {
            //     i++;
            //     continue;
            // }
            
        if(flowerbed[i]==0 && (i==x-1 || flowerbed[i+1]!=1) && (i==0 || flowerbed[i-1] !=1)) {

                count++;
                flowerbed[i]=1;
                i++;

            }
            if(count>=n) return true;
        }
        return false;
    }
};

LEETCODE 3364

  class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

         int n = nums.size();
        if (n == 0 || l > r || l > n) return -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        
        for (int i = 0; i <= n - l; i++) {
            for (int j = l; j <= r && i + j <= n; j++) {
                int sum = prefix[i + j] - prefix[i];
                if (sum > 0 && sum < ans) {
                    ans = sum;
                }
            }
        }

         if(ans == INT_MAX) return -1 ;
         else return ans;

        // int n=nums.size();
        // for(int i=1; i<n; i++) {
        //     nums[i]+=nums[i-1];
        // }
        // int ans=INT_MAX;
        // if(n==0) return -1;
        // if(l>n && r>n) return -1;
        // for(int i=l-1; i<n; i++) {
        //     int x=0;
        //     if(i-l>=0) x = nums[i] - nums[i - l];
        //      else x=nums[i];
        //     if(x>=0 && x<ans  ) ans=x;
        // }
        // for(int i=r-1; i<n; i++) {
        //     if(l==r) break;
        //     int x=0;
        //    if(i-r>=0) x = nums[i] - nums[i - r];
        //    else x=nums[i];
        //    if(x<ans && x>=0) ans=x;
        // }
        // if(ans>0 && ans != INT_MAX) return ans;
        // else return -1;
        
    }
};
