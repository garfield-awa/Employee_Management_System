#include "manager.h"

Manager::Manager(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showInfo(){
    cout << "职工编号" << this->m_Id
    << "职工姓名" << this->m_Name
    << "岗位" << getDeptName()
    << "岗位职责：向员工提交任务" << endl;
}

string Manager::getDeptName(){
    return string("经理");
}