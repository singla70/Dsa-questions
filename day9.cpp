//leetcode 75
TC O( n)
SC O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;

        while (mid <= hi) {  
            if (nums[mid] == 0) {   
                swap(nums[mid], nums[lo]);
                lo++;
                mid++;  
            }
            else if (nums[mid] == 1) {  
                mid++;  
            }
            else {   
                swap(nums[mid], nums[hi]);
                hi--;  
            }
        }
    }
};
//leetcode 1
TC O(N)
SC O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        int n=nums.size();
        
        unordered_map<int,int> mp;
        for(int i=0; i<n;i++) {
            int x = target -nums[i];
            if(mp.find(x)!= mp.end()) {
                indices.push_back(i);
                indices.push_back(mp[x]);

            }
            else mp[nums[i]]=i;
        }
       
        return indices;
    }
};

// geekforgeek --> Maximum Score from Subarray Minimum

approach 1 TC O(n2)
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int n= arr.size();
        
   int ans = 0;

   
    for (int i = 0; i < n - 1; i++) {
        int smallest = arr[i], second_smallest = INT_MAX;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < smallest) {
                second_smallest = smallest; 
                smallest = arr[j];          
            } else if (arr[j] < second_smallest) {
                second_smallest = arr[j];   
            }

            
            if (second_smallest != INT_MAX) {
                ans = max(ans, smallest + second_smallest);
            }
        }
    }
    
    return ans;

        
    }
};


approach 2  TC --> O(n)

  class Solution {
public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        int ans = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            int currSum = arr[i] + arr[i + 1];
            ans = max(ans, currSum);
        }
        
        return ans;
    }
};
