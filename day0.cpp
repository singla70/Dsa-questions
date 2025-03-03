

// question : contain duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++) {
            if(nums[i]== nums[i+1]) return true;
        }
        return false;
    }
};

// concatenation of array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(2*n);
        for(int i=0; i<n; i++) {
            ans[i] = nums[i];
            ans[i+n] = nums[i];

        }
        return ans;

        
    }
};
