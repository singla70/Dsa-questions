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


// LEETCODE 34 FIRST AND LAST POSITION OF ELEMENT
TC O(log n)
SC O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n= nums.size();
        int l=0,h=n-1;
        bool flag = false;
        vector<int> v(2,-1);
        int mid;


        while(l<=h) {
             mid = l+ (h-l)/2;

            if(nums[mid] == target) {
                if(mid==0 || nums[mid-1] != target) {
                    v[0]=mid;
                    break;
                }
                else h = mid-1;
            }
            else if(nums[mid]>target) h=mid-1;
            else l= mid+1;
        }
        l=0,h=n-1;
        while(l<=h) {
          mid = l+ (h-l)/2;

            if(nums[mid] == target) {
                if(mid==n-1 || nums[mid+1] != target) {
                    v[1]=mid;
                    break;
                }
                else l=mid+1;
            }
            else if(nums[mid]>target) h=mid-1;
            else l= mid+1;
        }

        return v;
        
    }  
};

//LEETCODE 35 SEARCH INSERT POSITION
TC O(log n)
SC O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int lo=0; int hi=n-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>target) hi = mid-1;
            else lo=mid+1;
        }
        return lo;
        
    }
};
