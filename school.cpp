#include <iostream>
using namespace std;

class student{
public:
string name;
int age;

void student_adder(string n, int a ){
    name=n;
    age=a;
}


};
class school{

public:

school(){
    int count=0;
}

student students[3];

void active(string cname, int cage ){
    for (int i=0; i<3;i++){
    students[i].student_adder(cname,cage);
}
}

void printer(int i){
   
cout<<students[i].name;
cout<<students[i].age;

}
//}
};


int main(){
    string cname[3];
    int cage[3];
     for (int i=0; i<3;i++){
  cin>>cname[i]>>cage[i];
     }
     
school c1;

 for (int i=0; i<3;i++){
c1.active(cname[i],cage[i]);
 }
 cout<<"enter student 0,1 or 2 you want info of";
 int choice;
 cin>>choice;
c1.printer(choice);

school c2;

school c3;




    
}