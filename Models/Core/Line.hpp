/*************************************************************************
【文件名】 Line.hpp
【功能模块和目的】 Line 类定义继承自两点元素的线段。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#ifndef LINE_HPP
#define LINE_HPP

#include "Element.hpp"
#include "Vector.hpp"
#include "Point.hpp"

namespace C3w {

/*************************************************************************
【类名】 Line
【功能】 定义一个维数 N 的线段。
【接口说明】 全部继承自 Element。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <size_t N>
class Line: public Element<N, 2> {
    public:
        // 属性
        
        // 起始点
        const Point<N>& Start { this->Points[0] };
        // 中止点
        const Point<N>& End { this->Points[1] };

        // 构造函数

        // 使用 Element 的构造函数
        using Element<N, 2>::Element;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用两个点初始化 Line 对象。
        【参数】 
            start: 起始点。
            end: 中止点。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Line(const Point<N>& start, const Point<N>& end);
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用一个 Element 初始化 Line 对象。
        【参数】 
            element: 一个包含两个点的元素。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Line(const Element<N, 2>& element);
        /**********************************************************************
        【函数名称】 拷贝构造函数
        【函数功能】 使用另一 Line 对象初始化 Line 对象。
        【参数】 
            other: 另一个 Line 对象。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Line(const Line<N>& other);

        // 属性

        /**********************************************************************
        【函数名称】 GetLength
        【函数功能】 求此元素的长度。
        【参数】 无
        【返回值】
            此元素的长度。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        double GetLength() const override;
        /**********************************************************************
        【函数名称】 GetArea
        【函数功能】 求此元素的面积。
        【参数】 无
        【返回值】
            此元素的面积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        double GetArea() const override;

        // 操作

        /**********************************************************************
        【函数名称】 IsParallel
        【函数功能】 判断自身是否和指定的线段平行。
        【参数】 
            other: 要与之判断的线段。
        【返回值】 
            自身和指定向量是否平行。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool IsParallel(const Line<N>& other) const;
        /**********************************************************************
        【函数名称】 IsParallel
        【函数功能】 判断两个线段是否平行。
        【参数】 
            left: 要判断的第一个线段。
            right: 要判断的第二个线段。
        【返回值】 
            两个向量是否平行。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static bool IsParallel(
            const Line<N>& left, 
            const Line<N>& right
        );
        /**********************************************************************
        【函数名称】 IsPerpendicular
        【函数功能】 判断自身是否和指定的线段垂直。
        【参数】 
            other: 要与之判断的线段。
        【返回值】 
            自身和指定线段是否垂直。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool IsPerpendicular(const Line<N>& other) const;
        /**********************************************************************
        【函数名称】 IsPerpendicular
        【函数功能】 判断两个线段是否垂直。
        【参数】 
            left: 要判断的第一个线段。
            right: 要判断的第二个线段。
        【返回值】 
            两个线段是否垂直。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static bool IsPerpendicular(
            const Line<N>& left,
            const Line<N>& right
        );
        /**********************************************************************
        【函数名称】 Intersection
        【函数功能】 获取自身与另一线段的交点。无交点返回 Point<N>::Void。
        【参数】 
            other: 另一个线段。
        【返回值】 
            两个线段的交点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> Intersection(const Line<N>& other) const;
        /**********************************************************************
        【函数名称】 Intersection
        【函数功能】 获取两线段的交点。无交点返回 Point<N>::Void。
        【参数】 
            left: 第一个线段。
            right: 第二个线段。
        【返回值】 
            两个线段的交点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Point<N> Intersection(
            const Line<N>& left, 
            const Line<N>& right
        );

        // 操作符

        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将另一元素赋值给自身。
        【参数】
            other: 从之取值的元素。
        【返回值】
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Line<N>& operator=(const Element<N, 2>& element);
        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将另一线段赋值给自身。
        【参数】
            other: 从之取值的线段。
        【返回值】
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Line<N>& operator=(const Line<N>& other);
        /**********************************************************************
        【函数名称】 operator Vector<double, N>
        【函数功能】 将自身转化为向量。
        【参数】 无
        【返回值】
            从起点指向终点的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        operator Vector<double, N>() const;
};

}

#include "Line.tpp"

#endif