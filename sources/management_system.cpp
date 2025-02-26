#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

void test01(){
    
    Worker * worker = NULL;
    
    worker = new Employee(1, "张三", 1);
    worker->showInfo();
    delete worker;
   
    worker = new Manager(2, "李四", 2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3, "王五", 3);
    worker->showInfo();
    delete worker;
}


int main(){
    test01();

    /*
    WorkerManager vm;
    vm.showMenu();
    int choice;
    
    while(true){
        cout << "请输入选择" << endl;
        cin >> choice;
        switch(choice){
            case 0:
                vm.exitSystem();
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }
    */
}