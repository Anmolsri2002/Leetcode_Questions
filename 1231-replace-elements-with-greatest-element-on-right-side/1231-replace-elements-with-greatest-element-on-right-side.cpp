class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result;
        result.push_back(-1);
        if(arr.size()==1){
            return result;
        }
        result.push_back(arr[arr.size()-1]);
        if(arr.size()==2){
            reverse(result.begin(),result.end());
            return result;
        }
        int max_elem=arr[arr.size()-1];
        for(int j=arr.size()-2;j>0;j--){
            if(arr[j]>=max_elem){
                result.push_back(arr[j]);
                max_elem=arr[j];
            }
            else{
                result.push_back(max_elem);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};