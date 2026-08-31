class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0;//point to child
        //point to cookie
        int j=0;
        int satisfied=0;//no of child satisfies
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                satisfied++;
                i++;
                j++;
            }
            else{
                //cookie to small-> try bigger one
                j++;
            }
        }
        return satisfied;
    }
};