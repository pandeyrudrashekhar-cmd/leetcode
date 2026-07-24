class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;//no of unmatched brackets
        int ans=0;//min no of insertions required
        for(char ch : s){
            if(ch=='('){
                open++;
            }
            else{
                if(open>0) open--;
                else{
                    ans++;
                }
            }
            

        }
        ans+=open;
        return ans;

    }
};