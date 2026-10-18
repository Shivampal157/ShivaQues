class Solution{
public:
    int countDigitOne(int n){
        long long ans=0;

        for(long long digit=1;digit<=n;digit*=10){
            long long high=n/(digit*10);
            long long cur=(n/digit)%10;
            long long low=n%digit;

            if(cur==0)
                ans+=high*digit;
            else if(cur==1)
                ans+=high*digit+low+1;
            else
                ans+=(high+1)*digit;
        }

        return ans;
    }
};