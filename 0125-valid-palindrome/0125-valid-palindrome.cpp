class Solution {
public:
    bool isPalindrome(string s) {
       string p="";
       //allow only a string now any other than that after than concert into lower case
       for(char c: s){
        if(isalnum(c)){
            p+=tolower(c);
        }
       } 
       string rev=p;
       reverse(rev.begin(),rev.end());
       if(p==rev) return true;
       else return false;

    }
};