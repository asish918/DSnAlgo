#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

int leastInterval(char tasks[], int n, int k){
    //Use vector for TLE space optimization
    unordered_map<char, int> m;
    priority_queue<int> maxHeap;
    queue<pair<int, int> > q;

    for(int i = 0; i<n; i++)
        m[tasks[i]]++;

    for(auto i : m)
        maxHeap.push(i.second);

    int time = 0;
    
    while(!q.empty() || !maxHeap.empty()){
        time += 1;

        if(!maxHeap.empty()){
            int count = maxHeap.top() - 1;
            maxHeap.pop();
            
            if(count)
                q.push(make_pair(count, time + k));
        }

        if(!q.empty() && q.front().second == time){
            maxHeap.push(q.front().first);
            q.pop();
        }
    }

    return time;
}

int main(){
    char tasks[] = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int k = 2;
    int n = sizeof(tasks) / sizeof(char);

    cout << leastInterval(tasks, n, k);
    return 0;
}

/*
The function leastInterval takes three parameters: tasks, which is a character array representing the tasks to be executed; n, which is the number of tasks in the array; and k, which represents the cooldown period.

An unordered map m is used to count the frequency of each task. The loop iterates through the tasks array and increments the count for each task encountered.

A max heap (priority_queue<int> maxHeap) is used to store the task frequencies. The frequencies are pushed into the max heap using a loop over the elements of the unordered map m.

The variable time is initialized to 0. It represents the total units of time required to complete all tasks, including idle time.

The main loop executes as long as there are pending tasks in either the queue q or the max heap maxHeap. It simulates the execution of tasks and handles the cooldown period.

In each iteration of the main loop, the time is incremented by 1, representing the passage of one unit of time.

If the max heap is not empty (!maxHeap.empty()), the highest frequency task is taken from the top of the max heap. The count is decremented by 1 to simulate the execution of the task.

If the count after decrementing is non-zero (if (count)), the task is pushed into the queue q along with its scheduled execution time, which is time + k. This accounts for the cooldown period before the task can be executed again.

If the queue is not empty and the front task in the queue is scheduled to be executed at the current time (q.front().second == time), it means the cooldown period has ended for that task. The task's frequency count is pushed back into the max heap, and the task is removed from the front of the queue.

After each iteration of the main loop, either a task is executed or an idle period occurs.

Once the main loop ends, the time variable contains the total units of time required to finish all the tasks, considering the cooldown period.

The intuition behind this implementation is to prioritize tasks with higher frequencies by using a max heap. The max heap ensures that the tasks with the highest frequencies are executed first within each cooldown period. The queue q is used to store the pending tasks that need to wait for their cooldown periods to end. By simulating the execution and cooldown periods, the code accurately calculates the total time needed to finish all the tasks.
*/
