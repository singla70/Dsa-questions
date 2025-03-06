// leetcode 409

class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(),s.end());
        int n= s.length();
        int odd=1,count=0;
        int freq=1;
        if(n==1) return 1;
        bool flag = false;
        for(int p=0; p<n; p++) {
        
            while(s[p]==s[p+1]) {
                freq++;
                p++;
            }
            if(freq%2==0) count+=freq;
            else {
                flag=true;
                count+= freq-1;
                
                if(freq>odd) odd=freq;
            }
            freq=1;
            
            
        }
        if(flag==false) return count;
        return count+1;
        
    }
};



// leetcode 2591
class Solution {
public:
    int distMoney(int money, int children) {
        int m=money-children;
        if((money==4 && children ==1) || money<children ) return -1;
        
       
        
        
        int y= m / 7;
        int x= m % 7;
        if(y>=children) {
            if(y==children && x==0) return y;
            else return children -1;
        }
        if(y==children && x==0) return y;
        if(y==children-1 && x==3) return y-1;
        
        

      
            
            return y;
         
        
        
       

        
    }
};
