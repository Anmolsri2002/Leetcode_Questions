class Solution {
private:
    bool valid(char ch)
    {
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
        {
            return 1;
        }
        return 0;
    }
    char tolower(char ch)
    {
        if((ch>='a' && ch<='z')||(ch>='0' && ch<='9'))
        {
            return ch;
        }
        else{
            char tp=ch-'A'+'a';
            return tp;
        }
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(valid(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
        int i=0;
        int j=temp.size()-1;
        while(i<=j)
        {
            if(tolower(temp[i])!=tolower(temp[j]))
            {
                return 0;
            }
            else{
                i++;
                j--;
            }
        }
        return 1;
    }
};