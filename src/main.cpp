#include<iostream>
#include "example.h"
int var_3 = 10;
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
    constexpr int *ptr_2=&var_3;

    return 0;
    
}