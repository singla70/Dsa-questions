LEETCODE 48
//APPROACH -> firstly transposed the matrix and then reversed each list to get required answer
  TC O(N2)
  SC O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int q= matrix.size();
         for(int i=0; i<q; i++) {
        for(int j=0; j<i; j++) {
           swap(matrix[i][j],matrix[j][i]);
        }
     }
     for(int i=0; i<q; i++) {
        reverse(matrix[i].begin(),matrix[i].end());
     }
        
        
    }
};


LEETCODE 54
TC O(M*N)
SC O(1)
  
  class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int top=0,bottom=m-1;
        int left=0,right=n-1;
        


       
    

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) 
                ans.push_back(matrix[top][j]);
            top++;
            for (int i = top; i <= bottom; i++) 
                ans.push_back(matrix[i][right]);
            right--; 
            if (top <= bottom) {
                for (int j = right; j >= left; j--) 
                    ans.push_back(matrix[bottom][j]);
                bottom--; 
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    ans.push_back(matrix[i][left]);
                left++; 
            }
        }
        
        return ans;
    }
};



LEETCODE 118
  TC O(N2)
  SC O(N2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> num;
          for(int i=0; i<numRows; i++) {
            vector<int> temp(i+1,1);
             int first=1;  

        
        for(int j=0; j<i; j++) {
            first = first * (i-j)/ (j+1);
            temp[j+1]=first;
            
        }
        num.push_back(temp);
        
    }
    return num;
        
    }
};
        
