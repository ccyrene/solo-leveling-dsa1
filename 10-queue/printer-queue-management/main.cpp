#include<iostream>
#include<queue>
#include<string>
using namespace std;

class PrintJob {
public:
    string documentName;
    int numberOfPages;

    PrintJob(string docName, int pages): documentName(docName), numberOfPages(pages) {}
};

class PrinterQueue {
private:
    queue<PrintJob> queues;

public:
    void addJob(const PrintJob &job) {
        queues.push(job);
        cout << "Added to queue: " << job.documentName << " (" 
        << job.numberOfPages << " pages)\n";
    }

    void processJobs() {
        while(!queues.empty()) {
            PrintJob currentJob = queues.front();
            cout << "Printing: " << currentJob.documentName << " ("
            << currentJob.numberOfPages << " pages)\n";
            queues.pop();
        }
        cout << "All print jobs completed.\n";
    }
};

int main() {
    PrinterQueue printer;

    printer.addJob(PrintJob("Document1.pdf", 10));
    printer.addJob(PrintJob("Document2.pdf", 5));
    printer.addJob(PrintJob("Document3.pdf", 12));

    printer.processJobs();

    return 0;
}