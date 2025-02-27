#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;


int main(){

    WorkerManager vm;
    //vm.showMenu();
    int choice;
    int test;
    while(true){
        vm.clear();
        vm.showMenu();
        cout << "请输入选择" << endl;
        cin >> choice;
        switch(choice){
            case 0:
                vm.exitSystem();
            case 1:
                vm.add_Emp();
                break;
            case 2:
                vm.show_Emp();
                break;
            case 3:
                vm.del_Emp();
                break;
            case 4:
                vm.mod_Emp();
                break;
            case 5:
                vm.find_Emp();
                break;
            case 6:
                vm.clean();
                break;
        }
    }
}