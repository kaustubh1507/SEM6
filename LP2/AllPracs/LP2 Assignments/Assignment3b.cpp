#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Process{
    public:
    int at,bt,ct,wt,tat;
    int rt;
    Process(int at, int bt) : at(at),bt(bt), rt(bt){
        ct = tat = wt =0;
        // rt = bt;
    }
};
class Scheduling{
    public:
    vector <int> schedule;
    void gaant(){}
    int findMin(vector <Process>& p, int t){
        int minVal = INT16_MAX;
        int minIndex=-1;
        // for(int i =0; i< p.size(); i++){
        //     cout<<p[i].at<<p[i].bt<<p[i].rt<<endl;
        // }
        for(int i =0; i<p.size(); i++){
            //cout<<p[i].rt;
            if(p[i].rt>0 && p[i].rt<minVal && p[i].at<= t){
                minVal = p[i].rt;
                minIndex=i;
            }
        }
        return minIndex;
    }
    bool allZero(const vector <Process>& p){
        for(int i =0; i< p.size(); i++){
            if(p[i].rt!=0){
                return false;
            }
        }
        return true;
    }
    void scheduler(vector <Process>& p){
        int t =0;
        int index;
        while(!this->allZero(p)){
            index = this->findMin(p,t);
            //cout<<index;
            if(index!=-1){
                schedule.push_back(index);
                p[index].rt--;
                //cout<<"ab";
            }
            else{
                schedule.push_back(-1);
            }
            t++;
            if(p[index].rt==0){
                p[index].ct = t;
                p[index].wt = p[index].ct-p[index].at-p[index].bt;
                p[index].tat= p[index].ct - p[index].at;
            }
            
        }
        
        for(int i =0; i<schedule.size(); i++){
            cout<<"|"<<schedule[i]+1<<"|";
        }
    }

};
int main(){
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;
    vector <Process> p;
    for(int i = 0; i<n; i++){
        int at,bt;
        cout<<"Enter Arrival Time and Burst Time";
        cin>>at>>bt;
        p.push_back(Process(at,bt));
    }
    // for(int i =0; i< n; i++){
    //     cout<<p[i].at<<p[i].bt<<p[i].rt<<endl;
    // }
    Scheduling s;
    s.scheduler(p);

    return 0;
}