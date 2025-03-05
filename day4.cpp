//question1
class Solution {
public:
    int distinctIntegers(int n) {
        if(n==1) return 1;
       else  return n-1;
        
    }
};

//question 2
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n= a.size();
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        int x;
        for(int i=0;i<=n-m; i++) {
             x= a[i+m-1] - a[i];
            if(ans>=x) ans=x;
        }
        return ans;
    }
};
