/*
Tandem Bicycle
A tandem bicycle is a bicycle that’s operated by two people: person A and person B. 
Both people pedal the bicycle, but the person that pedals faster dictates the speed of the bicycle. 
So if person A pedals at a speed of 5, tandemSpeed = max(speedA, speedB)

You’re given two lists of positive integers: one that contains the speeds of riders wearing red shirts and 
one that contains the speeds of riders wearing blue shirts. Each rider is represented by a single positive integer,
which is the speed that they pedal a tandem bicycle at. Both lists have the same length, meaning that there are as 
many red-shirt riders as there are blue-shirt riders. Your goal is to pair every rider wearing a red shirt with a 
rider wearing a blue shirt to operate a tandem bicycle.

Write a function that returns the maximum possible total speed or the minimum possible total speed of all of the tandem bicycles
being ridden based on an input parameter, fastest. If fastest = true, your function should return the maximum possible total speed; 
otherwise it should return the minimum total speed.

Total speed” is defined as the sum of the speeds of all the tandem bicycles being ridden.
For example, if there are 4 riders (2 red-shirt riders and 2 blue-shirt riders) who have speeds of 1, 3, 4, 5, and 
if they’re paired on tandem bicycles as follows: [1, 4], [5, 3], then the total speed of these tandem bicycles is 4 + 5 = 9.

Sample Input:-
redShirtSpeeds=[5,5,3,9,2]
blueShirtSpeeds=[3,6,7,2,1]
Fastest = true

Sample Output:-32
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxTotalSpeed(vector<int>red,vector<int>blue,int size){
    int val=0;
    bool perfectSize = (size%2 == 0)?true:false; 


    for(int i=0;i<size;i++){
        if(!perfectSize && i == size-1){
            val += red[i]+blue[i];
        }else{
            val += max(red[i],red[i+1])+max(blue[i],blue[i+1]);
            i++;
        }

    }

    return val;
}

int minTotalSpeed(vector<int>red,vector<int>blue,int size){
    int val=0;
    bool perfectSize = (size%2) == 0?true:false; 


    for(int i=0;i<size;i++){
        if(!perfectSize && i == size-1){
            val += red[i]+blue[i];
        }else{
            val += min(red[i],red[i+1])+min(blue[i],blue[i+1]);
            i++;
        }

    }

    return val;
}

int main(){

    int size;
    vector<int>redShirt;
    vector<int>blueShirt;
    bool Fastest=true;

    cin>>size;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        redShirt.push_back(temp);
    }
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        blueShirt.push_back(temp);
    }

    cin>>Fastest;
    sort(redShirt.begin(),redShirt.end());
    sort(blueShirt.begin(),blueShirt.end());

    if(Fastest){
        cout<<maxTotalSpeed(redShirt,blueShirt,size);
    }else{
        cout<<minTotalSpeed(redShirt,blueShirt,size);
    }


    return 0;
}