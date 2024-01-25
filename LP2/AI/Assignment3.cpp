#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

bool compareBurstTime(const Process& p1, const Process& p2) {
    return p1.remaining_time < p2.remaining_time;
}

void sjf_preemptive(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < processes.size()) {
        vector<Process> eligibleProcesses;

        for (const Process& p : processes) {
            if (p.arrival_time <= currentTime && p.remaining_time > 0) {
                eligibleProcesses.push_back(p);
            }
        }

        if (!eligibleProcesses.empty()) {
            sort(eligibleProcesses.begin(), eligibleProcesses.end(), compareBurstTime);

            Process& currentProcess = eligibleProcesses.front();
            cout << "Executing process " << currentProcess.id << " at time " << currentTime << endl;

            currentProcess.remaining_time--;

            if (currentProcess.remaining_time == 0) {
                completedProcesses++;
                cout << "Process " << currentProcess.id << " completed at time " << currentTime + 1 << endl;
            }
        } else {
            cout << "CPU idle at time " << currentTime << endl;
        }

        currentTime++;
    }
}

int main() {
    vector<Process> processes = {
        {1, 0, 5, 5},
        {2, 1, 3, 3},
        {3, 2, 8, 8},
        {4, 3, 6, 6}
    };

    sjf_preemptive(processes);

    return 0;
}
