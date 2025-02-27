#pragma once
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
    
        /* data */
    public:
        WorkerManager();
        /*展示菜单*/
        void showMenu();
        void exitSystem();

        //文件预处理
        bool check_FileIsNone();
        bool check_FileIsEmpty();
        int get_EmpNum();
        void init_Emp();

        //基本增删改查
        void add_Emp();
        void show_Emp();
        void del_Emp();
        void mod_Emp();
        void find_Emp();
        int IsExist(int id);

        //基本文件操作
        void save();
        void read();
        void clean();

        //其他操作
        void pause();
        void clear();
        ~WorkerManager();

    private:
        int m_EmpNum;
        Worker **m_EmpArray;
        bool m_FileIsEmpty;
        
};


