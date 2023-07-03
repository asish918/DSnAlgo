#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MedianFinder {
    private:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        double median;

    public:
        MedianFinder() {
            median = 0.0;
        }

        int signum() {
            return maxHeap.size() - minHeap.size();
        }

        void insertHeap(int &x) {
            switch(signum()) {
                case 0:
                    if(x > median) {
                        minHeap.push(x);
                        median = minHeap.top();
                    }
                    else {
                        maxHeap.push(x);
                        median = maxHeap.top();
                    }
                    break;
                
                case 1:
                    if(x > median) {
                        minHeap.push(x);
                    }
                    else {
                        balanceHeaps();
                        maxHeap.push(x);
                    }
                    median = (maxHeap.top() + minHeap.top()) / 2.0;
                    break;

                case -1:
                    if(x > median) {
                        balanceHeaps();
                        minHeap.push(x);
                    } else {
                        maxHeap.push(x);
                    }

                    median = (maxHeap.top() + minHeap.top()) / 2.0;
                    break;
            }
        }

        void balanceHeaps() {
            if(minHeap.size() < maxHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        double getMedian() {
            return median;
        }
};

int main() {
    MedianFinder md;

    int x[] = {5, 15, 1, 3};
    int n = sizeof(x) / sizeof(int);

    for(int i = 0; i<n; i++) {
        md.insertHeap(x[i]);
        cout << md.getMedian() << " ";
    }

    cout << endl;
    return 0;
}
