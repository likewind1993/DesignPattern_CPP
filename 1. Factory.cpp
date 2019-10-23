#include <iostream>
using namespace std;

class Person {
public:
    virtual void say() {} ;
};
class Teacher : public Person{
public:
    void say(){
        cout<<"teacher!"<<endl;
    }
};
class Student : public Person{
public:
    void say(){
        cout<<"student!"<<endl;
    }
};

class SchoolFactory{
public:
    Person * getPerson(string type){
   
        if(type == "student"){
            return new Student();
        }else if(type == "teacher"){
            return new Teacher();
        }else {
            return NULL;
        }
    }
};


int main() {
    SchoolFactory factory;

    Person * p = factory.getPerson("student");
    p->say();
    p = factory.getPerson("teacher");
    p->say();
    return 0;
}