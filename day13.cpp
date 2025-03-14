// leetcode 153 
TC O(LOG N)
SC O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int lo=0; int hi=n-1;
        int pivot;
        while(lo<hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }
        pivot=lo;
        return nums[pivot];
        
    }
};




// LEETCODE 33
TC O(LOG N)
SC O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0; int hi= nums.size()-1;
        int n=nums.size();
        int pivot;

        // while(lo<hi) {
        //     int mid= lo + (hi-lo)/2;
        //     if((nums[mid] > nums[mid-1] || mid==0) && (nums[mid] >nums[mid+1] || mid =n-1)) pivot=mid+1;
        //     else if((nums[mid] < nums[mid-1] || mid==0) && (nums[mid] <nums[mid+1] || mid =n-1)) pivot = mid;




        // }
        while(lo<hi) {
             int mid= lo +(hi-lo)/2;
            if(nums[mid]> nums[hi]) lo = mid+1;
            else hi = mid;
        }
        pivot=lo;
        lo=0; hi = n-1;
        if (target >= nums[pivot] && target <= nums[hi]) {
            lo = pivot;
        } else {
            hi = pivot - 1;
        }
        while(lo<=hi) {
            int mid= lo +(hi-lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }
        return -1;     
    }
};




// CODE360 -->  CEIL THE FLOOR
TC O(LOG N)
SC O(1)

pair<int, int> getFloorAndCeil(vector<int> &nums, int n, int x) {
	// Write your code here.
	pair<int,int> y;
	y.first=-1;
	y.second=-1;
if(x<nums[0]) {
	y.first=-1;
	y.second= nums[0];
	return y;
}
if(x>nums[n-1]) {
	y.first=nums[n-1];
	y.second=-1;
	return y;
}

	int lo=0,hi=n-1;
	while(lo<=hi) {
		int mid = lo + (hi-lo)/2;
		if(nums[mid] == x) {
			 y.first=nums[mid];
			 y.second= nums[mid];
			return y;
		}
		else if(nums[mid]>x) hi=mid-1;
		else lo= mid+1;
	}
	
	y.first= nums[hi];
	y.second= nums[hi+1];
	return y;

}
