class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int child=0;
        int cookie=0;
        //try to assign cookies
        while(child<g.size() && cookie<s.size()){
            if(s[cookie]>=g[child]) child++;
            //move to next in both case either cookie was assigned or cookie was too small and discarded
            cookie++;
        }
        return child;
    }
};