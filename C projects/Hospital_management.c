#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Doctor
{
    char name[50];
    char specialization[50];
    char phoneNo[11];
    int experienceYear;
    float salary;
};
struct Patient
{
    char name[50];
    char disease[50];
    char phoneNo[11];
    int age;
    float duePayment;
};
void addDoctor(struct Doctor doctors[], int *doctorCount);
void addPatient(struct Patient patients[], int *patientCount);
void viewDoctors(struct Doctor doctors[], int doctorCount);
void viewPatients(struct Patient patients[], int patientCount);
void updateDoctor(struct Doctor doctors[], int doctorCount);
void updatePatient(struct Patient patients[], int patientCount);
void removeDoctor(struct Doctor doctors[], int *doctorCount);
void removePatient(struct Patient patients[], int *patientCount);
void searchDoctorByName(struct Doctor doctors[], int doctorCount);
void searchPatientByName(struct Patient patients[], int patientCount);
void searchDoctorBySpecialization(struct Doctor doctors[], int doctorCount);
void searchPatientByDisease(struct Patient patients[], int patientCount);
void doctorWithHighestExperience(struct Doctor doctors[], int doctorCount);
void patientWithMaxDue(struct Patient patients[], int patientCount);
int main()
{
    struct Doctor doctors[100];
    struct Patient patients[100];
    int doctorCount = 0, patientCount = 0;
    int choice;
    printf("Hospital Management System\n");
    printf("...............................\n");
    printf("1.  View Doctor List\n");
    printf("2.  View Patient List\n");
    printf("3.  Add New Doctor\n");
    printf("4.  Add New Patient\n");
    printf("5.  Update Doctor\n");
    printf("6.  Update Patient\n");
    printf("7.  Remove Doctor\n");
    printf("8.  Remove Patient\n");
    printf("9.  Search Doctor by Name\n");
    printf("10. Search Doctor by Specialization\n");
    printf("11. Search Patient by Name\n");
    printf("12. Search Patient by Disease\n");
    printf("13. Doctor with Highest Experience\n");
    printf("14. Patient with Maximum Due Payment\n");
    printf("15. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1)
            viewDoctors(doctors, doctorCount);
        else if (choice == 2)
            viewPatients(patients, patientCount);
        else if (choice == 3)
            addDoctor(doctors, &doctorCount);
        else if (choice == 4)
            addPatient(patients, &patientCount);
        else if (choice == 5)
            updateDoctor(doctors, doctorCount);
        else if (choice == 6)
            updatePatient(patients, patientCount);
        else if (choice == 7)
            removeDoctor(doctors, &doctorCount);
        else if (choice == 8)
            removePatient(patients, &patientCount);
        else if (choice == 9)
            searchDoctorByName(doctors, doctorCount);
        else if (choice == 10)
            searchDoctorBySpecialization(doctors, doctorCount);
        else if (choice == 11)
            searchPatientByName(patients, patientCount);
        else if (choice == 12)
            searchPatientByDisease(patients, patientCount);
        else if (choice == 13)
            doctorWithHighestExperience(doctors, doctorCount);
        else if (choice == 14)
            patientWithMaxDue(patients, patientCount);
        else if (choice == 15)
        {
            printf("Exiting the program...\n");
            printf("Thank you for using our system... <3\n");
            printf("Created By _Lapata_Pookies_\n");
            break;
        }
        else
            printf("Provide a proper choice. Proper choice: 1-15\n");
    }
    return 0;
}
void viewDoctors(struct Doctor doctors[], int doctorCount)
{
    if (doctorCount == 0)
    {
        printf("No Doctors Available.\n");
        return;
    }
    printf("Total Doctors: %d\n", doctorCount);
    for (int i = 0; i < doctorCount; i++)
    {
        printf(".....................................................\n");
        printf("Index          : %d\n", i + 1);
        printf("Name           : %s\n", doctors[i].name);
        printf("Specialization : %s\n", doctors[i].specialization);
        printf("Phone No       : %s\n", doctors[i].phoneNo);
        printf("Experience     : %d years\n", doctors[i].experienceYear);
        printf("Salary         : %.2f\n", doctors[i].salary);
    }
}
void viewPatients(struct Patient patients[], int patientCount)
{
    if (patientCount == 0)
    {
        printf("No Patients Available.\n");
        return;
    }
    printf("Total Patients: %d\n", patientCount);
    for (int i = 0; i < patientCount; i++)
    {
        printf(".....................................................\n");
        printf("Index       : %d\n", i + 1);
        printf("Name        : %s\n", patients[i].name);
        printf("Disease     : %s\n", patients[i].disease);
        printf("Phone       : %s\n", patients[i].phoneNo);
        printf("Age         : %d\n", patients[i].age);
        printf("Due Payment : %.2f\n", patients[i].duePayment);
    }
}
void addDoctor(struct Doctor doctors[], int *doctorCount)
{
    printf("Insert Doctor Name: ");
    scanf(" %[^\n]", doctors[*doctorCount].name);
    printf("insert Doctor Specialization: ");
    scanf(" %[^\n]", doctors[*doctorCount].specialization);
    printf("Insert Doctor Phone No: ");
    scanf(" %s", doctors[*doctorCount].phoneNo);
    printf("Insert Experience (years): ");
    scanf("%d", &doctors[*doctorCount].experienceYear);
    printf("Insert Doctor Salary: ");
    scanf("%f", &doctors[*doctorCount].salary);
    (*doctorCount)++;
    printf("New Doctor Added at index %d!\n", *doctorCount);
}
void addPatient(struct Patient patients[], int *patientCount)
{
    printf("Insert Patient Name: ");
    scanf(" %[^\n]", patients[*patientCount].name);
    printf("Insert Patient Disease: ");
    scanf(" %[^\n]", patients[*patientCount].disease);
    printf("Insert Patient Phone Number: ");
    scanf(" %s", patients[*patientCount].phoneNo);
    printf("Insert Patient Age: ");
    scanf("%d", &patients[*patientCount].age);
    printf("Insert Patient Due Payment: ");
    scanf("%f", &patients[*patientCount].duePayment);
    (*patientCount)++;
    printf("New Patient added at index %d\n", *patientCount);
}
void updateDoctor(struct Doctor doctors[], int doctorCount)
{
    int index;
    printf("Enter doctor index: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > doctorCount)
    {
        printf("Invalid index.\n");
        return;
    }
    index--;
    printf("Insert Doctor New Name: ");
    scanf(" %[^\n]", doctors[index].name);
    printf("Insert Doctor New Specialization: ");
    scanf(" %[^\n]", doctors[index].specialization);
    printf("Insert Doctor New Phone No: ");
    scanf(" %s", doctors[index].phoneNo);
    printf("Insert Doctor New Experience: ");
    scanf("%d", &doctors[index].experienceYear);
    printf("Insert Doctor New Salary: ");
    scanf("%f", &doctors[index].salary);
    printf("New Doctor Successfully updated at index %d\n", index + 1);
}
void updatePatient(struct Patient patients[], int patientCount)
{
    int index;
    printf("Insert patient index %d: ", patientCount);
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > patientCount)
    {
        printf("Invalid index.\n");
        return;
    }
    index--;
    printf("Insert Patient New Name: ");
    scanf(" %[^\n]", patients[index].name);
    printf("Insert PatientNew Disease: ");
    scanf(" %[^\n]", patients[index].disease);
    printf("Insert Patient New Phone Number: ");
    scanf(" %s", patients[index].phoneNo);
    printf("Insert Patient New Age: ");
    scanf("%d", &patients[index].age);
    printf("Insert Patient New Due Payment: ");
    scanf("%f", &patients[index].duePayment);
    printf("New Patient Successfully updated at index %d\n", index + 1);
}
void removeDoctor(struct Doctor doctors[], int *doctorCount)
{
    int index;
    printf("Insert doctor index: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > *doctorCount)
    {
        printf("Invalid index.\n");
        return;
    }
    index--;
    for (int i = index; i < *doctorCount - 1; i++)
        doctors[i] = doctors[i + 1];
    (*doctorCount)--;
    printf("Doctor successfully deleted from index %d\n", index + 1);
}
void removePatient(struct Patient patients[], int *patientCount)
{
    int index;
    printf("Insert patient index: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > *patientCount)
    {
        printf("Invalid index.\n");
        return;
    }
    index--;
    for (int i = index; i < *patientCount - 1; i++)
        patients[i] = patients[i + 1];
    (*patientCount)--;
    printf("Patient successfully deleted from index %d\n", index - 1);
}
void searchDoctorByName(struct Doctor doctors[], int doctorCount)
{
    char name[100];
    int found_index;
    printf("Insert Doctor Name to search: ");
    scanf(" %[^\n]", name);
    bool flag = false;
    for (int i = 0; i < doctorCount; i++)
    {
        if (strcmp(doctors[i].name, name) == 0)
        {
            flag = true;
            found_index = i;
        }
    }
    if (flag== true)
    {
        printf("Matched Doctor\n");
        printf(".............................................................\n");
        printf("Index       : %d\n", found_index + 1);
        printf("Name        : %s\n", doctors[found_index].name);
        printf("Disease     : %s\n", doctors[found_index].specialization);
        printf("Phone       : %s\n", doctors[found_index].phoneNo);
        printf("Experience  : %d\n", doctors[found_index].experienceYear);
        printf("Salary      : %.2f\n", doctors[found_index].salary);
    }
    else
        printf("Doctor not found.\n");
}
void searchDoctorBySpecialization(struct Doctor doctors[], int doctorCount)
{
    char spec[100];
    int found_index;
    printf("Enter Specialization: ");
    scanf(" %[^\n]", spec);
    bool flag = false;
    for (int i = 0; i < doctorCount; i++)
    {
        if (strcmp(doctors[i].specialization, spec) == 0)
        {
            flag = true;
            found_index = i;
        }
    }
    if (flag)
    {
        printf("Matched Doctors By Specialization\n");
        printf(".............................................................\n");
        printf("Index       : %d\n", found_index + 1);
        printf("Name        : %s\n", doctors[found_index].name);
        printf("Disease     : %s\n", doctors[found_index].specialization);
        printf("Phone       : %s\n", doctors[found_index].phoneNo);
        printf("Experience  : %d\n", doctors[found_index].experienceYear);
        printf("Salary      : %.2f\n", doctors[found_index].salary);
    }
    else
        printf("No doctor with that specialization found.\n");
}
void searchPatientByName(struct Patient patients[], int patientCount)
{
    char name[100];
    int found_index;
    bool flag = false;
    printf("Enter Patient Name to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(patients[i].name, name) == 0)
        {
            flag = true;
            found_index = i;
        }
    }
    if (flag)
    {
        printf("Matched Patients\n");
        printf(".............................................................\n");
        printf("Index       : %d\n", found_index + 1);
        printf("Name        : %s\n", patients[found_index].name);
        printf("Disease     : %s\n", patients[found_index].disease);
        printf("Phone       : %s\n", patients[found_index].phoneNo);
        printf("Age         : %d\n", patients[found_index].age);
        printf("Due Payment : %.2f\n", patients[found_index].duePayment);
    }
    else
        printf("Patient not found.\n");
}
void searchPatientByDisease(struct Patient patients[], int patientCount)
{
    char disease[100];
    int found_index;
    bool flag = false;
    printf("Enter Disease: ");
    scanf(" %[^\n]", disease);
    for (int i = 0; i < patientCount; i++)
    {
        if (strcmp(patients[i].disease, disease) == 0)
        {
            flag = true;
            found_index = i;
        }
    }
    if (flag)
    {
        printf("Matched Patients By Disease\n");
        printf(".............................................................\n");
        printf("Index       : %d\n", found_index + 1);
        printf("Name        : %s\n", patients[found_index].name);
        printf("Disease     : %s\n", patients[found_index].disease);
        printf("Phone       : %s\n", patients[found_index].phoneNo);
        printf("Age         : %d\n", patients[found_index].age);
        printf("Due Payment : %.2f\n", patients[found_index].duePayment);
    }
    else
        printf("No patient with that disease found.\n");
}
void doctorWithHighestExperience(struct Doctor doctors[], int doctorCount)
{
    if (doctorCount == 0)
    {
        printf("No doctors available.\n");
        return;
    }
    int maxIndex = 0;
    for (int i = 0; i < doctorCount; i++)
    {
        if (doctors[i].experienceYear > doctors[maxIndex].experienceYear)
            maxIndex = i;
    }
    printf("Doctor With Highest Experience\n");
    printf(".............................................................\n");
    printf("Index       : %d\n", maxIndex + 1);
    printf("Name        : %s\n", doctors[maxIndex].name);
    printf("Disease     : %s\n", doctors[maxIndex].specialization);
    printf("Phone       : %s\n", doctors[maxIndex].phoneNo);
    printf("Experience  : %d\n", doctors[maxIndex].experienceYear);
    printf("Salary      : %.2f\n", doctors[maxIndex].salary);
}
void patientWithMaxDue(struct Patient patients[], int patientCount)
{
    if (patientCount == 0)
    {
        printf("No patients available.\n");
        return;
    }
    int maxIndex = 0;
    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i].duePayment > patients[maxIndex].duePayment)
            maxIndex = i;
    }
    printf("Patient With Max Due\n");
    printf(".............................................................\n");
    printf("Index       : %d\n", maxIndex + 1);
    printf("Name        : %s\n", patients[maxIndex].name);
    printf("Disease     : %s\n", patients[maxIndex].disease);
    printf("Phone       : %s\n", patients[maxIndex].phoneNo);
    printf("Age         : %d\n", patients[maxIndex].age);
    printf("Due Payment : %.2f\n", patients[maxIndex].duePayment);
}
