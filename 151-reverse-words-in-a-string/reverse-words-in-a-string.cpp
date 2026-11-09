class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> v;

        while(ss >> word) {
            v.push_back(word);
        }

        reverse(v.begin(),v.end());

        string ans = "";

        for(int i=0;i<v.size();i++) {
            if(i > 0) ans += " ";
            ans += v[i];
        }

        return ans;
    }
};