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




//LEETCODE 875
SC O(1)
TC O(LOG N)


class Solution {
public:


    bool check(int speed,vector<int> & piles,double h) {
        double time=0;
        int n= piles.size();
        for(int i=0; i<n; i++) {
            
            int x= piles[i]/speed;
            long long y = (long long)x;
            if(piles[i] <=speed) time++;  // as fir vo 1 hour to minimum khayega hi is case me
            
            else if(piles[i] > speed) {

                if(piles[i] % speed ==0 ) time += y;
                else time += (y+1);
            }

        }
        if(time> h) return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int lo=1;
        int max=INT_MIN;
        for(int i=0; i<n; i++) {
            if(max<piles[i]) max = piles[i];
        }
        int hi=max;
        int ans=0;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(check(mid,piles,h)) {
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;

        }
        return ans;

        
    }
};
