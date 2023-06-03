/*Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular employee. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details. Use sequential file to main the data. */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    int roll_no;
    string name;
    string division;
    string address;
};

const string file_path = "students.txt";

void add_student()
{
    Student student;
    ofstream outfile;
    outfile.open(file_path, ios::app);
    cout << "Enter roll number: ";
    cin >> student.roll_no;
    cout << "Enter name: ";
    cin >> student.name;
    cout << "Enter division: ";
    cin >> student.division;
    cout << "Enter address: ";
    cin >> student.address;
    outfile << student.roll_no << " " << student.name << " " << student.division << " " << student.address << endl;
    outfile.close();
}

void delete_student()
{
    int roll_no;
    bool found = false;
    ifstream infile;
    ofstream outfile;
    infile.open(file_path);
    outfile.open("temp.txt", ios::app);
    cout << "Enter roll number to delete: ";
    cin >> roll_no;
    Student student;
    while (infile >> student.roll_no >> student.name >> student.division >> student.address)
    {
        if (student.roll_no != roll_no)
        {
            outfile << student.roll_no << " " << student.name << " " << student.division << " " << student.address << endl;
        }
        else
        {
            found = true;
        }
    }
    infile.close();
    outfile.close();
    remove(file_path.c_str());
    rename("temp.txt", file_path.c_str());
    if (found)
    {
        cout << "Student record deleted." << endl;
    }
    else
    {
        cout << "Student record not found." << endl;
    }
}

void display_student()
{
    int roll_no;
    bool found = false;
    ifstream infile;
    infile.open(file_path);
    cout << "Enter roll number to display: ";
    cin >> roll_no;
    Student student;
    while (infile >> student.roll_no >> student.name >> student.division >> student.address)
    {
        if (student.roll_no == roll_no)
        {
            cout << "Roll number: " << student.roll_no << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }
    infile.close();
    if (!found)
    {
        cout << "Student record not found." << endl;
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            display_student();
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
