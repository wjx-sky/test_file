#include<iostream>
#include "example.h"
#include <string>
int var_3[3] = {1,2,3};
typedef char * pstring;

struct student{
    public:
    int id;
    std::string name;
    double score;
    student(int id , std::string name , double score):id(id),name(name){
        score = score;//构造函数
    }
};

struct address{
    int door_num;
    std::string adr;
 };

 struct Student{
    int id;
    std::string name;
    address persion;
 };//嵌套结构体
int main(){


    int var=10;
    int * ptr=&var;//ptr指向var
    int * * ptr_adress = &ptr;//指针的指针
    void *ptr_al;//万能指针
    ptr_al = &var;
    std::cout<<"万能指针解引用"<<*((int *)ptr_al)<<std::endl;

    std::cout<<"var的地址"<<&var<<std::endl;
    std::cout<<"ptr储存的数据"<<ptr<<std::endl;
    std::cout<<"ptr的地址"<<&ptr<<std::endl;
    std::cout<<"ptr_address储存的数据"<<ptr_adress<<std::endl;
    std::cout<<"ptr_add的地址:"<<&ptr_adress<<std::endl;
    //访问对象
    *ptr=43;//赋值以及修改i数据内容
    std::cout<<*ptr<<std::endl;//由*得到指针指向对象var的值

    c_printfer();
    std::cout<<"main函数中的buffer_1的地址"<<&buffer_1
            <<"\n main函数中buffer_2的地址:"<<&buffer_2<<std::endl;
    constexpr int *ptr_2=var_3;//常量指针，且表达式必须为常量表达式，即表达式必须在编译期就能得到结果
    *ptr_2 = 10;
    
    const pstring pstring_1 =nullptr;//cosnt修饰pstring ,所定义的pstring_1是常量指针，等价于char* const pstring_1;
    //*pstring_1 = '2';报错，空指针修改内容会崩溃
    const int ci =10,&r = ci;//顶层const会被推导忽略,而底层const不会被忽略；
    const int *p = &ci;//p是指向常量的指针
    auto f = *p;//f是从const int *类型对象,
    auto g1 = &ci;//由于ci是常量，故为底层const,故g是指向常量的指针，
    const auto g2 = *p;//g是const int类型对象
    auto & ce = ci;//const引用类型，数据类型由底层决定，而不是顶层；
    //auto & m = c,*pt = &ci;auto推导后面的几种数据类型必须是相同的，否则是错误的；
    decltype(p) q = nullptr;
    decltype(r) rea = ci;
    decltype(*p) var2 = ci;//const int &引用类型；
    decltype((ci)) var_2 =ci;//多加一个括号变成引用类型；

    
    //student student_1,student_2;//结构体定义
    //student_1.id =1003;
    student student_1(1030,"limei",283);
    
 Student student_3;
 student_3.persion.door_num = 100;//

    return 0;
    
}