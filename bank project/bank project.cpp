#include <iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class bank {
  private:
   int accno;
   char name[20];
   int balance;
   char type;
  public:
  bank(){
    accno=0;
    strcpy(name,"NULL");
    balance=00;
  }

   int create (){
   cout<<"enter your account number ";
   cin>>accno;
   cout<<"enter your name ";
   cin>>name;
   cout<<"enter your opening amount ";
   cin>>balance;
   cout<<"enter your account type (C/S)";
   cin>>type;
   cout<<"\n your account has been created sucessfully ";
   return 0;}

   void show (){
   cout<<"\n\nyour account number "<<accno;
   cout<<"\naccount holders name ";
   puts(name);
   cout<<"your account balance "<<balance;
   cout<<"\naccount type-"<<type;
   }
  void deposit(int,int);
  void save();
  void showall();
  void dlt(int);
  void withdraw(int,int);
};
void bank::save(){
ofstream fout;
fout.open("file1.dat",ios::app|ios::binary);
fout.write((char*)this,sizeof(*this));
fout.close();
}
void bank::showall(){
  ifstream fin;
  fin.open("file1.dat",ios::in|ios::binary);
  if(!fin){cout<<"file not found ";}
  else{
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof()){
    show();
    fin.read((char*)this,sizeof(*this));
  }
  }
fin.close();
}
void bank::dlt(int x){
   ofstream fout;
    fout.open("temp.dat",ios::out|ios::binary);
  ifstream fin;
  fin.open("file1.dat",ios::binary);
  if(!fin)cout<<"file not found";
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof()){
    if(accno!=x)
       {
         fout.write((char *)this,sizeof(*this));
       }
    fin.read((char*)this,sizeof(*this));
  }
  fout.close();
  fin.close();
  remove("file1.dat");
  rename("temp.dat","file1.dat");

}
void bank::deposit(int x,int y){
  int count=0;
fstream file;
file.open("file1.dat",ios::ate|ios::binary|ios::in|ios::out);
file.seekg(0);
if(!file) cout<<"file not found";
file.read((char*)this,sizeof(*this));
while(!file.eof()){
 if(accno=x){ balance=balance+y;
int pos=(-1)*static_cast<int>(sizeof(bank));
			file.seekp(pos,ios::cur);
 file.write((char*)this,sizeof(*this));
 count++;}file.read((char*)this,sizeof(*this));
 }file.close();
 if(count==0){cout<<"account not found";
 return;}cout<<"amount deposited successfully";
}


void bank::withdraw(int x,int y){
  int count=0;
fstream file;
file.open("file1.dat",ios::ate|ios::binary|ios::in|ios::out);
file.seekg(0);
if(!file) cout<<"file not found";
file.read((char*)this,sizeof(*this));
while(!file.eof()){
 if(accno=x){
   if(y>balance){cout<<"balance insufficient";
   return;}
    balance=balance-y;
int pos=(-1)*static_cast<int>(sizeof(bank));
			file.seekp(pos,ios::cur);
 file.write((char*)this,sizeof(*this));

 count++;}file.read((char*)this,sizeof(*this));
 }file.close();
 if(count==0){cout<<"account not found";
return;}
cout<<"amount withdrawn successfully";
}



int main() {
class bank b1;

int x,y;
while(1){
system ("CLS");
  cout <<"\n\n\n\n----Welcome to our bank----"<<"\n\n 1. Create new account \n 2. Diposit money \n 3. withdraw money \n 4. get all account overview\n 5. delete a record \n 6. Exit \n\n\n enter your choice  ";
  cin>>x;

 switch(x){
 case 1 : b1.create();
 b1.save();cout<<"\n\n press any key to continue";getch();
 break;
 case 2 : cout<<"enter your account and amount to be deposited";
 int p,q;
 cin>>p>>q;
 b1.deposit(p,q);cout<<"\n\n press any key to continue";getch();
 break;
 case 3 : cout<<"enter your account no and amount to be withdrawn";
 cin>>p>>q;
 b1.withdraw(p,q);cout<<"\n \n press any key to continue";getch();
 break;
 case 4 : b1.showall();cout<<"\n\n press any key to continue";getch();
 break;
 case 5 : cout<<"enter a record to be deleted";
 cin>>y; b1.dlt(y);cout<<"\n\n press any key to continue";getch();
 break;
 case 6 :cout<<"thank your for using our program \n\n press any key to exit ";
         getch();
     exit(1);
default :cout<<"invalid entry press any key to return";
getch();
break;}

}
return 0;}
