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
    char name[size];
    char clan[size];
    int mark[row][col];
    double avg;
};
void read_file(struct Student students[],FILE *infile,int *student_count,char dummy[]);
void write_file(struct Student students[],FILE *outfile,int *student_count,char dummy[]);
void total_marks(struct Student students[],int *student_count,FILE *outfile,char dummy[]);
int main(){
    struct Student students[10];
    int student_count=0;
    char dummy[size];
    FILE *in_file,*out_file;
    in_file=fopen("nevermore_data.txt","r");
    out_file=fopen("nevermore_output.txt","w");
    if(in_file==NULL || out_file==NULL){
        printf("File could not found\n");
        return 1;
    }
    else{
        printf("File read successfully!\n");
        read_file(students,in_file,&student_count,dummy);
        write_file(students,out_file,&student_count,dummy);
        total_marks(students,&student_count,out_file,dummy);
        fclose(in_file);
        fclose(out_file);
    }
    return 0;
}
void read_file(struct Student students[],FILE *infile,int *student_count,char dummy[]){
    while(fscanf(infile," %[^\n]",students[*student_count].name)!=EOF){
        fscanf(infile," %[^\n]",students[*student_count].clan);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                fscanf(infile,"%d",&students[*student_count].mark[i][j]);
        fscanf(infile,"%lf",&students[*student_count].avg);
        fscanf(infile," %[^\n]",dummy);
        (*student_count)++;
    }
}
void write_file(struct Student students[],FILE *outfile,int *student_count,char dummy[]){
    for(int i=0;i<*student_count;i++){
        fprintf(outfile,"%s\n",students[*student_count-1].name);
        fprintf(outfile,"%s\n",students[*student_count-1].clan);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                fprintf(outfile,"%d ",students[*student_count-1].mark[i][j]);
            }
            fprintf(outfile,"\n");
        }
        fprintf(outfile,"%lf\n",students[*student_count-1].avg);
        fprintf(outfile,"%s\n",dummy);
        fprintf(outfile,"\n");
    }
}
void total_marks(struct Student students[],int *student_count,FILE *outfile,char dummy[]){
    int sum1,sum2,sum3;
    for(int i=0;i<col;i++)
        sum1+=students[*student_count].mark[0][i];
    for(int i=0;i<col;i++)
        sum2+=students[*student_count].mark[1][i];
    for(int i=0;i<col;i++)
        sum3+=students[*student_count].mark[2][i];
    for(int i=0;i<(*student_count);i++){
        fprintf(outfile,"Student: %d\n",*student_count);
        fprintf(outfile,"Psychic total marks: %d\n",sum1);
        fprintf(outfile,"Combat total marks: %d\n",sum2);
        fprintf(outfile,"Monster total marks: %d\n",sum3);
        fprintf(outfile,"%s\n",dummy);
    }       
}
























// #include<stdio.h>
// #include<math.h>
// #include<string.h>
// #include<stdlib.h>
// #include<stdbool.h>
// #include<ctype.h>
// #define row 3
// #define col 4
// #define size 10000
// struct Student{
//     char name[size],clan[size];
//     int marks[row][col];
//     double avg;
// };
// void read_file(struct Student students[],FILE *infile,char dummy[],int *student_count);
// void write_file(struct Student students[],FILE *outfile,char dummy[],int *student_count);
// void total_print(struct Student students[],FILE *outfile,int *student_count);
// int main(){
//     struct Student students[10];
//     int student_count=0;
//     FILE *in_file, *Out_file;
//     in_file=fopen("nevermore_data.txt","r");
//     Out_file=fopen("nevermore_output.txt","w");
//     if(in_file == NULL || Out_file == NULL){
//         printf("Could not open the file\n");
//         return 1;
//     }
//     else{
//         printf("File Opened Successfully. Your operation has been done. Check the Output file");
//         char dummy[size]; // taking a dummy string to take the dots (....);
//         read_file(students,in_file,dummy,&student_count);
//         write_file(students,Out_file,dummy,&student_count);
//         total_print(students,Out_file,&student_count);
//     }
//     fclose(in_file);
//     fclose(Out_file);
//     return 0;
// }
// void read_file(struct Student students[],FILE *infile,char dummy[], int *student_count){
//     while(fscanf(infile," %[^\n]",students[*student_count].name)!=EOF){ // this will read until he finds a name
//         //as we have taken name as input in the while loop, we can input the clan.
//         // /!/! if you want to avoid newline, provide a space before the string input
//         fscanf(infile, " %[^\n]",students[*student_count].clan);
//         //taking the input of marks
//         for(int i=0;i<row;i++)
//             for(int j=0;j<col;j++)
//                 fscanf(infile,"%d",&students[*student_count].marks[i][j]);
//         fscanf(infile,"%lf",&students[*student_count].avg);
//         fscanf(infile," %[^\n]",dummy);
//         (*student_count)++;//just increasing the count of the students.
//     }
// }
// void write_file(struct Student students[],FILE *outfile,char dummy[],int *student_count){
//     //decrementing the student value by 1 so that we get the exact value to print.
//             fprintf(outfile,"%s\n",students[(*student_count)-1].name);
//             fprintf(outfile,"%s\n",students[(*student_count)-1].clan);
//             for(int i=0;i<row;i++){
//                 for(int j=0;j<col;j++){
//                     fprintf(outfile,"%d ",students[(*student_count)-1].marks[i][j]);
//                 }
//                 fprintf(outfile,"\n");
//             }
//             fprintf(outfile,"%.1lf\n",students[(*student_count)-1].avg);
//             fprintf(outfile,"%s\n",dummy);
//             fprintf(outfile,"\n");
// }
// void total_print(struct Student students[],FILE *outfile,int *student_count){
//     int total_marks1=0,total_marks2=0,total_marks3=0;
//     for(int i=0;i<col;i++)
//         total_marks1+=students[*student_count].marks[0][i];
//     for(int i=0;i<col;i++)
//         total_marks2+=students[*student_count].marks[1][i];
//     for(int i=0;i<col;i++) 
//         total_marks3+=students[*student_count].marks[2][i];
//     fprintf(outfile,"Psychic total marks: %d\n",total_marks1);
//     fprintf(outfile,"Celestial total marks: %d\n",total_marks2);
//     fprintf(outfile,"Kaisshar total marks: %d\n",total_marks3);
// }




