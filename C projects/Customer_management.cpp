#include <bits/stdc++.h>
using namespace std;
struct Customers{
    char name[100];
    char contact[100];
    int membership_number;
    int total_points;
};
//functions are used for this project
void input(struct Customers info[],int n);
void show_info(struct Customers info[],int n);
void most_valuable_customer(struct Customers info[],int n);
int main(){
    cout<<"Welcome to Customer Information Center"<<endl;
    cout<<"............................................................."<<endl;
    cout<<"How many customers do you want to add"<<endl;
    int n;
    cin>>n;
    struct Customers info[n];
    input(info,n);
    while(1){
        cout<<"Enter Your Choice (1-3)"<<endl;
        cout<<"1. Show the information of the customer"<<endl;
        cout<<"2. show the kth most valuable customer"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Choose your option: "<<endl;
        int choice;
        cin>>choice;
        if(choice<1 || choice >3)
            cout<<"Invalid Choice. Try to choose between (1-3)"<<endl;
        else{
            if(choice == 1)
                show_info(info,n);
            else if(choice == 2)
                most_valuable_customer(info,n);
            else if(choice ==3){
                cout<<"Exiting the system"<<endl;
                cout<<"Thank you for using the system"<<endl;
                cout<<"Created by |$AJAX$|"<<endl;
                cout<<"............................................................."<<endl;
                break;
            }
        }
    }
    return 0;
}
void input(struct Customers info[],int n){
        for(int i=0;i<n;i++){
        cout<<"Enter Customer Name: "<<endl;
        cout<<"............................................................."<<endl;        getchar();
        scanf("%[^\n]",info[i].name);
        cout<<"Enter Customer Phone Number: ";
        getchar();
        scanf("%[^\n]",info[i].contact);
        cout<<"Enter Membership Number: ";
        cin>>info[i].membership_number;
        cout<<"Enter total points: ";
        cin>>info[i].total_points;
        cout<<"Customer data added succesfully"<<endl;
    }
    cout<<"............................................................."<<endl;
}
void show_info(struct Customers info[],int n){
    cout<<"Provide the Membership Number of customer"<<endl;
    cout<<"............................................................."<<endl;
    int provided_number;cin>>provided_number;
    bool flag=false;
    int found_index=0;
    for(int i=0;i<n;i++){
        if(provided_number==info[i].membership_number){
            flag=true;
            found_index=i;
            break;
        }
        else flag=false;
    }
    if(flag){
        cout<<"Customer found!"<<endl;
        cout<<"Customer's name: ";
        cout<<info[found_index].name<<endl;
        cout<<"Customer's Contact: ";
        cout<<info[found_index].contact<<endl;
        cout<<"Customers's Total point: ";
        cout<<info[found_index].total_points<<endl;
    }
    else cout<<"Customer not found!"<<endl;
    cout<<"............................................................."<<endl;
}
void most_valuable_customer(struct Customers info[],int n){
    cout<<"provide the value of k to get the the kth valuable customer"<<endl;
    cout<<"............................................................."<<endl;
    int k;
    cin>>k;
    //using selection sort here
    for(int i=0;i<n-1;i++){
        int maximum_index=i;
        for(int j=i+1;j<n;j++){
            if(info[j].total_points<info[maximum_index].total_points)
                maximum_index=j;
        }
        int temp=info[i].total_points;
        info[i].total_points=info[maximum_index].total_points;
        info[maximum_index].total_points=temp;
    }
    cout<<"Kth most valuable customer"<<endl;
    cout<<"Customer Name: "<<info[k].name<<endl;
    cout<<"Customer Contact: "<<info[k].contact<<endl;
    cout<<"Customer Membership Number: "<<info[k].membership_number<<endl;
    cout<<"Customer Total Points: "<<info[k].total_points<<endl;
    cout<<"............................................................."<<endl;
}
