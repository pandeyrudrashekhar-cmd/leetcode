class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child=0,cookie=0;
        //try assuming cookies
        while(child<g.size() && cookie<s.size()){
            //if curr cookie can satisfy current child
            if(s[cookie]>=g[child]){
                child++;//move to next child
            }
            cookie++;
        }
        return child;
    }
};