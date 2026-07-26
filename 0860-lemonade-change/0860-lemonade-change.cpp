class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for( int bill : bills){
            if(bill==5) five++;
            else if(bill==10){
                //need one five as change
                if(five==0) return false;
                five--;
                ten++;
            }
            else{//customer pay 20
                //greedy approach:- prefer giving one 10 and one 5
                if(ten>=1 && five>=1){
                    ten--;
                    five--;
                }
                //otherwise give 3 five bills
                else if(five>=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};