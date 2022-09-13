#include <bits/stdc++.h>

using namespace std;

class process{    
    public:
        string id;
        int arrival_time;
        int burst_time;
        string type;
        int priority;
        int initial_burst;
        int completion_time;
        int TAT;
        int WT;
        process(string id , int arrival_time , int burst_time , string type , int priority){
            this->id = id;
            this->arrival_time = arrival_time;
            this->burst_time =burst_time ;
            initial_burst = burst_time;
            this->type = type;
            this->priority = priority;
        }
}
;

struct prioritycomp{
    bool operator()(const process &a, const process &b){
        if(a.priority == b.priority ){
            if(a.arrival_time == b.arrival_time) return a.id > b.id;

            return a.arrival_time > b.arrival_time ;
        }

        return a.priority > b.priority;
    }
};

struct sjfcomp{
    bool operator()(const process &a, const process &b){
        if(a.burst_time == b.burst_time ){
            if(a.arrival_time == b.arrival_time) return a.id > b.id;

            return a.arrival_time > b.arrival_time ;
        }

        return a.burst_time > b.burst_time;
    }
};

struct fcfscomp{
    bool operator()(const process &a, const process &b){
        return a.arrival_time > b.arrival_time;
    }
};

int main(){

    int RRquantum ;cin>>RRquantum;

    int N  ; cin>> N;

    priority_queue<process , vector<process>, prioritycomp> sys;
    priority_queue<process , vector<process>, fcfscomp> ip;
    priority_queue<process , vector<process>, fcfscomp> iep;
    priority_queue<process , vector<process>, sjfcomp> bp;
    priority_queue<process , vector<process>, sjfcomp> std;
    
    unordered_map<int,vector<process>> process_arriving_at_time; 
    vector<process> process_list;
    int clock_end = 0;
    for(int i = 0;i<N;i++){
        string id;cin>>id;
        int arrival_time;cin>>arrival_time;
        int burst_time;cin>>burst_time;
        clock_end+=burst_time;
        string type;cin>>type;
        int priority;cin>>priority;

        if(priority == 0) priority = INT_MAX;

        process proc(id,arrival_time, burst_time , type, priority);
        process_arriving_at_time[arrival_time].push_back(proc);
        
    }
    

    int clock = 0,switch_queue = 0,counter = 0,process_left = N;
    while(process_left){
        cout<<"clock status : "<<clock<<endl;
        cout<<"switch_queue : "<<switch_queue<<endl;
        for(auto a : process_arriving_at_time[clock]){
            if(a.type == "sys"){
                sys.push(a);
            }
            if(a.type == "ip"){
                ip.push(a);
            }
            if(a.type == "iep"){
                iep.push(a);
            }
            if(a.type == "bp"){
                bp.push(a);
            }
            if(a.type == "sp"){
                std.push(a);
            }
        }
        if(switch_queue%5 == 0){
            if(sys.empty()){
                switch_queue++;
                counter = 0 ;
                cout<<"no process in Q ********************"<<switch_queue<<endl;
                continue;
            }
            else{
                process proc = sys.top();
                sys.pop();
                cout<<"currently executing process : "<< proc.id<<" and "<<proc.burst_time<<endl;
                proc.burst_time--;
                sys.push(proc);

                if(proc.burst_time == 0){
                    cout<<"process : "<<proc.id<<" is done"<<endl;
                    proc.completion_time =clock+1;
                    proc.TAT = proc.completion_time - proc.arrival_time;
                    proc.WT = proc.TAT - proc.initial_burst;
                    process_list.push_back(proc);
                    process_left--;
                    sys.pop();
                }
                counter++;
                if(counter == RRquantum){
                    switch_queue++;
                    counter = 0;
                    clock++;
                    continue;
                }
                
            }

        }
        if(switch_queue%5 == 1){
            if(ip.empty()){
                switch_queue++;
                counter = 0;
                cout<<"no process in Q ********************"<<switch_queue<<endl;
                continue;
            }
            else{
                process proc = ip.top();
                ip.pop();
                cout<<"currently executing process : "<< proc.id<<" and "<<proc.burst_time<<endl;
                proc.burst_time--;
                ip.push(proc);

                if(proc.burst_time == 0){
                    cout<<"process : "<<proc.id<<" is done"<<endl;
                    proc.completion_time =clock+1;
                    proc.TAT = clock - proc.arrival_time;
                    proc.WT = proc.TAT - proc.initial_burst;
                    process_list.push_back(proc);
                    process_left--;
                    ip.pop();
                }
                counter++;
                if(counter == RRquantum){
                    switch_queue++;
                    counter = 0;
                    clock++;
                    continue;
                }
            }
        }
        if(switch_queue%5 == 2){
            if(iep.empty()){
                switch_queue++;
                counter = 0;
                cout<<"no process in Q ********************"<<switch_queue<<endl;
                continue;
            }
            else{
                process proc = iep.top();
                iep.pop();
                cout<<"currently executing process : "<< proc.id<<" and "<<proc.burst_time<<endl;
                proc.burst_time--;
                iep.push(proc);

                if(proc.burst_time == 0){
                    cout<<"process : "<<proc.id<<" is done"<<endl;
                    proc.completion_time =clock+1;
                    proc.TAT = clock - proc.arrival_time;
                    proc.WT = proc.TAT - proc.initial_burst;
                    process_list.push_back(proc);
                    process_left--;
                    iep.pop();
                }
                counter++;
                if(counter == RRquantum){
                    switch_queue++;
                    counter = 0;
                    clock++;
                    continue;
                }
            }
        }
        if(switch_queue%5 == 3){
            if(bp.empty()){
                switch_queue++;
                counter = 0;
                cout<<"no process in Q ********************"<<switch_queue<<endl;
                continue;
    
            }
            else{
                process proc = bp.top();
                cout<<"currently executing process : "<< proc.id<<" and "<<proc.burst_time<<endl;
                bp.pop();
                proc.burst_time--;
                bp.push(proc);
                if(proc.burst_time == 0){
                    cout<<"process : "<<proc.id<<" is done"<<endl;
                    proc.completion_time =clock+1;
                    proc.TAT = clock - proc.arrival_time;
                    proc.WT = proc.TAT - proc.initial_burst;
                    process_list.push_back(proc);
                    process_left--;
                    bp.pop();
                }
                counter++;
                if(counter == RRquantum){
                    switch_queue++;
                    counter = 0;
                    clock++;
                    continue;
                }
            }
        }
        if(switch_queue%5 == 4){
            if(std.empty()){
                switch_queue++;
                counter = 0;
                cout<<"no process in Q ********************"<<switch_queue<<endl;
                continue;
            }
            else{
                process proc = std.top();
                std.pop();
                cout<<"currently executing process : "<< proc.id<<" and "<<proc.burst_time<<endl;
                proc.burst_time--;
                std.push(proc);

                if(proc.burst_time == 0){
                    cout<<"process : "<<proc.id<<" is done"<<endl;
                    proc.completion_time =clock+1;
                    proc.TAT = clock - proc.arrival_time;
                    proc.WT = proc.TAT - proc.initial_burst;
                    process_list.push_back(proc);
                    process_left--;
                    std.pop();
                }
                counter++;
                if(counter == RRquantum){
                    switch_queue++;
                    counter = 0;
                    clock++;
                    continue;
                }
            }
        }

        clock++;
    }


    cout<<endl<<"Order of Exec."<<endl;

    cout<< left<< setw(13)<< "Process ID"<< left<< setw(20)<< "Completetion-time"<< left<< setw(20)<< "Turn-Around-Time"<< left<< setw(20)<< "Waiting-Time"<< endl;

    for(auto a: process_list){
        cout<< left<< setw(13)<< a.id<< left<< setw(20)<< a.completion_time<< left<< setw(20)<<a.TAT<< left<< setw(20)<< a.WT<< endl;
    }



}