#include<iostream>
#include<iomanip>
#include<unordered_map>
using namespace std;

int m[20][20], total,connections,space,cost,visited[20];
string office_name[20],start_point,end_point;
unordered_map<string,int>map;

void insert(){
    cout<<"Enter number of offices: ";
    cin>>space;

    for(int i=0; i<space; i++){
        for(int j=0; j<space; j++){
            m[i][j]=999;
        }
    }

    for(int i=0; i<space; i++){
        cout<<"Enter Name of Office "<<i+1<<" : ";
        cin>>office_name[i];
        map[office_name[i]]=i;
    }

    cout<<"Enter Number of Connections : ";
    cin>>connections;

    cout<<"Give cost of Connections : "<<endl;
    for(int i=0; i<connections; i++){
        cout<<"Enter start Point : ";
        cin>>start_point;

        cout<<"Enter end point : ";
        cin>>end_point;

        cout<<"Enter Cost : ";
        cin>>cost;

        m[map[start_point]] [map[end_point]]=m[map[end_point]][map[start_point]]=cost;
        cout<<endl;
    }
}

void display(){
    cout<<"---- A D J AE C E N C Y  M A T R I X -----"<<endl;
    cout<<"                  ";
    for(int i=0; i<space; i++){
        cout<<left<<setw(15)<<office_name[i];
    }
    cout<<endl;
    for(int i=0; i<space; i++){
        cout<<left<<setw(15)<<office_name[i];
        for(int j=0; j<space; j++){
            cout<<left<<setw(15)<<m[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    insert();
    display();
    return 0;
}
