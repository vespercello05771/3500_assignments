#include <bits/stdc++.h>

using namespace std;

class process{
    int id;
    int arrival_time;
    int burst_time;
    string type;
    int priority;
    
    public:
        process(int id , int arrival_time , int burst_time , string type , int priority){
            this->id = id;
            this->arrival_time = arrival_time;
            this->burst_time =burst_time ;
            this->type = type;
            this->priority = priority;
        }
}
;


int main(){

    int RRquantum ;cin>>RRquantum;

    int N  ; cin>> N;

    queue<process> sys;
    queue<process> ip;
    queue<process> iep;
    queue<process> bp;
    queue<process> std;
    
    for(int i = 0;i<N;i++){
        int id;cin>>id;
        int arrival_time;cin>>arrival_time;
        int burst_time;cin>>burst_time;
        string type;cin>>type;
        int priority;cin>>priority;

        if(priority == 0) priority = INT_MAX;

        process proc(id,arrival_time, burst_time , type, priority);

        if(type == "sys"){
            sys.push(proc);
        }
        if(type == "ip"){
            ip.push(proc);
        }
        if(type == "iep"){
            iep.push(proc);
        }
        if(type == "bp"){
            bp.push(proc);
        }
        if(type == "std"){
            std.push(proc);
        }
        
    }




}