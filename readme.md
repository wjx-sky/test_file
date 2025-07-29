## 学习c++的第六天
- 重新构建编译空间
```cmake
cmake_minimum_required(VERSION 3.8)
project(day_six_learning VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCE_FILES .src/main.cpp .src/example.cpp )
add_executable(main_exe ${SOURCE_FILES})
```
- 复合类型
1. 引用类型（变量的别名），不同变量名指向同一个变量
    - 举例：
    ```c++
    int main(){
        int a=10;
        int &b=a;//引用类型，a,b指向同一个内存空间
        int c=a;
        std::cout<<"a的地址："<<&a<<std::endl;
        std::cout<<"b的地址："<<&b<<std::endl;
        std::cout<<"c的地址"<<&c<<std::endl;

    }
    ```
    - 引用特性
    1. 必须初始化（创建必须指向某个已存在的对象）
    2. 一旦绑定，不可改变：初始化后，不可能再指向其它对象
    3. 没有空引用：引用必须指向某个对象。
    - 注意事项
    1. 引用主要实现对原始数据的直接访问，提高程序的效率和可读性；
    2. 引用可以是const类型的，可以通过引用直接访问数据但不可以修改数据；
    3. 引用通过指针实现，但比指针更安全直观；
    - 引用分类
        ```c++
        int a=10
        int & b = a;//左值引用，绑定对象是变量，为已经存在的对象创建别名，可以修改数据
        int && c = 10;//右值引用，绑定对象是常量，不可修改,为临时变量创建别名，主要用于接受函数返回值，减少开销

        ```
    **右值引用的主要用途：移动语义和完美转发**
2. 指针
    指针是一种复合类型，存储的是地址，可直接访问和操作内存中的数据
    ### 与引用的区别
    1. 指针本身就是一个对象，可以在指针的生命周期内指向多个对象
    2. 指针可以不初始化赋值，但会在定义时侯得到一个不确定的值
    举例：
    ```c++
    int var= 10,*ptr;//指针定义；

    int *ptr = 0xffff;//直接赋值内存地址
    int *ptr=&ar;//赋值变量地址，指针本身也有自己的地址，只不过指针的内容存储的是地址；
    int **ptr=&ptr;//指向指针的指针；
    ```
    - 指针值
    指针值（地址）应该属于以下4种状态之一：
    1. 指向一个对象
    2. 指向紧邻对象的下一个位置:end()之后；
    3. 空指针：不指向任何一个对象；
    4. 无效指针：访问无效指针后果严重，而编译器并不负责检查这类错误；//malloc 开辟，free 释放；new delete
    - 利用指针访问对象
    数据变量 = *指针（ *表示解引用操作，获取指针指向对象的数据），解引用只适合指向了某个对象的有效指针，空指针会使程序崩溃；
    例如：
    ```c++
    int * ptr = nullptr;
    std::cout<<*ptr<<std::endl;//程序会崩溃；
    ```
    *注意*
    ```c++
    int var = 30;
    int *ptr = &var;//指针指向var变量，存储的是var的地址
    int &r2=*ptr;//解引用操作符，取出所指向地址对应变量的内容，此时r2就是var的引用
    ```
    -  空指针
    ```c++
    //c++ 11的写法
    int *p = nullptr;
    //c98写法
    int *P = 0；
    //传统写法
    int *p = null;
    ```
## 学习c++的第七天
  - 指针类型(8字节或者4字节，默认8字节，存储的是地址)
    1. 相关指令
        - 空指针判断
        ```c++
        int * ptr = nullptr;
        if(!ptr){
            std::cout<<"这是一个空指针"<<std::endl;
        }
        ```
        - 指针是否相等
        ```c++
        int *ptr_normal,*ptr_empty;
        if(ptr_normal != ptr_empty){

        }
        ```
    2. 万能指针
        void *ptr, 可接收任何类型的对象；缺点是不能直接解引用；
        ```C++
        int var , * ptr = &var;
        void * ptr_al;
        ptr_val = &var;
        *((int *)ptr_al)//万能指针解引用方法；
        ```
    3. 指针的指针
        - 定义
        ```C++
        int var = 10,*ptr = &var;
        int **ptr_sec = &ptr;
        std::cout<<**ptr_sec<<std::endl;//双层解引用；
        ```
        - 指向指针的引用
        指针不能指向引用，但引用可以指向指针
        ```c++
        int * ptr_init = nullptr,init = 24;
        int *& rpinit = ptr_init;//对指针的引用，此时的引用也是指针类型；
        rpinit = &init//此时指针也指向init；
        *rpinit = 0；//解引用修改地址所对应数据，则init数据同样发生变化；
        ```
        *数组*
        ```c++
        int arr[5]={1,2,3,4,5};
        int * ptr =arr//数组名就是首地址
        ptr++;//是按元素进行递加，而不是地址递加，比如如果此时首地址为0x0000,则此时ptr=0x0004;
          ```
  - const限定符
    const关键字用于指示变量不可修改，防止无意修改变量的值；
    1. const对象作用范围只有当前文件，如果多个文件用到了同名的const对象，则等同于在不同文件内定义了不同变量
    ‵‵‵c++
    

















        

