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

