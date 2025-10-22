#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define row 3
#define col 4
#define size 10000
struct Student{
    char name[size],clan[size];
    int marks[row][col];
    double avg;
};
int main(){
    struct Student students[10];
    int student_count=0;
    FILE *in_file, *Out_file;
    in_file=fopen("nevermore_data.txt","r");
    Out_file=fopen("nevermore_output.txt","w");
    if(in_file == NULL || Out_file == NULL){
        printf("Could not open the file\n");
        return 1;
    }
    else{
        printf("File Opened Successfully. Your operation has been done. Check the Output file");
        char dummy[size]; // taking a dummy string to take the dots (....);
        while(fscanf(in_file," %[^\n]",students[student_count].name)!=EOF){ // this will read until he finds a name
            //as we have taken name as input in the while loop, we can input the clan.
            // /!/! if you want to avoid newline, provide a space before the string input
            fscanf(in_file, " %[^\n]",students[student_count].clan);
            //taking the input of marks
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    fscanf(in_file,"%d",&students[student_count].marks[i][j]);
            fscanf(in_file,"%lf",&students[student_count].avg);
            fscanf(in_file," %[^\n]",dummy);
            student_count++;//just increasing the count of the students.
            //decrementing the student value by 1 so that we get the exact value to print.
            fprintf(Out_file,"%s\n",students[student_count-1].name);
            fprintf(Out_file,"%s\n",students[student_count-1].clan);
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    fprintf(Out_file,"%d ",students[student_count-1].marks[i][j]);
                }
                fprintf(Out_file,"\n");
            }
            fprintf(Out_file,"%.1lf\n",students[student_count-1].avg);
            fprintf(Out_file,"%s\n",dummy);
            fprintf(Out_file,"\n");
        }

    }
    fclose(in_file);
    fclose(Out_file);
    return 0;
}


