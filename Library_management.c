#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct Book{
    char title[1000],Author_Name[1000],Availability_Status[1000];
    int Publication_Year;
};
void addBook(struct Book books[],int *count);
void searchBook(struct Book books[],int count,char title[]);
void updateStatus(struct Book books[],int count,char title[]);
void displayBooks(struct Book books[],int count);
int main(){
    printf("Library Management System: \n");
    printf("1. Add a new book.\n");
    printf("2. Search for a book by Title\n");
    printf("3. Update a book's availability status\n");
    printf("4. Display all books\n");
    printf("5. Exit\n");
    struct Book books[100];
    int count=0;
    while(1){
        printf("Enter Your Choice: ");
        int choice;scanf("%d",&choice);
        if(choice==1){
            addBook(books,&count);
        }
        else if(choice==2){
            printf("Enter book title to search: ");
            char title[1000];
            getchar();
            scanf("%[^\n]",title);
            searchBook(books,count,title);
        }
        else if(choice==3){
            printf("Enter book title to update: ");
            char title[1000];
            getchar();
            scanf("%[^\n]",title);
            updateStatus(books,count,title);
        }
        else if(choice==4){
            displayBooks(books,count);
        }
        else if(choice==5){
            printf("Exiting the system\n");
            printf("Thank you for using our system\n");
            printf("Created By _$AJAX$_");
            break;
        }
        else printf("Invalid Choice. Provide a valid choice\n");
    }
    return 0;
}
void addBook(struct Book books[],int *count){
        printf("How many books do you want to add?: ");
        int book_count;
        scanf("%d",&book_count);
        for(int i=0;i<book_count;i++){
            printf("Enter book title: ");
            getchar();
            scanf("%[^\n]",books[*count].title);
            printf("Enter author name: ");
            getchar();
            scanf("%[^\n]",books[*count].Author_Name);
            printf("Enter publication year: ");
            scanf("%d",&books[*count].Publication_Year);
            printf("Enter availability status(Available/Checked Out): ");
            getchar();
            scanf("%[^\n]",books[*count].Availability_Status);
            printf("Books added successfully\n");
            (*count)++;
        }
}
void searchBook(struct Book books[],int count,char title[]){
    bool found=false;
    for(int i=0;i<count;i++){
        if(strcasecmp(books[i].title,title)==0){
            printf("Title: %s, Author: %s, Year: %d, Status: %s\n",books[i].title,books[i].Author_Name,books[i].Publication_Year,books[i].Availability_Status);
            found = true;
            break;
        }
    }
    if(!found) printf("Book is not available\n");
}
void updateStatus(struct Book books[],int count,char title[]){
    bool found=false;
    for(int i=0;i<count;i++){
        if(strcmp(books[i].title,title)==0){
            printf("Enter new status(Available/Checked Out): ");
            getchar();
            scanf("%[^\n]",books[i].Availability_Status);
            printf("Book status updated successfully\n");
            found=true;
            break; 
        }
    }
    if(!found) printf("Book not found.\n");
}
void displayBooks(struct Book books[],int count){
    if(count==0){
        printf("No book available\n");
        return;
    }
    else{
        for(int i=0;i<count;i++){
            if(strcmp(books[i].Availability_Status,"Available")==0)
                printf("Title: %s, Author: %s, Year: %d, Status: %s\n",books[i].title,books[i].Author_Name,books[i].Publication_Year,books[i].Availability_Status);
        }
        for(int i=0;i<count;i++){
            if(strcmp(books[i].Availability_Status,"Checked Out")==0)
                printf("Title: %s, Author: %s, Year: %d, Status: %s\n",books[i].title,books[i].Author_Name,books[i].Publication_Year,books[i].Availability_Status);
        }
    }
}
// it was so hectic
