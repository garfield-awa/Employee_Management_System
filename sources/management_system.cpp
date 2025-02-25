#include <iostream>
#include "workerManager.h"
using namespace std;

int main(){
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
}