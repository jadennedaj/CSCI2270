#include "WaitlistQueue.hpp"

using namespace std;

WaitlistQueue::WaitlistQueue(int qSize)
{
    /* Already implemented, don't change */
    qFront = qEnd = -1;
    qCapacity = qSize;
    queue = new string[qSize];
    count = 0;
}

WaitlistQueue::~WaitlistQueue()
{
    delete []queue;
    //TODO
}

void WaitlistQueue::enqueue(string value)
{
    //TODO
    if (isFull()){
        cout << "Queue full, cannot add new item" << endl;
        return;
    }
    if(isEmpty()){
            queue[0] = value;
            qFront = 0;
            qEnd = 0;
            count++;
    }else{
            qEnd++;
            queue[qEnd] = value;
            count++;
    }    
    
    return;
}




void WaitlistQueue::dequeue()
{
    //TODO
    if(isEmpty()){
        cout << "Waitlist is empty. Cannot dequeue." << endl;
    }else if(qFront == qEnd){
        qFront = -1;
        qEnd = -1;
        count = 0;
    }else{
        qFront++;
        count--;
    }
}

string WaitlistQueue::peek()
{
    //TODO
    if(qFront > -1) return queue[qFront];
    return "<EMPTY QUEUE>";
}

void WaitlistQueue::resize(int newSize)
{
    //TODO
    string* newQ = new string[newSize];
    int crawl1 = 0;
    int crawl2 = 0;
    if(qFront > qEnd){
        while(qFront < qCapacity){
            if(crawl1 < newSize -1){
                newQ[crawl1] = queue[qFront];
                crawl1++;
                qFront++;
            }else break;
        }
        while (crawl2 < qEnd){
            if(crawl1 < newSize -1){
                newQ[crawl1] = queue[crawl2];
                crawl1++;
                crawl2++;
            }else break;
        }
        newQ[crawl1] = queue[crawl2];
        qFront = 0;
        qEnd = crawl1;
    }else{
        while(crawl1 < newSize - 1){
            while(qFront < qEnd){
                newQ[crawl1] = queue[qFront];
                qFront++;
                crawl1++;
            }
            newQ[crawl1] = queue[qFront];
            break;
        }
        qFront = 0;
        qEnd = crawl1;
    }
    delete [] queue;
    qCapacity = newSize;
    queue = newQ;
    newQ = nullptr;
    delete [] newQ;
}

int WaitlistQueue::size()
{
    //TODO
    return count;
}

int WaitlistQueue::capacity()
{
    //TODO
    return qCapacity;
}

bool WaitlistQueue::isEmpty()
{
    //TODO
    if(qEnd == qFront && qFront == -1){
        return true;
    }
    return false;
}

bool WaitlistQueue::isFull()
{
    //TODO
    if(qEnd + 1 == qFront){
        return true;
    }else{
    return false;
    }
}