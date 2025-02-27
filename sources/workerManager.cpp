#include "workerManager.h"

WorkerManager::WorkerManager()
{
    //判断文件是否存在或是否为空
    if(check_FileIsNone()) return;
    if(check_FileIsEmpty()) return;

    //统计人数
    int num = this->get_EmpNum();
    cout << "职工的人数为：" << num << endl;
    this->m_EmpNum = num;
    this->m_FileIsEmpty = false;

    //根据人数读取文件信息
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    this->init_Emp();
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

bool WorkerManager::check_FileIsNone(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在"<< endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return true;
    }
    ifs.close();
    return false;
}

bool WorkerManager::check_FileIsEmpty(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return true;
    }
    ifs.close();
    return false;
}

int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId){
        num++;
    }
    ifs.close();
    return num; 
}

void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    Worker *worker;
    while(ifs >> id && ifs >> name && ifs >> dId){
        switch(dId){
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;  
            case 3:
                worker = new Boss(id, name, 3);
                break;
        }
        this->m_EmpArray[index++] = worker;
    }
    ifs.close();
}

void WorkerManager::add_Emp(){
    cout << "输入添加人数数量" << endl;
    int addNum = 0;
    cin >> addNum;
    cout << addNum << endl;
    if(addNum > 0){
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker*[newSize];
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for(int i = 0; i < addNum; i++){
            int id;
            string Name;
            int dSelect;
            cout << "请输入第" << i+1 << "个职工编号:";
            cin >> id;
            cout << "请输入第" << i+1 << "个职工姓名:";
            cin >> Name;
            cout << "请输入第" << i+1 << "个职工岗位（1、职工 2、经理 3、老板）:";
            cin >> dSelect;
            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(id, Name, 1);
                    break;
                case 2:
                    worker = new Manager(id, Name, 2);
                    break;
                case 3:
                    worker = new Boss(id, Name, 3);
                    break;
                default:
                       break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;

        this->m_EmpArray = newSpace;

        this->m_EmpNum = newSize;

        this->m_FileIsEmpty = false;

        this->save();

        cout << "成功添加" << addNum << "人" << endl;

    }else{
        cout << "输入错误,退出" << endl;
    }
    this->pause();
    this->clear();
}

void WorkerManager::show_Emp(){
    this->clear();
    if(this->m_FileIsEmpty){
        cout << "暂无员工信息" << endl;
    }else{

        cout << "员工信息显示" << endl;
        for(int i = 0; i < this->m_EmpNum; i++){
            cout << "员工号："<< this->m_EmpArray[i]->m_Id
            << "员工姓名：" << this->m_EmpArray[i]->m_Name
            << "员工类别：" << this->m_EmpArray[i]->getDeptName() << endl;
        }
    }
    this->pause();
}

void WorkerManager::del_Emp(){
    cout << "输入要删除的员工号：" << endl;
    int id;
    cin >> id;
    int index = IsExist(id);
    if(index == -1){
        cout << "该员工不存在" << endl;
    }else{
        for(int i = index; i < this->m_EmpNum-1; i++)
            this->m_EmpArray[i] = this->m_EmpArray[i+1];
        this->m_EmpNum--;
        this->save();
        cout << "删除成功" << endl;
    }
    this->pause();
    this->clear();
}

void WorkerManager::mod_Emp(){
    cout << "输入要修改的员工号：";
    int id;
    string name;
    int dId;
    cin >> id;
    int index = IsExist(id);
    if(index == -1){
        cout << "该员工不存在" << endl;
    }else{
        cout << "请输入新的员工号：";
        cin >> id; 
        cout << "请输入新的员工名：";
        cin >> name;
        cout << "请输入新的类别：";
        cin >> dId;
        if(dId == this->m_EmpArray[index]->m_DeptId){
            this->m_EmpArray[index]->m_Id = id;
            this->m_EmpArray[index]->m_Name = name; 
        }else{
            delete this->m_EmpArray[index];
            Worker *worker = NULL;
            switch(dId){
                case 1:
                    worker = new Employee(id, name, dId);
                    break;
                case 2:
                    worker = new Manager(id, name, dId);
                    break;
                case 3:
                    worker = new Boss(id, name, dId);
                    break;
                default:
                    break;
            }
            this->m_EmpArray[index] = worker;
            this->save();
            cout << "修改成功" << endl;
        }
    }
    this->pause();
    this->clear();
}

int WorkerManager::IsExist(int id){
    for(int i = 0; i < this->m_EmpNum; i++){
        if(id == this->m_EmpArray[i]->m_Id)
            return i;
    }
    return -1;
}

void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for(int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}


void WorkerManager::read(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在"<< endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }else{

    }
}


void WorkerManager::pause(){
    cout << "请按任意键继续" << endl;
    cin.get();
    cin.get();
}

void WorkerManager::clear(){
    system("clear");
}

WorkerManager::~WorkerManager(){
    if(this->m_EmpArray != NULL){
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
    }
}