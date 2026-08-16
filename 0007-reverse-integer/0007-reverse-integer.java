class Solution {
    public int reverse(int x) {
        int rem;
        int ans=0;
        while(x!=0){
            rem=x%10;
            x=x/10;
            if(ans>Integer.MAX_VALUE/10 || ans<Integer.MIN_VALUE/10) return 0;
            ans=ans*10+rem;
            
        }
        return ans;
    
    }
}