class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int i=0;
        for(string s:words){
            if(find(s.begin(),s.end(),x)!=s.end()){
                result.push_back(i);
            }
            i++;
        }
        return result;
    }
};