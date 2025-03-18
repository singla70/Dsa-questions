LEETCODE 1901
  TC O (M*N)
  SC O (1)


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int ro= mat.size();
        int col= mat[0].size();
        vector<int> ans(2,-1);
        for(int i=0; i<=ro-1; i++) {
            // int lo=0;
            // int hi= col-1;
            // while(lo<=hi) {
            //     int mid = lo + (hi-lo)/2;
            //     // bool left = (mid==0 || mat[i][mid] > mat[i][mid-1]);
            //     // bool right = (mid == col-1 || mat[i][mid] > mat[i][mid+1] );
            //     bool top = (i==0 || mat[i][mid] > mat[i-1][mid]);
            //     bool bottom = (i== ro-1 || mat[i][mid] > mat[i+1][mid] );

            //     if ( left && right  && top && bottom ) {
            //         ans[0] = i;
            //         ans[1]= mid;
            //         return ans;
            //     }
            //     else if(!left) hi=mid-1;  // or we can write !left
            //     else lo = mid+1;

            // }


            int mxcol=0;
            for(int j=1; j<col; j++) {
                if(mat[i][j]>mat[i][mxcol]) mxcol=j;
            }
                bool top = (i==0 || mat[i][mxcol] > mat[i-1][mxcol]);
                bool bottom = (i== ro-1 || mat[i][mxcol] > mat[i+1][mxcol] );
                if(top && bottom) {
                    ans[0] = i;
                    ans[1]= mxcol;
                    return ans;
                }
        }
        return ans;
        
    }
};


// GEEKFORGEEK MEDIAN IN A ROW WISE SORTED MATRIX
approach 1
TC O(M*N)
SC O(M*N)

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int m= mat.size();
        int n= mat[0].size();
        
        // m and n are always odd so median is always 1;
        // int med=(m*n)/2; // jo ki (m*n)/2 index pe hpga
        // int j=1;
        // while(j<med) {
        //     sort(mat.begin(),mat.end());
            
        //     if(mat[0].size() !=0) mat[0].erase(mat[0].begin());
        //     else mat.erase(mat.begin());
        //     j++;
        // }
        // return mat[0][0];
        
       
       int k=0;
       vector<int> temp(m*n);
       for(int i=0; i<m; i++) {
           for(int j=0; j<n; j++) {
               temp[k++]= mat[i][j];
           }
       }
       sort(temp.begin(),temp.end());
       return temp[(m*n)/2];     
    }
};


approach 2 
sc o(1)
tc o (log(maxval - minval) * m log n)

class Solution {
  public:
    int solve(vector<int> temp, int target) {
        int lo=0,hi=temp.size()-1;
        int count=0;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(temp[mid] <= target) // saare element mid se pehle wale chote hai target se
            {
                count= mid+1;
                lo = mid+1;
            }
            else hi=mid-1;
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        int m= mat.size();
        int n= mat[0].size(); 
      int minv= INT_MAX;
      int maxv= INT_MIN;
      for(int i=0; i<m; i++) {
          minv = min(minv,mat[i][0]);
          maxv= max(maxv,mat[i][n-1]);
          
      }
    int median = (m*n)/2;
    while(minv <=maxv) {
        int mid = minv + (maxv-minv)/2;
        int count=0;
        for(int i=0; i<m; i++) {
            count+= solve(mat[i],mid);
        }
        if(count<= median) minv= mid+1;
        else maxv = mid-1;
    }
    return minv;  
    }
};














LEETCODE 387
  TC O(N)
  SC O(1)
  class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> mp;
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
            }
            else mp[s[i]]=1;
        }
        for(int i=0; i<s.length(); i++) {
            if(mp[s[i]]==1) return i;
        }
        return -1;
        
    }
};



