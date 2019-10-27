#include <iostream>
#include <string>
using namespace std;

class Saler{
public:
    void sell_book (){
        cout<<"sell book!"<<endl;
    }
    void sell_fruit () {
        cout<<"sell fruit!"<<endl;
    }
};

class Command{
protected:
    Saler * saler;
public:
    virtual void execute(){};
};

class OrderBookCommand : public Command{
public:
    OrderBookCommand(Saler * s) {
        saler = s;
    };
    void execute() override {
        saler->sell_book();
    }
};
class OrderFruitCommand : public Command{
public:
    OrderFruitCommand(Saler * s) {
        saler = s;
    };
    void execute() override {
        saler->sell_fruit();
    }
};

class Waiter {
private:
    Command * command;
public:
    void setCommand(Command * cmd){
        command = cmd;
    }
    void notify(){
        command->execute();
    }
};



int main() {
    Waiter * waiter = new Waiter();
    Saler * saler = new Saler();
    OrderBookCommand * book_cmd = new OrderBookCommand(saler);
    OrderFruitCommand * fruit_cmd = new OrderFruitCommand(saler);

    waiter->setCommand(book_cmd);
    waiter->notify();

    waiter->setCommand(fruit_cmd);
    waiter->notify();

    return 0;
}

