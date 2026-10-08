class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long x=1;x*x<=num;x++){
        if(x*x==num){
            return true;
        }
        }
        return false;
        
    }
};