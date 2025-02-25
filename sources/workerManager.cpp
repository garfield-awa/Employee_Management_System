#include "workerManager.h"

WorkerManager::WorkerManager(/* args */)
{
}



 void WorkerManager::showMenu(){
    cout << "****************************" << endl;
    cout << "*          欢迎使用职工管理系统！         *" << endl;
    cout << "****************************" << endl;
    cout << "* 0.退出管理程序                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 1.增加职工信息                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 2.显示职工信息                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 3.删除离职职工                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 4.修改职工信息                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 5.查找职工信息                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 6.按照编号排序                   *" << endl;
    cout << "****************************" << endl;
    cout << "* 7.清空所有文档                   *" << endl;
    cout << "****************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem(){
    cout << "感谢您的使用!" << endl;
    pause();
    exit(0);
}

void WorkerManager::pause(){
    cout << "请按任意键继续" << endl;
    getchar();
    getchar();
}

WorkerManager::~WorkerManager()
{
}