// geekforgeek  stock span problem


// approach 1, but o(n2) time complexity

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n= arr.size();
        vector<int> ans;
        
        ans.push_back(1);
        for(int i=1; i<n; i++) {
            int count=1;
            int j=i;
            
            while(j>0 && arr[i]>=arr[j-1]  ) {
                count++;
                j--;
                
            }
            
            ans.push_back(count);
            
        }
        return ans;
    }
};

// approach 2, having better time complexity
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1); 

        for (int i = 1; i < n; i++) {
            int j = i - 1; 

            while (j >= 0 && arr[i] >= arr[j]) {
                ans[i] += ans[j]; 
                j -= ans[j];     
            }
        }

        return ans;
    }
};



// question 2, leetcode 1560
