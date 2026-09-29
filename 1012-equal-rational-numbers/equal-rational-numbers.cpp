class Solution{
public:
    pair<long long,long long>get(string s){
        long long num=0,den=1;
        int i=0;

        while(i<s.size()&&s[i]!='.'){
            num=num*10+(s[i]-'0');
            i++;
        }

        if(i==s.size())return {num,1};

        i++;

        long long non=0;
        int cnt=0;

        while(i<s.size()&&s[i]!='('){
            non=non*10+(s[i]-'0');
            cnt++;
            i++;
        }

        if(cnt){
            num=num*pow10(cnt)+non;
            den=pow10(cnt);
        }

        if(i<s.size()){
            i++;
            long long rep=0;
            int len=0;

            while(s[i]!=')'){
                rep=rep*10+(s[i]-'0');
                len++;
                i++;
            }

            long long p=pow10(len);
            num=num*(p-1)+rep;
            den=den*(p-1);
        }

        long long g=gcd(num,den);
        return {num/g,den/g};
    }

    long long pow10(int n){
        long long p=1;
        while(n--)p*=10;
        return p;
    }

    bool isRationalEqual(string s,string t){
        auto a=get(s);
        auto b=get(t);

        return a.first*b.second==b.first*a.second;
    }
};