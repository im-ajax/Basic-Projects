#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct student {
    char name[1000];
    int id;
    int marks[5];
    float avg;
};
int main() {
    printf("Student Performance Management System\n");
    printf("1. Add a new student\n");
    printf("2. Display All students\n");
    printf("3. Find Top Performer\n");
    printf("4. Find failing students\n");
    printf("5. Exit\n");
    struct student list[100];
    int total_Students=0;
    while(1){
        printf("Enter Your choice : ");
        int choice;
        scanf("%d",&choice);
        if(choice==1){
            printf("How many students do you want to add?: ");
            int quantity;
            scanf("%d",&quantity);
            for (int i=0;i<quantity;i++){
                printf("Enter Student name: ");
                getchar();
                scanf("%[^\n]",list[total_Students].name);
                printf("Enter Student ID: ");
                scanf("%d",&list[total_Students].id);
                printf("Enter marks for 5 subjects: \n");
                int total_marks = 0;
                for(int j=0;j<5;j++){
                    scanf("%d",&list[total_Students].marks[j]);
                    total_marks+=list[total_Students].marks[j];
                }
                list[total_Students].avg=total_marks/5.0;
                printf("Student added successfully\n");
                total_Students++;
            }
        }
        else if(choice==2){
            if(total_Students==0)
                printf("No students added yet.\n");
            else{
                printf("Student Records:\n");
                for (int i=0;i<total_Students;i++){
                    printf("ID: %d, ",list[i].id);
                    printf("Name: %s, ",list[i].name);
                    printf("Marks: ");
                    for (int j=0;j<5;j++)
                        printf("%d ",list[i].marks[j]);
                    printf(", Average: %.1f\n",list[i].avg);
                }
                printf("\n");
            }
        }
        else if (choice==3){
            if (total_Students==0)
                printf("No students available.\n");
            else{
                float max=list[0].avg;
                int topper=0;
                for (int i=1;i<total_Students;i++){
                    if (list[i].avg>max) {
                        max =list[i].avg;
                        topper=i;
                    }
                }
                printf("Top performer: ");
                printf("Name: %s, ",list[topper].name);
                printf("Average Marks: %.1f\n",max);
            }
        }
        else if(choice==4){
            if(total_Students==0)
                printf("No students available.\n");
            else{
                printf("Failing Students:\n");
                int anyFailed=0;
                for(int i=0;i<total_Students;i++){
                    int failed_sub_count=0;
                    for (int j=0;j<5;j++){
                        if (list[i].marks[j]<40)
                            failed_sub_count++;
                    }
                    if(failed_sub_count>0){
                        printf("ID: %d, Name: %s, Failed Subjects: %d\n",list[i].id,list[i].name,failed_sub_count);
                        anyFailed=1;
                    }
                }
                if(!anyFailed)
                    printf("No failing students.\n");
            }
        }
        else if (choice==5){
            printf("Exiting the system.\n");
            printf("Thank you for using our system");
            printf("Created By _$AJAX$_");
            break;
        }
        else
            printf("Invalid input. Provide something valid...\n");
    }
    return 0;
}
