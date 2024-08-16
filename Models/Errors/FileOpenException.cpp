/*************************************************************************
【文件名】 FileOpenException.cpp
【功能模块和目的】 为 FileOpenException.hpp 提供实现。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#include <stdexcept>
#include <string>
#include "FileOpenException.hpp"
using namespace std;

namespace C3w {

namespace Errors {

/**********************************************************************
【函数名称】 构造函数
【函数功能】 以默认信息初始化异常。
【参数】
    Path: 文件的路径。
【返回值】 无
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
FileOpenException::FileOpenException(string Path)
    : runtime_error(
        "cannot open file '" + Path + "'"
    ) {}

}

}