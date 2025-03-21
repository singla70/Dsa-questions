LEETCODE 1614
  TC O (N)
  SC O(N)

class Solution {
public:
    int maxDepth(string s) {
        stack <int> st;
        int ans=0;
       
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(') {
                st.push(s[i]);
               ans = max(ans,(int)st.size());

            }
            else if (s[i]== ')') {
                if(!st.empty())
                st.pop();   
            }
        }
        return ans;
    }
};



LEETCODE 13
  TC O(N)
  SC O(1)


class Solution {
public:
    int romanToInt(string s) {
        double ans=0;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i]== 'M' && i>=0) {
                if((i==0 || s[i-1] != 'C' )) ans+=1000;    
                else {
                    ans+=900;
                    i--;
                 }
            }
           else if(s[i]== 'D' && i>=0) {
                if((i==0 || s[i-1] != 'C' )) ans+=500;    
                else {
                    ans+=400;
                    i--;
                 }
            }
           else if(s[i]== 'C' && i>=0) {
                if((i==0 || s[i-1] != 'X' )) ans+=100;    
                else {
                    ans+=90;
                    i--;
                 }
            }
            else if(s[i]== 'L' && i>=0) {
                if((i==0 || s[i-1] != 'X' )) ans+=50;    
                else {
                    ans+=40;
                    i--;
                 }
            }
           else if(s[i]== 'X' && i>=0) {
                if((i==0 || s[i-1] != 'I' )) ans+=10;    
                else {
                    ans+=9;
                    i--;
                 }
            }
           else if(s[i]== 'V' && i>=0) {
                if((i==0 || s[i-1] != 'I' )) ans+=5;    
                else {
                    ans+=4;
                    i--;
                 }
            }
           else if(s[i]=='I' && i>=0) ans+=1;
            


        }
        return ans;
        
    }
};
