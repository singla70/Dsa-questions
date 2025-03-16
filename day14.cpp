// GEEKFORGEEK SQUARE ROOT
TC O(LOG N)
SC O(1)


class Solution {
  public:
    int floorSqrt(int n) {
        int lo=1,hi=n;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(mid*mid== n) return mid;
            else if(mid*mid > n) hi=mid-1;
            else lo = mid+1;
        }
    
    return hi;
    }
};



// leetcode 1283
TC O(N LOG N)
SC 0(1)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int sum;
        
        sort(nums.begin(),nums.end());
        int lo=1,hi= nums[n-1];
        
        while(lo<hi) {
            sum=0;
            int mid= lo + (hi-lo)/2;
            for(int i=0; i<n;i++) {
                int x= nums[i];
                if (x %mid !=0) {
                x /= mid;
                x+=1;
                }
                else x/=mid;
                sum+=x;
            }
            if(sum <= threshold) {
                hi = mid;
                
            }
            else lo = mid+1;
        }
        
        
        return hi;

        
    }
};
