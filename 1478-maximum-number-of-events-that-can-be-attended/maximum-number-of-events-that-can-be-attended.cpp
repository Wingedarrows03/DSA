class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day, and by end day if start days are equal
        sort(events.begin(), events.end());
        
        // Min-heap to store end days of events that can be attended
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int maxEvents = 0; // Count of attended events
        int i = 0; // Index for iterating through sorted events
        int n = events.size();
        int day = 1; // Current day
        
        // Process days until all events are considered and no events are left in the heap
        while (i < n || !pq.empty()) {
            // Add all events that start on or before the current day to the heap
            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]); // Push end day of the event
                i++;
            }
            
            // Remove events that can no longer be attended (end day < current day)
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // If there are events that can be attended on the current day, attend one
            if (!pq.empty()) {
                pq.pop(); // Attend the event with the earliest end day
                maxEvents++; // Increment the count of attended events
            }
            
            day++; // Move to the next day
        }
        
        return maxEvents;
    }
};