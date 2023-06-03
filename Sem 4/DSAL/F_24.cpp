#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

class EMP_CLASS
{
 typedef struct EMPLOYEE
 {
 char name[10];
 int emp_id;
 int salary;
 }Rec;

 typedef struct INDEX
 {
 int emp_id;
 int position;
 }Ind_Rec;

 Rec Records;
 Ind_Rec Ind_Records;

 public:
  EMP_CLASS();
  void Create();
  void Display();
  void Delete();
  void Append();
};

EMP_CLASS::EMP_CLASS()//constructor 
  {
   strcpy(Records.name,"");
  }

void EMP_CLASS::Create()
{
 int i,j;
 char ch='y';
 fstream seqfile;
 fstream indexfile;
 i=0;
 indexfile.open("IND.DAT",ios::out);
 seqfile.open("EMP.DAT",ios::out);
 do
 {
  cout<<"\n Enter Name: ";
  cin>>Records.name;
  cout<<"\n Enter Emp_ID: ";
  cin>>Records.emp_id;
  cout<<"\n Enter Salary: ";
  cin>>Records.salary;
  seqfile.write((char*)&Records,sizeof(Records));
  Ind_Records.emp_id=Records.emp_id;
  Ind_Records.position=i;
  indexfile.write((char*)&Ind_Records,sizeof(Ind_Records));
  i++;
  cout<<"\nDo you want to add more records?";
  cin>>ch;
  }while(ch=='y');
  seqfile.close();
  indexfile.close();
}
void EMP_CLASS::Display()
{
 fstream seqfile;
 fstream indexfile;
 int n,i,j;
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
 indexfile.seekg(0,ios::beg);
 seqfile.seekg(0,ios::beg);
 cout<<"\n The Contents of file are ..."<<endl;
 i=0;
 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
 {

   i=Ind_Records.position*sizeof(Rec);//getting pos from index file
   seqfile.seekg(i,ios::beg);//seeking record of that pos from seq.file

   seqfile.read((char *)&Records,sizeof(Records));//reading record

   if(Records.emp_id!=-1)//if rec. is not deleted logically
   {   //then display it
   cout<<"\nName: "<<Records.name<<flush;
   cout<<"\nEmp_ID: "<<Records.emp_id;
   cout<<"\nSalary: "<<Records.salary;
   cout<<"\n";
    }

 }
 seqfile.close();
 indexfile.close();
}
void EMP_CLASS::Delete()
{
 int id,pos;
 cout<<"\n For deletion,";
 cout<<"\n Enter the Emp_ID for for searching ";
 cin>>id;
 fstream seqfile;
 fstream indexfile;
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
 seqfile.seekg(0,ios::beg);
 indexfile.seekg(0,ios::beg);
 pos=-1;
 //reading index file for getting the index
 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
 {
  if(id==Ind_Records.emp_id) //desired record is found
  {
   pos=Ind_Records.position;
   Ind_Records.emp_id=-1;
   break;
  }
 }
 if(pos==-1)
 {
  cout<<"\n The record is not present in the file";
  return;
 }
//calculating the position of record in seq. file using the pos of ind. file
 int offset=pos*sizeof(Rec);
 seqfile.seekp(offset);//seeking the desired record for deletion
 strcpy(Records.name,"");
 Records.emp_id=-1; //logical deletion
 Records.salary=-1; //logical deletion
 seqfile.write((char*)&Records,sizeof(Records))<<flush;//writing deleted status 
    //From index file also the desired record gets deleted as follows

 offset=pos*sizeof(Ind_Rec);//getting position in index file
 indexfile.seekp(offset); //seeking that record
 Ind_Records.emp_id=-1; //logical deletion of emp_id
 Ind_Records.position=pos;//position remain unchanged
 indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
 seqfile.seekg(0);
 indexfile.close();
 seqfile.close();
 cout<<"\n The record is Deleted!!!";
}
void EMP_CLASS::Append()
{
 fstream seqfile;
 fstream indexfile;
 int pos;
 indexfile.open("IND.DAT",ios::in|ios::binary);
 indexfile.seekg(0,ios::end);
 pos=indexfile.tellg()/sizeof(Ind_Records);
 indexfile.close();

 indexfile.open("IND.DAT",ios::app|ios::binary);
 seqfile.open("EMP.DAT",ios::app|ios::binary);

 cout<<"\n Enter the record for appending";
 cout<<"\nName: ";cin>>Records.name;
 cout<<"\nEmp_ID: ";cin>>Records.emp_id;
 cout<<"\nSalary: ";cin>>Records.salary;
 seqfile.write((char*)&Records,sizeof(Records));//inserting rec at end in seq. file
 Ind_Records.emp_id=Records.emp_id;           //inserting rec at end in ind. file

 Ind_Records.position=pos;                          //at calculated pos
 indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
 seqfile.close();
 indexfile.close();
 cout<<"\n The record is Appended!!!";
}

int main()
{
 EMP_CLASS List;
 char ans;
 int choice;
 do
 {
  cout<<"\n***********Main Menu************"<<endl;
  cout<<"\n 1.Create";
  cout<<"\n 2.Display";
  cout<<"\n 3.Delete";
  cout<<"\n 4.Append";
  cout<<"\n 5.Exit";
  cout<<"\n Enter your choice: ";
  cin>>choice;
  switch(choice)
    {
  case 1:List.Create();
      break;
  case 2:List.Display();
      break;
  case 3:List.Delete();
      break;
  case 4:List.Append();
      break;
    }
 cout<<"\n\t Do you want to go back to Main Menu?";
 cin>>ans;

 }while(ans=='y');

}
