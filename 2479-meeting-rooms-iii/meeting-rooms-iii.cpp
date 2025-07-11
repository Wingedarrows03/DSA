class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        // Priority queue for used rooms (end time, room number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> used;
        // Priority queue for available rooms (just room number, min-heap for lowest room number)
        priority_queue<int, vector<int>, greater<int>> available;
        
        // Initialize all rooms as available
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        
        // Count meetings per room
        vector<int> meetingCount(n, 0);
        
        // Process each meeting
        for (const auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            long long duration = end - start;
            
            // Free up rooms that are done by the current meeting's start time
            while (!used.empty() && used.top().first <= start) {
                auto [endTime, room] = used.top();
                used.pop();
                available.push(room);
            }
            
            // If there are available rooms
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                meetingCount[room]++;
                used.push({start + duration, room});
            } else {
                // No rooms available, take the earliest finishing room
                auto [endTime, room] = used.top();
                used.pop();
                meetingCount[room]++;
                // Meeting starts when the room becomes free
                long long newStart = endTime;
                used.push({newStart + duration, room});
            }
        }
        
        // Find room with maximum meetings
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                resultRoom = i;
            }
        }
        
        return resultRoom;
    }
};