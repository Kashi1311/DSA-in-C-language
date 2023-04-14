// Basic OOPS example //
#include<iostream>
using namespace std;

class student{
    public:
    string name;
    int age;
    bool gender;
    
    student(){
        cout<<"Default Constructor"<<endl;    // it is a default constructor. // 
    }

    student(string s, int a, bool  g){
        cout<<"Parameterised Constructor"<<endl;
        name = s;
        age = a;
        gender = g;                                   
    } // parameterised constructor //

    student(student &a){
        cout<<"Copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~student(){
        cout<<"Deconstructor";
    }

    void printinfo(){

    }
};

int main(){
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     cout<<"Name : ";
    //     cin>>arr[i].name;
    //     cout<<"Age : ";
    //     cin>>arr[i].age;
    //     cout<<"Gender : ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printinfo();
    // }
    student a("Urvi", 20, 1);
    student b;
    student c = a;
    return 0;

}