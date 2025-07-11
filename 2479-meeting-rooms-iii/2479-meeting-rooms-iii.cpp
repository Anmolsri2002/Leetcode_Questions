class Solution {
    #define l1 long long
    #define pli pair<l1,int>
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pli,vector<pli>,greater<pli>> free_rooms, occupied_rooms;
        vector<int> freq(n,0);
        for(int i=0;i<n;++i){
            free_rooms.push({0,i});
        } 
        for(int i=0;i<meetings.size();i++){
            while(!occupied_rooms.empty() && occupied_rooms.top().first<=meetings[i][0]){
                pli curr=occupied_rooms.top();
                occupied_rooms.pop();
                curr.first=0;
                free_rooms.push(curr);
            }
            if(!free_rooms.empty()){
                pli curr=free_rooms.top();
                free_rooms.pop();
                freq[curr.second]++;
                curr.first=meetings[i][1];
                occupied_rooms.push(curr);
            }
            else{
                pli curr=occupied_rooms.top();
                occupied_rooms.pop();
                freq[curr.second]++;
                curr.first+=1LL*(meetings[i][1]-meetings[i][0]);
                occupied_rooms.push(curr);
            }
        }
        int maxr=0;
        int maxm=0;
        for(int i=0;i<n;i++){
            if(freq[i]>maxm){
                maxr=i;
                maxm=freq[i];
            }
        }
        return maxr;
    }
};