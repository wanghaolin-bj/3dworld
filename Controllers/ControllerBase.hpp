/*************************************************************************
【文件名】 ControllerBase.hpp
【功能模块和目的】 ControllerBase 类定义了一个控制器的基类。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include "../Models/Core/Model.hpp"
#include "../Models/Core/Line.hpp"
#include "../Models/Core/Face.hpp"
#include "../Models/Core/Point.hpp"
using namespace std;

namespace C3w {

namespace Controllers {

/*************************************************************************
【类名】 ControllerBase
【功能】 所有控制器的基类。
【接口说明】 获取/修改/添加/删除模型中的线段/面，导入/导出模型。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
class ControllerBase {
    public:
        // 内嵌类型

        /**********************************************************************
        【类名】 Result
        【功能】 控制器大部分函数的返回值类型。
        【接口说明】 枚举，表示发生的错误。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        enum class Result: short {
            // 操作成功
            OK,
            // 没有合适的导入/导出器
            STORAGE_LOOKUP_ERROR,
            // 文件无法打开
            FILE_OPEN_ERROR,
            // 文件内容错误
            FILE_FORMAT_ERROR,
            // 下标越界
            INDEX_OVERFLOW,
            // 点下标越界
            POINT_INDEX_OVERFLOW,
            // 点重复
            POINT_COLLISION,
            // 元素重复
            ELEMENT_COLLISION
        };

        /**********************************************************************
        【类名】 Status
        【功能】 代表线段/面是否为刚创建的或是被修改过的。
        【接口说明】 枚举，表示元素的状态。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        enum class Status {
            // 未修改
            UNTOUCHED,
            // 被创建
            CREATED,
            // 已修改
            MODIFIED
        };

        /**********************************************************************
        【类名】 GetElementResult
        【功能】 用于 GetLines / GetFaces 的返回值。
        【接口说明】 包含元素的字符串表达形式以及状态。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        struct GetElementResult {
            // 字符串表达形式
            string String;
            // 元素状态
            Status ElementStatus;
        };

        /**********************************************************************
        【类名】 Statistics
        【功能】 用于 GetStatistics 的返回值。
        【接口说明】 点数量，线段数量/总长度，面数量/总面积，外接长方体体积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        struct Statistics {
            // 点数量
            size_t TotalPointCount;
            // 线段数量
            size_t TotalLineCount;
            // 线段总长度
            double TotalLineLength;
            // 面数量
            size_t TotalFaceCount;
            // 面总面积
            double TotalFaceArea;
            // 外接长方体体积
            double BoundingBoxVolume;
        };
        
        // 构造函数

        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 创建一个默认的 ControllerBase 类型实例。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        ControllerBase() = default;
        // 删除拷贝构造函数
        ControllerBase(const ControllerBase& other) = delete;
        // 删除移动构造函数
        ControllerBase(ControllerBase&& other) = delete;

        // 操作

        /**********************************************************************
        【函数名称】 GetName
        【函数功能】 获取模型的名称。
        【参数】 无
        【返回值】 
            模型的名称。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        string GetName() const;
        /**********************************************************************
        【函数名称】 GetLines
        【函数功能】 获取所有线段的字符串表达形式。
        【参数】 无
        【返回值】 
            所有线段的字符串表达形式。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        vector<GetElementResult> GetLines() const;
        /**********************************************************************
        【函数名称】 GetLinePoints
        【函数功能】 获取指定线段中所有点的字符串表达形式。
        【参数】
            index: 线段的下标。
            points: 要赋值的向量。
        【返回值】 
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result GetLinePoints(size_t index, vector<string>& points) const;
        /**********************************************************************
        【函数名称】 AddLine
        【函数功能】 添加一个线段。
        【参数】
            x1, y1, z1: 第一个点的三维坐标。
            x2, y2, z2: 第二个点的三维坐标。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result AddLine(
            double x1, double y1, double z1,
            double x2, double y2, double z2
        );
        /**********************************************************************
        【函数名称】 ModifyLine
        【函数功能】 修改一个线段。
        【参数】
            index: 线段的下标。
            pointIndex: 要修改的点在线段中的下标。
            x, y, z: 修改后点的三维坐标。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result ModifyLine(
            size_t index,
            size_t pointIndex,
            double x, double y, double z
        );
        /**********************************************************************
        【函数名称】 RemoveLine
        【函数功能】 删除一个线段。
        【参数】
            index: 要删除线段的下标。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result RemoveLine(size_t index);
        /**********************************************************************
        【函数名称】 GetFaces
        【函数功能】 获取所有面的字符串表达形式。
        【参数】 无
        【返回值】 
            所有面的字符串表达形式。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        vector<GetElementResult> GetFaces() const;
        /**********************************************************************
        【函数名称】 GetLinePoints
        【函数功能】 获取指定面中所有点的字符串表达形式。
        【参数】
            index: 面的下标。
            points: 要赋值的向量。
        【返回值】 
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result GetFacePoints(size_t index, vector<string>& points) const;
        /**********************************************************************
        【函数名称】 AddFace
        【函数功能】 添加一个面。
        【参数】
            x1, y1, z1: 第一个点的三维坐标。
            x2, y2, z2: 第二个点的三维坐标。
            x3, y3, z3: 第三个点的三维坐标。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result AddFace(
            double x1, double y1, double z1,
            double x2, double y2, double z2,
            double x3, double y3, double z3
        );
        /**********************************************************************
        【函数名称】 ModifyFace
        【函数功能】 修改一个面。
        【参数】
            index: 面的下标。
            pointIndex: 要修改的点在面中的下标。
            x, y, z: 修改后点的三维坐标。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result ModifyFace(
            size_t index,
            size_t pointIndex,
            double x, double y, double z
        );
        /**********************************************************************
        【函数名称】 RemoveFace
        【函数功能】 删除一个面。
        【参数】
            index: 要删除面的下标。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result RemoveFace(size_t index);
        /**********************************************************************
        【函数名称】 GetStatistics
        【函数功能】 获取统计信息。
        【参数】 无
        【返回值】
            模型统计信息。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Statistics GetStatistics() const;
        /**********************************************************************
        【函数名称】 LoadModel
        【函数功能】 从文件加载一个模型。
        【参数】
            path: 文件位置。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result LoadModel(string path);
        /**********************************************************************
        【函数名称】 SaveModel
        【函数功能】 向文件保存一个模型。
        【参数】
            path: 文件位置。
        【返回值】
            函数发生的错误类型。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Result SaveModel(string path);

        // 虚析构函数
        virtual ~ControllerBase() = default;

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
        virtual string PointToString(const Point<3>& point) const = 0;
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
        virtual string LineToString(
            const Line<3>& line, 
            Status status
        ) const = 0;
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
        virtual string FaceToString(
            const Face<3>& face, 
            Status status
        ) const = 0;
    private:
        string m_Path;
        Model<3> m_Model;
        vector<Status> m_LineStatus;
        vector<Status> m_FaceStatus;
};

}

}