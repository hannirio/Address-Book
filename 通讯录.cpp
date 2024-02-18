//
//  main.cpp
//  通讯录管理系统
//
//  Created by 包涵 on 2021/10/28.
//

#include <iostream>
using namespace std;
void showMenu()
#include<string>
#define MAX 1000
{
    cout<<"*********************"<<endl;
    cout<<"*****1.添加联系人******"<<endl;
    cout<<"*****2.显示联系人******"<<endl;
    cout<<"*****3.删除联系人******"<<endl;
    cout<<"*****4.查找联系人******"<<endl;
    cout<<"*****5.修改联系人******"<<endl;
    cout<<"*****6.清空联系人******"<<endl;
    cout<<"*****0.退出通讯录******"<<endl;
    cout<<"*********************"<<endl;
}
struct Person
{
    string m_name;
    int m_sex;//性别：男1女2
    int m_age;//
    string phone;
    string addr;
};
struct Addressbook
{
    struct Person personArray[MAX];//联系人数组
    int m_size;//记录当前联系人个数
};
void addPerson(Addressbook *abs)
{
    if(abs->m_size>MAX)
    {
        cout<<"通讯录已满，无法添加"<<endl;
       
    }
    else
    {
        //添加具体联系人
        string name;
        cout<<"请输入一个姓名"<<endl;//姓名
        cin>>name;
        abs->personArray[abs->m_size].m_name=name;
        
        
    }
    //性别
    cout<<"请输入性别"<<endl;
    cout<<"1----男"<<endl;
    cout<<"2----女"<<endl;
    int sex=0;
    while (true) {
        cin>>sex;
        if(sex==1||sex==2)
        {
            abs->personArray[abs->m_size].m_sex=sex;
            break;
        }
        cout<<"请重新输入性别"<<endl;
         
    }
    //年龄
    cout<<"请输入年龄"<<endl;
    int age=0;
    cin>>age;
    abs->personArray[abs->m_size].m_age=age;
    //电话
    cout<<"请输入联系电话"<<endl;
    string phone;
    cin>>phone;
    abs->personArray[abs->m_size].phone=phone;
    //住址
    cout<<"请输入住址"<<endl;
    string address;
    cin>>address;
    abs->personArray[abs->m_size].addr=address;
    //更新通讯录
    abs->m_size++;
    cout<<"添加成功"<<endl;
    
}
void showPerson(Addressbook*abs)
{
    if(abs->m_size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_size;i++)
        {
            cout<<"姓名为:"<<abs->personArray[abs->m_size].m_name<<"\t";
            cout<<"性别为:"<<(abs->personArray[abs->m_size].m_sex==1?"男":"女")<<"\t";
            cout<<"年龄为:"<<abs->personArray[abs->m_size].m_age<<"\t";
            cout<<"电话为:"<<abs->personArray[abs->m_size].phone<<"\t";
            cout<<"住址为:"<<abs->personArray[abs->m_size].addr<<endl;
        }
    }
    system("clear");
   
}
int isExist(Addressbook*abs,string name)
{
    for(int i=0;i<abs->m_size;i++)
    {
        if(abs->personArray[i].m_name==name)
        {
            return i;
        }
        
    }return -1;
}

int main()
{
    Addressbook abs;
    abs.m_size=0;
    showMenu();
    int select=0;
    cin>>select;
    do{
    switch (select) {
        //添加一个人
        case 1:
            addPerson(&abs);//利用地址传递可以修饰行参
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3://删除联系人
//        { cout<<"请输入联系人姓名"<<endl;
//            string name;
//            cin>>name;
//            int ret=isExist(&abs, name);
//            if(ret!=-1)
//            {
//                for(int i=ret;i<abs.m_size;i++)
//                {
//                    abs.personArray[i]=abs.personArray[i+1];
//                }
//                abs.m_size--;
//                cout<<"删除成功"<<endl;
//            }}
//           if( isExist(&abs, name)==-1)
//           {
//               cout<<"查无此人"<<endl;
//           }
//            else
//            {
//                cout<<"找到此人"<<endl;
//            }
//        }
            
        case 0:
            cout<<"欢迎下次使用"<<endl;
            break;
        default:
        break;
            }
    if(select!=0)
    {
        cin>>select;
    }
    }while(select!=0);}
