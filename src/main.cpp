#include<iostream>

int main(){


    int var=10;
    int * ptr=&var;//ptr指向var
    int * * ptr_adress = &ptr;//指针的指针
    std::cout<<"var的地址"<<&var<<std::endl;
    std::cout<<"ptr储存的数据"<<ptr<<std::endl;
    std::cout<<"ptr的地址"<<&ptr<<std::endl;
    std::cout<<"ptr_address储存的数据"<<ptr_adress<<std::endl;
    std::cout<<"ptr_add的地址："<<&ptr_adress<<std::endl;
    //访问对象
    *ptr=43;//赋值以及修改i数据内容
    std::cout<<*ptr<<std::endl;//由*得到指针指向对象var的值

    return 0;
    
}