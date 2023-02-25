// C++ STL Implementation of Queues

#include <iostream>
#include <queue>
  
using namespace std;

int main(){
    queue <int> q; 
    q.push(10); // void type
    q.push(20); 
    q.push(30); 
    q.push(40); 
    q.push(50); 
  
    cout << "Size: " << q.size() << endl;
    cout << "Front,Rear: " << q.front() << "," << q.back() << endl;
    q.pop(); // void type
    cout << "Front,Rear: " << q.front() << "," << q.back() << endl;
    
    
    queue <int> q2 (q); 
    cout << "Size: " << q2.size() << endl;
    
    cout << "\nQueue: ";
    while(!q.empty())
    {
       cout << q.front() << " ";
       q.pop();
    }


    return 0;
}