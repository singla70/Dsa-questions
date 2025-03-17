LEETCODE 74
//  APPROACH 1
  TC O ( M * log (n) )
  SC O(1)
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();
        if(target >= matrix[0][0] && target <= matrix[0][col-1]) {
            int lo=0; int hi= col-1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if (target== matrix[0][mid]) return true;
                else if (target < matrix[0][mid] ) hi = mid-1;
                else lo = mid +1;
            }
        }
        for(int i=0; i<row-1; i++) {
            if(target > matrix[i][col-1] && target <= matrix[i+1][col-1]) {
                 int lo=0; int hi= col-1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if (target== matrix[i+1][mid]) return true;
                else if (target < matrix[i+1][mid] ) hi = mid-1;
                else lo = mid +1;
            }
            return false;
            }
        }
        return false;
        
    }
};

  //  APPROACH 2
  TC O ( log (m*n) )
  SC O(1)


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();

        int top=0,bottom=row-1;
        while(top<=bottom) {
            int middle = top + (bottom - top)/2;
            if (target>= matrix[middle][0] && target <= matrix[middle][col-1]) {
                 int lo=0; int hi= col-1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if (target== matrix[middle][mid]) return true;
                else if (target < matrix[middle][mid] ) hi = mid-1;
                else lo = mid +1;
            }
            return false;
            }
            else if(target < matrix[middle][0]) bottom = middle-1;
            else top = middle +1;
        }
        
           
        return false;
    }



// LEETCODE 240

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int row= a.size();
        int col= a[0].size();
        int i= 0, j= col-1;
        while( i<row && j>= 0 ) {
            if(a[i][j]== target) return true;
            else if(a[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
};





// GEEKFORGEEK KTH ELEMENT OF TWO ARRAY
SC  O(M+N)
TC O (M+N)

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m=a.size();
        int n= b.size();
        int i=0,j=0,p=0;
        vector<int> c(m+n);
        
        while(i<m && j<n) {
            if(a[i] >b[j])    c[p++]= b[j++]; 
            else  c[p++] = a[i++];
            if(p>=k) return c[k-1];
        }
        if(i==m) {
            while(p<m+n) {
                c[p++]=b[j++];
                if(p>=k) return c[k-1];
            }
        }
        if(j==n) {
            while(p<m+n) {
                c[p++]=a[i++];
                if(p>=k) return c[k-1];
            }
        }
        return 0;
    }
};
