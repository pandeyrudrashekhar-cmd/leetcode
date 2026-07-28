class Solution {
public:
    bool checkValidString(string s) {
        
        //greedy method
        int low=0;
        int high=0;
        for(char ch : s){
            if(ch=='('){
                low++;
                high++;
            }
            else if(ch==')'){
                low--;
                high--;
            }
            else{
                //ch==*
                //act as (
                low--;
                //act as )
                high++;
            }
            if(high<0) return false;//too many closing bracket
            low=max(low,0);

        }
        return low==0;
    }
};