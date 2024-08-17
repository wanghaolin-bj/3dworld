/*************************************************************************
【文件名】 ViewBase.hpp
【功能模块和目的】 ViewBase 类是所有视图的基类。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#ifndef VIEW_BASE_HPP
#define VIEW_BASE_HPP

#include <memory>
#include "../Controllers/ControllerBase.hpp"
using namespace std;
using namespace C3w::Controllers;

namespace C3w {

namespace Views {

/*************************************************************************
【类名】 ViewBase
【功能】 所有视图的基类。
【接口说明】 
    构造与析构：
        删除默认构造函数。
        接受一个控制器指针的构造函数。
        虚析构函数。
    操作：
        Display: 展示此视图。
    成员：
        m_pController: 存储控制器的指针。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
class ViewBase {
    public:
        // 操作

        /**********************************************************************
        【函数名称】 Display
        【函数功能】 向用户展示此视图。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        virtual void Display() const = 0;

        // 虚析构函数
        virtual ~ViewBase() = default;
    protected:
        // 删除默认构造函数
        ViewBase() = delete;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用控制器初始化 ViewBase 类型实例。
        【参数】
            Controller: 使用的控制器指针。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        ViewBase(shared_ptr<ControllerBase> Controller);

        // 控制器
        shared_ptr<ControllerBase> m_pController;
};

}

}

#endif