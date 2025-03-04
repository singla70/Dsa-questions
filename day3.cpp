//question 1
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n= image.size();
        vector<vector<int>> flip;
        
        for(int i=0; i<n; i++) {
            int m= image[i].size();
            for(int j=0; j<m; j++) {
                if(image[i][j]==0) image[i][j]=1;
                else image[i][j]=0;
            }
            for(int j=0; j<m/2; j++) {
                swap(image[i][j],image[i][m-j-1]);
            }
            flip.push_back(image[i]);
        }
        return flip;
    }
};

// question 2
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int count=0;
        for(int i=0; i<n; i++) {
            sort(dominoes[i].begin(),dominoes[i].end());
        }
        sort(dominoes.begin(),dominoes.end());
        int k=1;
        for(int i=0; i<n-1; i++) {
            if(dominoes[i]==dominoes[i+1]) {
                count+=k;
                k++;
            }
            else k=1;
            
        }
        
        
        return count;
    }
    
};
