// question 1 : 
class Solution {
  public:
  bool check(char ch) {
      if(ch=='a' || ch=='e' || ch=='i'|| ch=='o'|| ch=='u') return true;

          else return false;
     
     
  }
    int isGoodorBad(string S) {
        int n=S.length();
        bool flag=true;
        int vowel=0,conso=0;
        for(int i=0; i<n; i++) {
            flag= check(S[i]);
            if(S[i]=='?') {
                vowel++;
                conso++;
            }
            
            else if(flag==true) 
            {
                vowel++;
                conso=0;
                
            }
            
            
            else {
                conso++;
                vowel=0;
               
            }
            if(vowel>=6) return 0;
             if(conso>=4) return 0;
        
    }
        return 1;
    }
};



// question 2 :

  class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> merged;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
                merged.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } 
            else if (nums1[i][0] < nums2[j][0]) {
                merged.push_back(nums1[i]);
                i++;
            } 
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

      
        while (i < n) {
            merged.push_back(nums1[i]);
            i++;
        }

        
        while (j < m) {
            merged.push_back(nums2[j]);
            j++;
        }
    
        return merged;
    
    }
};


    
