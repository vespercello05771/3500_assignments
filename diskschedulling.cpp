#include <bits/stdc++.h>
using namespace std;

//********************************** FCFS *****************************************
void FCFS(int requests[],int head_position)
{

	cout << "FCFS: " << endl;
	int distance = abs(head_position - requests[0]);
    cout<<requests[0]<<"->";
	for (int i = 1; i < 1000; i++) {
        cout<<requests[i]<<"->";
		distance += abs(requests[i] - requests[i - 1]);
	}
	
	cout<<endl;
    cout<<"Total head movements = "<< distance<<'\n';
    cout<<"Average head movement = "<<(float)distance/1000<<'\n';
}

//********************************** SCAN *****************************************
void SCAN(int requests[], int head_position) {
	int i,j,k,n = 1000,m = 5000,sum=0,x,y,h = head_position;
    
    vector <int> a(n),b;
    for(i=0;i<n;i++){
       a[i] = requests[i];
    }
    
    int temp=h;
    a.push_back(h);
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            b.push_back(a[i]);
        }
    }
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
}

//********************************** CLOOK ****************************************
void CLOOK(int requests[], int head_position) {
	int i,j,k,n = 1000,m = 5000,sum=0,x,y,h = head_position;
    vector <int> a(n),l;
    for(i=0;i<n;i++){
        a[i] = requests[i];
    }
    
    a.push_back(h);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=0;i<k;i++){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=a.size()-1;i>k;i--){
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    cout<<temp;
    for(i=1;i<l.size();i++){
        cout<<" -> "<<l[i]<<' ';
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
}

//********************************** CSCAN ****************************************
void CSCAN(int requests[], int head_position)
{
    int i,j,k,n = 1000,m = 5000,sum=0,x,y,h = head_position;
    vector <int> a(n),b;
    for(i=0;i<n;i++){
        a[i] = requests[i];
    }
    
	int temp=h;
    a.push_back(h);
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=0;i<=k-1;i++){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=a.size()-1;i>=k+1;i--){
            b.push_back(a[i]);
        }
    }
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    return ;
}

//********************************** LOOK ****************************************
void LOOK(int requests[], int head_position) {
	int i,j,k,n = 1000,m = 5000,sum=0,x,y,h = head_position;
    vector <int> a(n),l;
    for(i=0;i<n;i++){
        a[i] = requests[i];
    }
    a.push_back(h);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    cout<<temp;
    for(i=1;i<l.size();i++){
        cout<<" -> "<<l[i]<<' ';
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    return ;
}

//********************************** SSTF ****************************************
void SSTF(int requests[], int head_position) {
	int i,j,k,n = 1000,m = 5000,sum=0,x,y,h = head_position;
    vector <int> a(n),b;
    map <int,int> mp;
    for(i=0;i<n;i++){
        a[i] = requests[i];
    }
    int temp=h;
    int ele;
    b.push_back(h);
    int count=0;
    while(count<n){
        //initially taking diff to be very large.
        int diff=999999;
        //traversing in map to find the least difference
        for(auto q:mp){
            if(abs(q.first-temp)<diff){
                ele=q.first;
                diff=abs(q.first-temp);
            }
        }
        //deleting the element that has the least
        //difference from the map
        mp[ele]--;
        if(mp[ele]==0){
            mp.erase(ele);
        }
        //adding that element to our output array.
        b.push_back(ele);
        temp=ele;
        count++;
    }
    //printing the output array
    cout<<b[0];
    temp=b[0];
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    return ;
}

//********************************** Driver Code **********************************
int main()
{
	//INPUTS
    

    int requests[1000];
    for(int i = 0;i<1000;i++){
        requests[i] = rand()%5000;
    }
	int head_position = 2000;
	
    cout<<"Enter initial disk position: "<<endl;

    cin>>head_position;

    cout<<"Enter the algorithm to be used : "<<endl;
    string algo ;
    cin>>algo;

    
    if(algo == "LOOK"){
        LOOK(requests, head_position);
    }
    else if (algo == "SSTF")
    {
        SSTF(requests, head_position);
    }
    else if (algo == "CSCAN")
    {
        CSCAN(requests, head_position);
    }
    else if (algo == "CLOOK")
    {
        CLOOK(requests, head_position);
    }
    else if (algo == "FCFS")
    {
        FCFS(requests, head_position);
    }
    else if (algo == "SCAN")
    {   
        SCAN(requests, head_position);
    }
    
}