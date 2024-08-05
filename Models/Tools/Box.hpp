/*************************************************************************
【文件名】 Box.hpp
【功能模块和目的】 Box 类表示一个棱平行于坐标轴的长方体。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#pragma once

#include <cstddef>
#include "../Core/Point.hpp"
#include "../Containers/DynamicSet.hpp"
using namespace std;

namespace c3w::tools {

/*************************************************************************
【类名】 Box
【功能】 定义一个棱平行于坐标轴的 N 维长方体。使用两个顶点确定。不能从 Box 继承。
【接口说明】 获取/修改点，求体积。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <size_t N>
class Box final {
    public:
        // 成员

        // 维数
        static constexpr size_t Dimension { N };
        // 第一个顶点
        Point<N> Vertex1;
        // 第二个顶点（可与另一顶点重合）
        Point<N> Vertex2;

        // 构造函数

        // 删除默认构造函数
        Box() = delete;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用两个顶点初始化 Box 对象。
        【参数】 
            vertex1: 第一个顶点。
            vertex2: 第二个顶点。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box(const Point<N>& vertex1, const Point<N>& vertex2);
        /**********************************************************************
        【函数名称】 拷贝构造函数
        【函数功能】 使用另一 Box 对象初始化 Box 对象。
        【参数】 
            other: 另一 Box 对象。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box(const Box<N>& other);
        /**********************************************************************
        【函数名称】 BoundingBoxOf
        【函数功能】 获取可以容纳所有给定点的最小长方体。
        【参数】 
            points: 包含点的集合。
        【返回值】
            可以容纳所有给定点的最小长方体。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Box<N> BoundingBoxOf(const DynamicSet<Point<N>>& points);

        // 属性

        /**********************************************************************
        【函数名称】 Volume
        【函数功能】 计算自身的体积。
        【参数】 无。
        【返回值】
            长方体体积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        double Volume() const;

        // 操作

        /**********************************************************************
        【函数名称】 IsEqual
        【函数功能】 判断自身和另一长方体是否相等。
        【参数】
            other: 另一长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool IsEqual(const Box<N>& other) const;
        /**********************************************************************
        【函数名称】 IsEqual
        【函数功能】 判断两长方体是否相等。
        【参数】
            left: 第一个长方体。
            right: 第二个长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static bool IsEqual(const Box<N>& left, const Box<N>& right);

        // 操作符

        /**********************************************************************
        【函数名称】 operator==
        【函数功能】 判断自身和另一长方体是否相等。
        【参数】
            other: 另一长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool operator==(const Box<N>& other) const;
        /**********************************************************************
        【函数名称】 operator!=
        【函数功能】 判断自身和另一长方体是否相等。
        【参数】
            other: 另一长方体。
        【返回值】
            两长方体是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool operator!=(const Box<N>& other) const;
        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将另一长方体赋值给自身。
        【参数】
            other: 从之取值的长方体。
        【返回值】
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Box<N>& operator=(const Box<N>& other);
};

}

#include "Box.tpp"