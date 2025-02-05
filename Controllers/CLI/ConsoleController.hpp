/*************************************************************************
【文件名】 ConsoleController.hpp
【功能模块和目的】 ConsoleController 类定义了一个用于控制台的控制器。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#pragma once

#include <memory>
#include <string>
#include "../ControllerBase.hpp"
#include "../../Models/Core/Line.hpp"
#include "../../Models/Core/Face.hpp"
using namespace std;

namespace C3w {

namespace Controllers {

namespace Cli {

/*************************************************************************
【类名】 ConsoleController
【功能】 用于控制台的控制器。
【接口说明】 单例，继承于 ControllerBase。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
class ConsoleController: public ControllerBase {
    public:
        // 构造函数

        /**********************************************************************
        【函数名称】 GetInstance
        【函数功能】 获取 ConsoleController 的唯一实例。
        【参数】 无
        【返回值】
            ConsoleController 的唯一实例。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static shared_ptr<ConsoleController> GetInstance();
        
    protected:
        /**********************************************************************
        【函数名称】 PointToString
        【函数功能】 获取点的字符串表达形式。
        【参数】
            point: 要转化的点。
        【返回值】
            点的字符串表达形式。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        string PointToString(const Point<3>& point) const override;
        /**********************************************************************
        【函数名称】 LineToString
        【函数功能】 获取线段及其状态的字符串表达形式。
        【参数】
            line: 要转化的线段。
            status: 线段的状态。
        【返回值】
            线段的字符串表达形式。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        string LineToString(
            const Line<3>& line, 
            Status status
        ) const override;
        /**********************************************************************
        【函数名称】 FaceToString
        【函数功能】 获取面的字符串表达形式。
        【参数】
            face: 要转化的面。
            status: 面的状态。
        【返回值】
            面的字符串表达形式。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        string FaceToString(
            const Face<3>& face, 
            Status status
        ) const override;
    private:
        // 单例
        static shared_ptr<ConsoleController> m_pInstance;
        // 使用基类的构造函数
        using ControllerBase::ControllerBase;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 初始化默认的 ConsoleController 类型实例。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        ConsoleController() = default;
};

}

}

}