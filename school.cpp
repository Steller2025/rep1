#include <iostream>
using namespace std;
//comeend 50
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

void active(int index,string cname, int cage ){
    
    students[index].student_adder(cname,cage);
}


void printer(int i){
   
cout<<students[i].name;
cout<<students[i].age;

}
//}
};


int main(){
   
school schools[3];
for (int j=0; j<3;j++){

     string cname[3];
    int cage[3];
     for (int i=0; i<3;i++){
  cin>>cname[i]>>cage[i];
     }
     
 for (int i=0; i<3;i++){
schools[j].active(i,cname[i],cage[i]);
 }
}
int schoice;
 cout<<"enter school 0,1 or 2 you want info of";
 cin>>schoice;
 
 int stchoice; 
 cout<<"enter student 0,1 or 2 you want info of"<<endl;
 cin>>stchoice;

schools[schoice].printer(stchoice);


    
}