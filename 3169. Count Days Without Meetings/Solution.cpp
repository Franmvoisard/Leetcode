class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = days;
        int previousEnd = 0;

        // Sort them
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>&b){
            return a[0] < b[0];
        });
       
        for(auto& meeting : meetings){
            int meetingStart = max(meeting[0], previousEnd);
            int meetingEnd = meeting[1];
            if(previousEnd > meetingEnd) continue;
            
            int length = meetingEnd - meetingStart + 1;
            freeDays -= length;
            previousEnd =  max(previousEnd, meetingEnd + 1);
        }

        return freeDays;
    }
};
