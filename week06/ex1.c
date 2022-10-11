#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    unsigned int id;
    unsigned int arrivalTime;
    unsigned int burstTime;
    unsigned int completionTime;
    unsigned int turnAroundTime;
    unsigned int waitingTime;
} process;

int comparatorId(const void * a, const void * b) {
    process* p1 = (process *) a;
    process* p2 = (process *) b;
    if (p1->id < p2->id)
        return -1;
    else if (p1->id > p2->id)
        return 1;
    return 0;
}

int comparator(const void * a, const void * b) {
    process* p1 = (process *) a;
    process* p2 = (process *) b;
    if (p1->arrivalTime < p2->arrivalTime)
        return -1;
    else if (p1->arrivalTime > p2->arrivalTime)
        return 1;
    else
        return comparatorId(a, b);
    return 0;
}

unsigned int max(unsigned int a, unsigned int b) {
    if (a > b) return a;
    return b;
}

int main() {
    unsigned int n;
    scanf("%d", &n);
    process *processes = calloc(n, sizeof(process));
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        scanf("%d", &processes[i].arrivalTime);
        scanf("%d", &processes[i].burstTime);
    }
    qsort(processes, n, sizeof(process), comparator);
    unsigned int sumTat = 0, sumWt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) processes[i].completionTime = processes[i].arrivalTime + processes[i].burstTime;
        else processes[i].completionTime =
                max(processes[i - 1].completionTime, processes[i].arrivalTime) + processes[i].burstTime;
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;

        sumTat += processes[i].turnAroundTime;
        sumWt += processes[i].waitingTime;
    }

    qsort(processes, n, sizeof(process), comparatorId);

    for (int i = 0; i < n; ++i) {
        printf("Process %d:\n", processes[i].id);
        printf("Completion time: %d\n", processes[i].completionTime);
        printf("Turn around time: %d\n", processes[i].turnAroundTime);
        printf("Waiting time: %d\n\n", processes[i].waitingTime);
    }
    printf("Average Turnaround time: %f\n", (double) sumTat / n);
    printf("Average waiting time: %f\n", (double) sumWt / n);
    return EXIT_SUCCESS;
}

