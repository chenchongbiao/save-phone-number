cmake_minimum_required(VERSION 3.1.0)  # 指定cmake最低版本
project(main                           # 指定项目名称, 版本, 语言 c就是c语言
    VERSION 1.0.0 
    LANGUAGES C
) 

set(CMAKE_C_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)      # 设置包含当前目录

add_executable(${PROJECT_NAME}         # 生成可执行文件
    main.c
)
