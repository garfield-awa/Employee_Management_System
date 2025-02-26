#include "boss.h"

Boss::Boss(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo(){
    cout << "职工编号" << this->m_Id
    << "职工姓名" << this->m_Name
    << "岗位" << getDeptName()
    << "岗位职责：根据经理建议实施重大决策" << endl;
}

string Boss::getDeptName(){
    return string("老板");
}