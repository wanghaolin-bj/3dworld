/*************************************************************************
【文件名】 Vector.hpp
【功能模块和目的】 Vector 类定义了一个 N 维向量。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#pragma once

#include <array>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <string>
#include "../Tools/Representable.hpp"
using namespace std;

namespace C3w { 

/*************************************************************************
【类名】 Vector
【功能】 定义一个分量类型为 T，维数为 N 的向量。
【接口说明】 获取/设置分量，向量的加减以及内积。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <typename T, size_t N>
class Vector: public Tools::Representable {
    static_assert(N > 0, "Dimension must be positive.");
    public:
        // 成员

        // 向量的维度，与模板中 N 相等。
        static constexpr size_t Dimension { N };

        // 构造函数

        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 初始化分量全部为 0 的 Vector 对象。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector() = default;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用初始化列表初始化 Vector 对象。
        【参数】 
            components: 分量构成的初始化列表。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector(initializer_list<T> components);
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用分量数组初始化 Vector 对象。
        【参数】 
            components: 分量构成的数组。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector(const array<T, N>& components);
        /**********************************************************************
        【函数名称】 拷贝构造函数
        【函数功能】 使用另一 Vector 初始化 Vector 对象。
        【参数】 
            other: 另一个向量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector(const Vector<T, N>& other) = default;

        // 访问器

        /**********************************************************************
        【函数名称】 GetComponent
        【函数功能】 返回指定下标处的分量。
        【参数】 
            index: 要获取分量的下标。
        【返回值】 
            对指定下标处的分量的常引用。
            如果下标越界，抛出 IndexOverflowException。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        const T& GetComponent(size_t index) const;
        /**********************************************************************
        【函数名称】 GetComponent
        【函数功能】 返回指定下标处的分量。
        【参数】 
            index: 要获取分量的下标。
        【返回值】 
            对指定下标处的分量的可变引用。
            如果下标越界，抛出 IndexOverflowException。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        T& GetComponent(size_t index);
        /**********************************************************************
        【函数名称】 SetComponent
        【函数功能】 设置指定下标处的分量。
        【参数】 
            index: 要设置分量的下标。
            value: 要设置的分量值。
        【返回值】 
            对指定下标处的分量的可变引用。
            如果下标越界，抛出 IndexOverflowException。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void SetComponent(size_t index, const T& value);
        /**********************************************************************
        【函数名称】 SetAllComponents
        【函数功能】 使用数组设置所有分量。
        【参数】 
            components: 分量构成的数组。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void SetAllComponents(const array<T, N>& components);

        // 属性

        // 零向量。
        static const Vector<T, N> Zero;
        /**********************************************************************
        【函数名称】 Module
        【函数功能】 求此向量的模长。
        【参数】 无
        【返回值】 此向量的模长。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        T Module() const;

        // 操作
        
        /**********************************************************************
        【函数名称】 IsEqual
        【函数功能】 判断自身是否和指定的向量相等。
        【参数】 
            other: 要与之判断的向量。
        【返回值】 
            自身和指定向量是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool IsEqual(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 IsEqual
        【函数功能】 判断两个向量是否相等。
        【参数】 
            left: 要判断的第一个向量。
            right: 要判断的第二个向量。
        【返回值】 
            两个向量是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static bool IsEqual(
            const Vector<T, N>& left, 
            const Vector<T, N>& right
        );
        /**********************************************************************
        【函数名称】 NegateInplace
        【函数功能】 反转此向量。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void NegateInplace();
        /**********************************************************************
        【函数名称】 Negate
        【函数功能】 反转此向量并存为新的向量。
        【参数】 无
        【返回值】 
            反转后的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> Negate() const;
        /**********************************************************************
        【函数名称】 Negate
        【函数功能】 反转给定向量并存为新的向量。
        【参数】 
            vector: 要反转的向量。
        【返回值】 
            反转后的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Vector<T, N> Negate(const Vector<T, N>& vector);
        /**********************************************************************
        【函数名称】 AddInplace
        【函数功能】 将自身加以另一个向量。
        【参数】 
            other: 另一个向量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void AddInplace(const Vector<T, N>& other);
        /**********************************************************************
        【函数名称】 Add
        【函数功能】 将自身与另一向量相加并存储为新的向量。
        【参数】 
            other: 另一向量。
        【返回值】 
            两向量相加形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> Add(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 Add
        【函数功能】 将两个向量相加并存储为新的向量。
        【参数】 
            left: 要相加的第一个向量。
            right: 要相加的第二个向量。
        【返回值】 
            两向量相加形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Vector<T, N> Add(
            const Vector<T, N>& left, 
            const Vector<T, N>& right
        );

        /**********************************************************************
        【函数名称】 SubtractInplace
        【函数功能】 将自身减去另一个向量。
        【参数】 
            other: 另一个向量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void SubtractInplace(const Vector<T, N>& other);
        /**********************************************************************
        【函数名称】 Subtract
        【函数功能】 将自身与另一向量相减并存储为新的向量。
        【参数】 
            other: 另一向量。
        【返回值】 
            两向量相减形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> Subtract(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 Subtract
        【函数功能】 将两个向量相减并存储为新的向量。
        【参数】 
            left: 要相减的第一个向量。
            right: 要相减的第二个向量。
        【返回值】 
            两向量相减形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Vector<T, N> Subtract(
            const Vector<T, N>& left, 
            const Vector<T, N>& right
        );
        /**********************************************************************
        【函数名称】 MultiplyInplace
        【函数功能】 将自身与标量数乘。
        【参数】 
            factor: 要数乘的标量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void MultiplyInplace(T factor);
        /**********************************************************************
        【函数名称】 Multiply
        【函数功能】 将自身与标量数乘。
        【参数】 
            factor: 要数乘的标量。
        【返回值】 
            数乘形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> Multiply(T factor) const;
        /**********************************************************************
        【函数名称】 Multiply
        【函数功能】 将向量与标量数乘。
        【参数】 
            vector: 要数乘的向量。
            factor: 要数乘的标量。
        【返回值】 
            数乘形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static Vector<T, N> Multiply(const Vector<T, N> vector, T factor);
        /**********************************************************************
        【函数名称】 InnerProduct
        【函数功能】 将自身和另一向量做内积。
        【参数】 
            other: 另一个向量。
        【返回值】 与另一向量的内积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        T InnerProduct(const Vector<T, N>& other);
        /**********************************************************************
        【函数名称】 InnerProduct
        【函数功能】 将两个向量做内积。
        【参数】 
            left: 要做内积的第一个向量。
            right: 要做内积的第二个向量。
        【返回值】 
            两向量的内积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static T InnerProduct(
            const Vector<T, N>& left, 
            const Vector<T, N>& right
        );

        // 操作符

        /**********************************************************************
        【函数名称】 operator[]
        【函数功能】 通过下标访问分量。
        【参数】 
            index: 要访问的下标。
        【返回值】 
            分量的常引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        const T& operator[](size_t index) const;
        /**********************************************************************
        【函数名称】 operator[]
        【函数功能】 通过下标访问分量。
        【参数】 
            index: 要访问的下标。
        【返回值】 
            分量的可变引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        T& operator[](size_t index);
        /**********************************************************************
        【函数名称】 operator-
        【函数功能】 反转此向量并存为新的向量。
        【参数】 无
        【返回值】 
            反转后的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> operator-() const;
        /**********************************************************************
        【函数名称】 operator+
        【函数功能】 将自身与另一个向量的和存储为新的向量。
        【参数】 
            other: 另一个向量。
        【返回值】
            自身与另一向量相加形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> operator+(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 operator+=
        【函数功能】 将自身加以另一个向量。
        【参数】 
            other: 另一个向量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N>& operator+=(const Vector<T, N>& other);
        /**********************************************************************
        【函数名称】 operator-
        【函数功能】 将自身与另一个向量的差存储为新的向量。
        【参数】 
            other: 另一个向量。
        【返回值】
            自身与另一向量相减形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> operator-(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 operator-=
        【函数功能】 将自身减去另一个向量。
        【参数】 
            other: 另一个向量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N>& operator-=(const Vector<T, N>& other);
        /**********************************************************************
        【函数名称】 operator*
        【函数功能】 将自身做数乘。
        【参数】 
            factor: 要数乘的标量。
        【返回值】 
            数乘得到的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N> operator*(T factor) const;
        /**********************************************************************
        【函数名称】 operator*=
        【函数功能】 将自身做数乘。
        【参数】 
            factor: 要数乘的标量。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N>& operator*=(T factor);
        /**********************************************************************
        【函数名称】 operator*
        【函数功能】 将自身和另一向量做内积。
        【参数】 
            other: 另一个向量。
        【返回值】 与另一向量的内积。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        T operator*(const Vector<T, N>& other) const;
        // 将所有模板实现声明为友元
        /**********************************************************************
        【函数名称】 operator*
        【函数功能】 将向量与标量数乘。
        【参数】 
            vector: 要数乘的向量。
            factor: 要数乘的标量。
        【返回值】 
            数乘形成的新的向量。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        template <typename U, size_t M>
        friend Vector<U, M> operator*(U factor, const Vector<U, M>& vector);
        /**********************************************************************
        【函数名称】 operator==
        【函数功能】 判断自身是否和指定的向量相等。
        【参数】 
            other: 要与之判断的向量。
        【返回值】 
            自身和指定向量是否相等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool operator==(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 operator!=
        【函数功能】 判断自身是否和指定的向量不等。
        【参数】 
            other: 要与之判断的向量。
        【返回值】 
            自身和指定向量是否不等。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        bool operator!=(const Vector<T, N>& other) const;
        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将其他向量赋值给自身。
        【参数】 
            other: 从之取值的向量。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        Vector<T, N>& operator=(const Vector<T, N>& other) = default;

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

        // 虚析构函数
        virtual ~Vector() = default;
    
    private:
        // 分量
        array<T, N> m_Components;
};

}

#include "Vector.tpp"