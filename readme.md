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
      const关键字用于指示变量不可修改，防止无意修改变量的值  
        1. const对象作用范围默认只有当前文件，如果多个文件用到了同名的const对象，则等同于在不同文件内定义了不同变量
            想要避免的方法就是利用extern 关键字在头文件做声明，初始化在相应的源文件中  
        2. const类型的引用
            const int &i1 = i;//const类型对象在编译器中被认为是可读的，故不可修改   
            ```C++
            int i = 100；
            const int & r2 = i;//此时r2不可修改，但i可以修改，此处只是不想要i的值通过r2被修改。引用必须类型匹配

            double dval = 10;
            int & r3 = dval;//编译器会报错，类型不匹配；

            const int & r4 = dval;//编译通过，该绑定方式编译器会默认进行类型转换，等价于

            const int temp = dval;//创建临时变量，进行类型转化；
            const int & r4 = temp;
            ```
  - 指针和const
      1. 指向常量的指针（pointer to const）
          ```C++
          const double PI = 3.14;
          double * ptr = &PI;//编译器报错，不可以用普通指针指向const类型常量，存在修改风险；
          const double * Ptr = &PI;//编译通过，定义指向常量的指针,不可通过指针修改PI的值，但可以改变ptr指向的对象；可不初始化
          ```
      2. const指针
         指针本身不可修改，常量指针
         ```C++
         int a= 100；
         int * const p2 = &a;//不可修改P2指向的对象，但可以修改指向对象的数据；该常量指针必须初始化，即指向对象。
         *p2 = 120;//编译可以通过
         ```
      3. 顶层const
         所谓顶层const（top -level const）表示该对象本身就是常量，而底层const(low - level const)就是该对象所指向对象是常量，类似于常量指针和指向常量的指针。  
         `const int * const ptr = &a //左侧const是底层const ,表明所指向对象是const对象；右侧const是顶层const,表明该指针是一个常量指针`  
         `const int &r = a //用于声明引用的const都是底层const,表明所指向对象是const对象`  
         **注意：int ** p1 = &p2;是指向指针的指针，p1中储存的是p2的地址；而int * p1 = p2是将p2指向的对象的地址给p1 ,两者共同指向某一个对象，例如var**
      4. constexpr和常量表达式
         常量表达式是指在编译过程中就可以得到计算结果的表达式，而在运行中才可以得到结果的不是常量表达式；
         ```C++
         int b=10;//不是一个常量表达式；
         const int num_1 =10;
         const int num2 = num_1 + 10;//常量表达式
         const int num_3 = getnum_1();//非常量表达式
         ```
         *C++11新标准*：constexpr 允许将变量声明为一个常量，但其必须通过常量表达式初始化；
         `constexpr int var = 20;//正确`；
         `constexpr int var = getnum_1();//错误，getnum_1()不是常量表达式,会在编译器中直接报错；`
         ```c++
         constexpr int getnum_1(){//告诉编译器这是一个常量表达式
            return 1;
         }
         ```
         *内联使用inline关键字会将所使用函数直接粘贴到所使用的地方，而不是跳转调用，若在头文件中使用内联，则声明与定义均在头文件中*
      5. 指针与constexpr
         ```C++
         const int *p =nullptr;//指向常量的指针；
         constexpr int *q = nullptr;//指向整型的常量指针；使用该关键字定义指针时，指针必须为空或者指向一个具有固定地址的对象，而函数体中定义的变量一般不会存在与固定地址中，而一般只有全局变量或者常量才有固定地址；
         ```


         





        

    
    
 


    
    

















        

