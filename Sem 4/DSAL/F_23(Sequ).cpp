/*Department maintains a student information. 
The file contains roll number, name, division and address.
Allow user to add, delete information of student.
Display information of particular employee.
If record of student does not exist an appropriate message is displayed. 
If it is, then the system displays the student details. Use sequential file to main the data. */
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class studentclass
{
    typedef struct student
    {
        char name[10];
        int roll_no;
        char div;
        char address[50];
    }rec;
    rec records;
    public:
        void create();
        void display();
        void delet();
        int search();
        void append();
};
void studentclass::create()
{
    ofstream seqfile;
    seqfile.open("student.dat",ios::out|ios::binary);
        
        cout<<"Enter student information"<<endl;
        cout<<"Name:"<<endl;
        cin>>records.name;
        cout<<"Roll no.:"<<endl;
        cin>>records.roll_no;
        cout<<"Division:"<<endl;
        cin>>records.div;
        cout<<"Address:"<<endl;
        cin>>records.address;
        seqfile.write((char *)&records,sizeof(records))<<flush;
    seqfile.close();
}
void studentclass::display()
{
    ifstream seqfile;
    seqfile.open("student.dat",ios::in|ios::binary);
    seqfile.seekg(0,ios::beg);
    cout<<"contents are"<<endl;
    cout<<"\n\tName\tRoll_No.\tDiv\tAddress"<<endl;
    while(seqfile.read((char *)&records,sizeof(records)))
    {
        if(records.roll_no!=-1)
        {
            cout<<"\t"<<records.name<<"\t"<<records.roll_no<<"\t\t"<<records.div<<"\t"<<records.address<<endl;
        }
    }
    seqfile.close();
}

void studentclass::delet()
{
    cout<<"\n for deletion"<<endl;
    int pos;
    pos=search();
    fstream seqfile;
    seqfile.open("student.dat",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    if(pos==-1)
    {
        cout<<"Data not found"<<endl;
        return;
    }
    int offset=pos*sizeof(rec);
    seqfile.seekp(offset);
    strcpy(records.name,"NULL");
    records.roll_no=-1;
    records.div=-1;
    strcpy(records.address,"NULL");
    seqfile.write((char *)&records,sizeof(records));
    seqfile.seekg(0);
    seqfile.close();
    cout<<"\n deletion is done"<<endl;
}

int studentclass::search()
{
    fstream seqfile;
    int id, pos;
    cout<<"\n Enter the roll no. that you want to search"<<endl;
    cin>>id;
    seqfile.open("student.dat",ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    pos=-1;
    int i=0;
    while(seqfile.read((char*)&records,sizeof(records)))
    {
        if(id==records.roll_no)
        {
            pos=i;
            cout<<"\n Data is found"<<endl;
            break;
        }
        else{
            cout<<"data is not found";
        }
        i++;
    }
    return pos;
}
void studentclass :: append()
{
    fstream s;
    s.open("student.dat",ios::out|ios::in|ios::binary);
    s.seekg(0,ios::beg);
    int i=0;
    while(s.read((char*)&records,sizeof(records)))
    {
        i++;
    }
    s.clear();
    cout<<"Name:"<<endl;
    cin>>records.name;
    cout<<"Roll no.:"<<endl;
    cin>>records.roll_no;
    cout<<"Division:"<<endl;
    cin>>records.div;
    cout<<"Address:"<<endl;
    cin>>records.address;
    s.write((char *)&records,sizeof(records));
    s.seekg(0);
    s.close();

}


int main()
{
    studentclass sc;
    int ch;
    do{
    cout<<"enter your choice \n1.Add\n2.delete\n3.search\n4.append"<<endl;
    cin>>ch;
    switch(ch){

    case 1:
    sc.create();
    sc.display();
    break;
    case 2:
    sc.delet();
    sc.display();
    break;
    case 3:
    sc.search();
    break;
    case 4:
    sc.append();
    sc.display();
    break;
    }

    }while(ch<=4);
    return 0;
}
