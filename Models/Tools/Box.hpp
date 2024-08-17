/*************************************************************************
【文件名】 Box.hpp
【功能模块和目的】 Box 类表示一个棱平行于坐标轴的长方体。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

#include <cstddef>
#include "../Core/Point.hpp"
#include "../Containers/DynamicSet.hpp"
using namespace std;
using namespace C3w::Containers;

namespace C3w {

namespace Tools {

/*************************************************************************
【类名】 Box
【功能】 定义一个棱平行于坐标轴的 N 维长方体。使用两个顶点确定。不能从 Box 继承。
【接口说明】 
    成员：
        DIMENSION: 表示维数。
        Vertex1: 长方体的第一个顶点。
        Vertex2: 长方体的第二个顶点，与 Vertex1 构成对角线。
    构造与析构：
        默认构造函数，初始化后两顶点均为原点。
        接受两个顶点的构造函数。
        拷贝构造函数。
        GetBoundingBoxOf: 从点的集合创建一个包围盒。
    属性：
        GetVolume: 获取长方体的体积。
    操作：
        IsEqual: 相等性判断。
    操作符：
        operator==/!=: 同 IsEqual。
        operator=: 默认赋值运算符。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <size_t N>
class Box final {
    public:
        // 成员

        // 维数
        static constexpr size_t DIMENSION { N };
        // 第一个顶点
        Point<N> Vertex1;
        // 第二个顶点（可与另一顶点重合）
        Point<N> Vertex2;

        // 构造函数

        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用原点初始化 Box 对象。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box() = default;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用两个顶点初始化 Box 对象。
        【参数】 
            Vertex1: 第一个顶点。
            Vertex2: 第二个顶点。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box(const Point<N>& Vertex1, const Point<N>& Vertex2);
        /**********************************************************************
        【函数名称】 拷贝构造函数
        【函数功能】 使用另一 Box 对象初始化 Box 对象。
        【参数】 
            Other: 另一 Box 对象。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box(const Box<N>& Other) = default;
        /**********************************************************************
        【函数名称】 GetBoundingBoxOf
        【函数功能】 获取可以容纳所有给定点的最小长方体。
        【参数】 
            Points: 包含点的集合。
        【返回值】
            可以容纳所有给定点的最小长方体。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Box<N> GetBoundingBoxOf(const DynamicSet<Point<N>>& Points);

        // 属性

        /**********************************************************************
        【函数名称】 GetVolume
        【函数功能】 计算自身的体积。
        【参数】 无。
        【返回值】
            长方体体积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        double GetVolume() const;

        // 操作

        /**********************************************************************
        【函数名称】 IsEqual
        【函数功能】 判断自身和另一长方体是否相等。
        【参数】
            Other: 另一长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool IsEqual(const Box<N>& Other) const;
        /**********************************************************************
        【函数名称】 IsEqual
        【函数功能】 判断两长方体是否相等。
        【参数】
            Left: 第一个长方体。
            Right: 第二个长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static bool IsEqual(const Box<N>& Left, const Box<N>& Right);

        // 操作符

        /**********************************************************************
        【函数名称】 operator==
        【函数功能】 判断自身和另一长方体是否相等。
        【参数】
            Other: 另一长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool operator==(const Box<N>& Other) const;
        /**********************************************************************
        【函数名称】 operator!=
        【函数功能】 判断自身和另一长方体是否相等。
        【参数】
            Other: 另一长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool operator!=(const Box<N>& Other) const;
        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将另一长方体赋值给自身。
        【参数】
            Other: 从之取值的长方体。
        【返回值】
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box<N>& operator=(const Box<N>& Other) = default;
};

}

}

#include "Box.tpp"

#endif