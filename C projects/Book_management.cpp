#include <bits/stdc++.h>
using namespace std;
struct Book{
    char title[100];
    int isbn;
    char author_name[100];
    int publication_year;
    float price;
};
//functions were used to do this project
void addbook(struct Book books[],int n);
void search_by_ISBN(struct Book books[],int n);
void cheapest_book(struct Book books[],int n);
void sort_by_publication_year(struct Book books[],int n);
int main(){
    cout<<"welcome to Libaray Management System"<<endl;
    cout<<"................................................"<<endl;
    cout<<"How many books do you want to add"<<endl;
    long long m;
    cin>>m;
    struct Book books[m];
    while(1){
        cout<<"Enter Your Choice between (1-5): "<<endl;
        cout<<"1. Add a new book record"<<endl;
        cout<<"2. Search for a book by ISBN"<<endl;
        cout<<"3. Kth cheapest book"<<endl;
        cout<<"4. Show all the book sorted by publication year"<<endl;
        cout<<"5. Exit"<<endl;
        int choice;cin>>choice;
        if(choice <1 || choice > 5)
            cout<<"Invalid Choice! Try to choose between (1-5)."<<endl;
        else{
            int choice;cin>>choice;
            if(choice ==1)
                addbook(books,m);
            else if(choice == 2)
                search_by_ISBN(books,m);
            else if(choice == 3)
                cheapest_book(books,m);
            else if(choice ==4)
                sort_by_publication_year(books,m);
            else if(choice ==5){
                cout<<"Exiting the system"<<endl;
                cout<<"Thank you for using our system"<<endl;
                cout<<"................................................"<<endl;
                break;
            }
        }
    }
    return 0;
}
void addbook(struct Book books[],int n){
    cout<<"Adding a book"<<endl;
    cout<<"................................................"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Provide the title"<<endl;
        getchar();
        scanf("%[^\n]",books[i].author_name);
        cout<<"Provide the ISBN"<<endl;
        cin>>books[i].isbn;
        cout<<"Provide the author name"<<endl;
        getchar();
        scanf("%[^\n]",books[i].author_name);
        cout<<"Provide the publication year"<<endl;
        cin>>books[i].publication_year;
        cout<<"provide the price"<<endl;
        cin>>books[i].price;
        cout<<"Book added successfully"<<endl;
    }
    cout<<"................................................"<<endl;
}
void search_by_ISBN(struct Book books[],int n){
    cout<<"................................................"<<endl;
    if(n==0) {
        cout<<"No books were found!"<<endl;
        cout<<"................................................"<<endl;
    }
        else{
        cout<<"Searching by ISBN"<<endl;
        cout<<"Provide the ISBN"<<endl;
        int searched_isbn;
        cin>>searched_isbn;
        for(int i=0;i<n;i++){
            if(searched_isbn==books[i].isbn){
                cout<<"Found Book!"<<endl;
                cout<<books[searched_isbn].title<<endl;
                break;
            }
            else cout<<"Book not found"<<endl;
        }
    }
    cout<<"................................................"<<endl;
}
void cheapest_book(struct Book books[],int n){
    cout<<"................................................"<<endl;
    if(n==0){
        cout<<"No Books were found!"<<endl;
        cout<<"................................................"<<endl;
    }    
    else{
        //using selection sort
        for(int i=0;i<n-1;i++){
            int low_priced_index=i;
            for(int j=i+1;j<n;j++){
                if(books[j].price<books[low_priced_index].price){
                    low_priced_index=j;
                }
            }
            int temp=books[i].price;
            books[i].price=books[low_priced_index].price;
            books[i].price=temp;
        }
        cout<<"Provide the index of kth lowest book price"<<endl;
        cout<<"................................................"<<endl;
        int k;
        cin>>k;
        cout<<"The kth cheapest book is: "<<endl;
        cout<<books[k].title<<endl;
        cout<<books[k].author_name<<endl;
        cout<<books[k].price<<endl;
        cout<<books[k].isbn<<endl;
    }
    cout<<"................................................"<<endl;
}
void sort_by_publication_year(struct Book books[],int n){
    if(n==0){
        cout<<"No Books were found!"<<endl;
        cout<<"................................................"<<endl;
    }
    else{
        for(int i=0;i<n-1;i++){
        int minimum_publish_index=i;
            for(int j=i+1;j<n;j++){
                if(books[i].publication_year>books[minimum_publish_index].publication_year)
                    minimum_publish_index=j;
            }
            int temp=books[i].publication_year;
            books[i].publication_year=books[minimum_publish_index].publication_year;
            books[minimum_publish_index].publication_year=temp;
        }
        cout<<"Providing the list of books"<<endl;
        cout<<"................................................"<<endl;
        for(int i=0;i<n;i++){
            cout<<"Book title: "<<books[i].title<<endl;
            cout<<"ISBN: "<<books[i].isbn<<endl;
            cout<<"Publication Year: "<<books[i].publication_year<<endl;
        }
    }
    cout<<"................................................"<<endl;
}

































