#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

class Observer {
public:
    void virtual update() {};
};

class Student : public Observer {
private:
    std::string name;
public:
    Student(string na)
    {
        name = na;
    }

    void update() override
    {
        cout << name << " Got it !" << endl;
    }
};

class Subject {
protected:
    list<Observer *> observers;
public:
    void virtual attach(Observer * observer)
    {
        observers.push_back(observer);
    }
    void virtual detach(Observer * observer)
    {
        observers.push_back(observer);
    };
    void virtual notify()
    {
        for(auto iter : observers) {
            iter->update();
        }
    };
};


class Teacher : public Subject {
private:
    string name;
public:
    Teacher(string na)
    {
        name = na;
    }
    void notify() override
    {
        for(auto iter : observers) {
            iter->update();
        }
    }
};

int main()
{
    Student zhangsan("zhangsan");
    Student lisi("lisi");

    Teacher teacher("T");
    teacher.attach(&zhangsan);
    teacher.attach(&lisi);

    teacher.notify();

    return 0;
}