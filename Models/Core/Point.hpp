/*************************************************************************
【文件名】 Point.hpp
【功能模块和目的】 Point 类定义了一个 N 维点。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#include <cstddef>
#include <string>
#include "Vector.hpp"
using namespace std;

namespace C3w {

/*************************************************************************
【类名】 Point
【功能】 定义一个维数为 N 的点。
【接口说明】 获取/设置分量，求两点距离，相减得到向量，升维/降维。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <size_t N>
class Point: public Vector<double, N> {
    public:
        // 使用基类构造函数
        using Vector<double, N>::Vector;

        // 构造函数

        // 如果没有此构造函数，g++ 可以通过，但 msvc 报错。
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 初始化坐标全部为 0 的 Point 类的实例。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point() = default;
        /**********************************************************************
        【函数名称】 拷贝构造函数
        【函数功能】 使用另一 Point 初始化 Point 类的实例。
        【参数】
            other: 另一 Point 实例。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point(const Point<N>& other) = default;

        // 属性

        // 原点。
        static const Point<N> Origin;
        /**********************************************************************
        【函数名称】 Distance
        【函数功能】 求两个点之间的直线距离。
        【参数】 
            left: 第一个点。
            right: 第二个点。
        【返回值】
            两点之间的直线距离。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static double Distance(const Point<N>& left, const Point<N>& right);
        /**********************************************************************
        【函数名称】 Distance
        【函数功能】 求自身与另一点之间的直线距离。
        【参数】 
            other: 另一个点。
        【返回值】
            两点之间的直线距离。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        double Distance(const Point<N>& other) const;
        /**********************************************************************
        【函数名称】 GeneralDistance
        【函数功能】 求两个点之间的广义直线距离。
        【参数】 
            left: 第一个点。
            right: 第二个点。
        【返回值】
            两点之间的直线距离。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        template <size_t M>
        static double GeneralDistance(
            const Point<N>& left, 
            const Point<M>& right
        );
        /**********************************************************************
        【函数名称】 GeneralDistance
        【函数功能】 求自身与另一点之间的广义直线距离。
        【参数】 
            other: 另一个点。
        【返回值】
            两点之间的直线距离。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        template <size_t M>
        double GeneralDistance(const Point<M>& other) const;

        // 操作

        /**********************************************************************
        【函数名称】 Project
        【函数功能】 将自身从 N 维投影至更低的 M 维。
        【参数】 无
        【返回值】
            一个 M 维的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        template <size_t M>
        Point<M> Project() const;
        /**********************************************************************
        【函数名称】 Promote
        【函数功能】 将自身从 N 维升至更高的 M 维。
        【参数】 
            pad: 可选，填充于高维坐标的数，默认 0。
        【返回值】
            一个 M 维的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        template <size_t M>
        Point<M> Promote(double pad = 0) const;
        /**********************************************************************
        【函数名称】 Negate
        【函数功能】 反转此点并存为新的点。
        【参数】 无
        【返回值】 
            反转后的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> Negate() const;
        /**********************************************************************
        【函数名称】 Negate
        【函数功能】 反转给定点并存为新的点。
        【参数】 
            point: 要反转的点。
        【返回值】 
            反转后的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Point<N> Negate(const Point<N>& point);
        /**********************************************************************
        【函数名称】 Add
        【函数功能】 将自身与一向量相加并存储为新的点。
        【参数】 
            delta: 相加的向量。
        【返回值】 
            点与向量相加形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> Add(const Vector<double, N>& delta) const;
        /**********************************************************************
        【函数名称】 Add
        【函数功能】 将点与一向量相加并存储为新的点。
        【参数】 
            point: 相加的点
            delta: 相加的向量。
        【返回值】 
            点与向量相加形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Point<N> Add(
            const Point<N>& point, 
            const Vector<double, N>& delta
        );
        /**********************************************************************
        【函数名称】 Subtract
        【函数功能】 将自身与一向量相减并存储为新的点。
        【参数】 
            delta: 相减的向量。
        【返回值】 
            点与向量相减形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> Subtract(const Vector<double, N>& delta) const;
        /**********************************************************************
        【函数名称】 Subtract
        【函数功能】 将自身与另一点相减并存储为向量。
        【参数】 
            other: 相减的点。
        【返回值】 
            点与点相减形成的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<double, N> Subtract(const Point<N>& other) const;
        /**********************************************************************
        【函数名称】 Subtract
        【函数功能】 将点与一向量相减并存储为新的点。
        【参数】 
            point: 相减的点
            delta: 相减的向量。
        【返回值】 
            点与向量相减形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Point<N> Subtract(
            const Point<N>& point,
            const Vector<double, N>& delta
        );
        /**********************************************************************
        【函数名称】 Subtract
        【函数功能】 将两点点相减并存储为向量。
        【参数】 
            left: 第一个点。
            right: 第二个点。
        【返回值】 
            点与点相减形成的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Vector<double, N> Subtract(
            const Point<N>& left,
            const Point<N>& right
        );

        // 操作符
        
        /**********************************************************************
        【函数名称】 operator-
        【函数功能】 反转此点并存为新的点。
        【参数】 无
        【返回值】 
            反转后的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> operator-() const;
        /**********************************************************************
        【函数名称】 operator+
        【函数功能】 将自身与一向量相加并存储为新的点。
        【参数】 
            delta: 相加的向量。
        【返回值】 
            点与向量相加形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> operator+(const Vector<double, N>& delta) const;
        /**********************************************************************
        【函数名称】 operator+=
        【函数功能】 将自身与一向量相加。
        【参数】 
            delta: 相加的向量。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N>& operator+=(const Vector<double, N>& delta);
        /**********************************************************************
        【函数名称】 operator-
        【函数功能】 将自身与一向量相减并存储为新的点。
        【参数】 
            delta: 相减的向量。
        【返回值】 
            点与向量相减形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N> operator-(const Vector<double, N>& delta) const;
        /**********************************************************************
        【函数名称】 operator-
        【函数功能】 将自身与另一点相减并存储为向量。
        【参数】 
            other: 相减的点。
        【返回值】 
            点与点相减形成的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<double, N> operator-(const Point<N>& other) const;
        /**********************************************************************
        【函数名称】 operator-=
        【函数功能】 将自身与一向量相减并存储为新的点。
        【参数】 
            delta: 相减的向量。
        【返回值】 
            点与向量相减形成的新的点。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N>& operator-=(const Vector<double, N>& delta);
        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将另一点赋值于自身。
        【参数】 
            other: 要从之取值的点。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Point<N>& operator=(const Point<N>& other) = default;

        // 格式化
        
        /**********************************************************************
        【函数名称】 ToString
        【函数功能】 返回此对象的字符串表达形式。
        【参数】 无
        【返回值】 
            此对象的字符串表达形式。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        string ToString() const override;

        // 继承基类的函数：
        // GetComponent
        // SetComponent
        // SetAllComponents
        // NegateInplace
        // AddInplace
        // SubtractInplace
        // operator[]
        // operator==
        // operator!=

    private:
        // 隐藏向量独有的函数
        using Vector<double, N>::MultiplyInplace;
        using Vector<double, N>::Multiply;
        using Vector<double, N>::InnerProduct;
        using Vector<double, N>::operator*;
        using Vector<double, N>::operator*=;
        using Vector<double, N>::Module;
        using Vector<double, N>::Zero;
};

}

#include "Point.tpp"

#endif