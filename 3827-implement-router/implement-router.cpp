#include <vector>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

class Router {
private:
    int memoryLimit;
    deque<vector<int>> packets; // Store packets in FIFO order: [source, destination, timestamp]
    set<tuple<int, int, int>> duplicateCheck; // Set to check for duplicates: (source, destination, timestamp)
    map<int, vector<int>> destinationToTimestamps; // Map destination to sorted list of timestamps

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> packetKey = make_tuple(source, destination, timestamp);
        
        // Check if packet is a duplicate
        if (duplicateCheck.find(packetKey) != duplicateCheck.end()) {
            return false;
        }
        
        // If memory limit would be exceeded, remove oldest packet
        if (packets.size() >= memoryLimit) {
            vector<int>& oldestPacket = packets.front();
            int oldSource = oldestPacket[0];
            int oldDestination = oldestPacket[1];
            int oldTimestamp = oldestPacket[2];
            tuple<int, int, int> oldestKey = make_tuple(oldSource, oldDestination, oldTimestamp);
            
            // Remove from duplicate check set
            duplicateCheck.erase(oldestKey);
            
            // Remove from destination map
            auto& timestamps = destinationToTimestamps[oldDestination];
            auto it = lower_bound(timestamps.begin(), timestamps.end(), oldTimestamp);
            if (it != timestamps.end() && *it == oldTimestamp) {
                timestamps.erase(it);
            }
            if (timestamps.empty()) {
                destinationToTimestamps.erase(oldDestination);
            }
            
            // Remove from packets queue
            packets.pop_front();
        }
        
        // Add new packet
        packets.push_back({source, destination, timestamp});
        duplicateCheck.insert(packetKey);
        
        // Add to destination map (maintain sorted order)
        auto& timestamps = destinationToTimestamps[destination];
        timestamps.insert(upper_bound(timestamps.begin(), timestamps.end(), timestamp), timestamp);
        
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets.empty()) {
            return {}; // Return empty array
        }
        
        // Get the first packet (FIFO)
        vector<int> packetToForward = packets.front();
        packets.pop_front();
        
        int source = packetToForward[0];
        int destination = packetToForward[1];
        int timestamp = packetToForward[2];
        
        // Remove from duplicate check set
        tuple<int, int, int> packetKey = make_tuple(source, destination, timestamp);
        duplicateCheck.erase(packetKey);
        
        // Remove from destination map
        auto& timestamps = destinationToTimestamps[destination];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), timestamp);
        if (it != timestamps.end() && *it == timestamp) {
            timestamps.erase(it);
        }
        if (timestamps.empty()) {
            destinationToTimestamps.erase(destination);
        }
        
        return packetToForward;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // Check if destination exists in our map
        if (destinationToTimestamps.find(destination) == destinationToTimestamps.end()) {
            return 0;
        }
        
        const vector<int>& timestamps = destinationToTimestamps.at(destination);
        
        // Use binary search to find the range of valid timestamps
        auto left = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto right = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        
        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */