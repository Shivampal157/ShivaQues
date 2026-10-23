class Solution{
public:
    int findMinFibonacciNumbers(int k){
        vector<int>fib={1,1};

        while(fib.back()<=k){
            int n=fib.size();
            int next=fib[n-1]+fib[n-2];
            if(next>k)break;
            fib.push_back(next);
        }

        int ans=0;
        for(int i=fib.size()-1;i>=0;i--){
            if(k>=fib[i]){
                k-=fib[i];
                ans++;
            }
        }

        return ans;
    }
};