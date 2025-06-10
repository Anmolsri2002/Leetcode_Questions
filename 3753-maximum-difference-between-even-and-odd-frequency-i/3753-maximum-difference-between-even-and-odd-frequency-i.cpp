class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int maxi=0;
        int a=0,b=101;
        for(auto ch:s){
            if(mp[ch]%2!=0 && mp[ch]>a){                
               a=mp[ch]; 
            }
            if(mp[ch]%2==0 && mp[ch]<b){
                b=mp[ch];
            }
        }
        return a-b;
    }
};