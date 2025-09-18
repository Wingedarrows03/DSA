#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class TaskManager {
private:
    // Store task information: taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> tasks;
    
    // Max heap to store tasks by priority, then by taskId
    // Store as {priority, taskId} so priority is compared first
    priority_queue<pair<int, int>> maxHeap;
    
public:
    TaskManager(vector<vector<int>>& taskList) {
        for (const auto& task : taskList) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            
            tasks[taskId] = {userId, priority};
            maxHeap.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks[taskId] = {userId, priority};
        maxHeap.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        // Update the priority in the map
        int userId = tasks[taskId].first;
        tasks[taskId] = {userId, newPriority};
        
        // Add new entry to heap (old entry becomes stale)
        maxHeap.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        // Remove from tasks map (heap entries become stale)
        tasks.erase(taskId);
    }
    
    int execTop() {
        // Clean up stale entries and find the highest priority valid task
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();
            
            // Check if this task still exists and has the correct priority
            if (tasks.find(taskId) != tasks.end() && 
                tasks[taskId].second == priority) {
                
                int userId = tasks[taskId].first;
                tasks.erase(taskId);  // Remove the executed task
                return userId;
            }
            // Otherwise, this was a stale entry, continue to next
        }
        
        return -1;  // No tasks available
    }
};

// Example usage and test
/*
int main() {
    vector<vector<int>> initialTasks = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(initialTasks);
    
    taskManager.add(4, 104, 5);     // Add task 104 with priority 5 for User 4
    taskManager.edit(102, 8);       // Update priority of task 102 to 8
    cout << taskManager.execTop() << endl;  // Should return 3 (task 103, priority 15)
    taskManager.rmv(101);           // Remove task 101
    taskManager.add(5, 105, 15);    // Add task 105 with priority 15 for User 5
    cout << taskManager.execTop() << endl;  // Should return 5 (task 105, priority 15, higher taskId)
    
    return 0;
}
*/