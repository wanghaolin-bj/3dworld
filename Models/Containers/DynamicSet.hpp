/*************************************************************************
【文件名】 DynamicSet.hpp
【功能模块和目的】 DynamicSet 类定义了一个动态大小的集合。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#pragma once

#include <cstddef>
#include <vector>
#include "DistinctCollection.hpp"
using namespace std;

namespace C3w {

namespace Containers {

/*************************************************************************
【类名】 DynamicSet
【功能】 定义一个元素类型为 T 的动态大小的集合。
【接口说明】 获取/设置/添加/删除元素，判断是否包含元素，集合的交并补。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <typename T>
class DynamicSet: public DistinctCollection<T> {
    public:
        // 构造函数

        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 初始化空的 DynamicSet 类型实例。
        【参数】 无
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet() = default;
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用初始化列表初始化 DynamicSet 类型实例。
        【参数】
            elements: 元素初始化列表。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet(initializer_list<T> elements);
        /**********************************************************************
        【函数名称】 构造函数
        【函数功能】 使用 std::vector<T> 初始化 DynamicSet 类型实例。
        【参数】
            elements: 元素组成的向量。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet(const vector<T>& elements);
        /**********************************************************************
        【函数名称】 拷贝构造函数
        【函数功能】 使用另一 DynamicSet 初始化 DynamicSet 类的实例。
        【参数】
            other: 另一 DynamicSet 实例。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet(const DynamicSet<T>& other) = default;

        // 属性
        /**********************************************************************
        【函数名称】 Count
        【函数功能】 获取元素个数。
        【参数】 无
        【返回值】 
            集合中的元素个数。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        size_t Count() const override;

        // 操作

        /**********************************************************************
        【函数名称】 Intersection
        【函数功能】 返回此集合与另一集合的交集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的交集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> Intersection(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 Intersection
        【函数功能】 返回两集合的交集。
        【参数】 
            left: 第一个集合。
            right: 第二个集合。
        【返回值】 
            两集合的交集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static DynamicSet<T> Intersection(
            const DynamicSet<T>& left,
            const DynamicSet<T>& right
        );
        /**********************************************************************
        【函数名称】 Union
        【函数功能】 返回此集合与另一集合的并集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的并集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> Union(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 Union
        【函数功能】 返回两集合的并集。
        【参数】 
            left: 第一个集合。
            right: 第二个集合。
        【返回值】 
            两集合的并集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static DynamicSet<T> Union(
            const DynamicSet<T>& left,
            const DynamicSet<T>& right
        );
        /**********************************************************************
        【函数名称】 Difference
        【函数功能】 返回此集合与另一集合的差集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的差集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> Difference(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 Difference
        【函数功能】 返回两集合的差集。
        【参数】 
            left: 第一个集合。
            right: 第二个集合。
        【返回值】 
            两集合的差集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static DynamicSet<T> Difference(
            const DynamicSet<T>& left,
            const DynamicSet<T>& right
        );
        /**********************************************************************
        【函数名称】 SymmetricDifference
        【函数功能】 返回此集合与另一集合的对称差集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的对称差集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> SymmetricDifference(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 SymmetricDifference
        【函数功能】 返回两集合的对称差集。
        【参数】 
            left: 第一个集合。
            right: 第二个集合。
        【返回值】 
            两集合的对称差集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        static DynamicSet<T> SymmetricDifference(
            const DynamicSet<T>& left,
            const DynamicSet<T>& right
        );

        // 操作符

        /**********************************************************************
        【函数名称】 operator=
        【函数功能】 将其他集合赋值给自身。
        【参数】 
            other: 从之取值的集合。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T>& operator=(const DynamicSet<T>& other) = default;
        /**********************************************************************
        【函数名称】 operator&
        【函数功能】 返回此集合与另一集合的交集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的交集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> operator&(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 operator&=
        【函数功能】 将自身赋值为此集合与另一集合的交集。
        【参数】 
            other: 另一集合。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T>& operator&=(const DynamicSet<T>& other);
        /**********************************************************************
        【函数名称】 operator|
        【函数功能】 返回此集合与另一集合的并集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的并集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> operator|(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 operator|=
        【函数功能】 将自身赋值为此集合与另一集合的并集。
        【参数】 
            other: 另一集合。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T>& operator|=(const DynamicSet<T>& other);
        /**********************************************************************
        【函数名称】 operator-
        【函数功能】 返回此集合与另一集合的差集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的差集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> operator-(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 operator-=
        【函数功能】 将自身赋值为此集合与另一集合的差集。
        【参数】 
            other: 另一集合。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T>& operator-=(const DynamicSet<T>& other);
        /**********************************************************************
        【函数名称】 operator^
        【函数功能】 返回此集合与另一集合的对称差集。
        【参数】 
            other: 另一集合。
        【返回值】 
            两集合的对称差集。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> operator^(const DynamicSet<T>& other) const;
        /**********************************************************************
        【函数名称】 operator^=
        【函数功能】 将自身赋值为此集合与另一集合的对称差集。
        【参数】 
            other: 另一集合。
        【返回值】 
            自身的引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        DynamicSet<T> operator^=(const DynamicSet<T>& other);

        // 迭代器

        /**********************************************************************
        【函数名称】 begin
        【函数功能】 获取头部迭代器。
        【参数】 无
        【返回值】 
            指向首个元素的迭代器。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        typename vector<T>::const_iterator begin() const;
        /**********************************************************************
        【函数名称】 end
        【函数功能】 获取尾部迭代器。
        【参数】 无
        【返回值】 
            指向最后元素之后的迭代器。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        typename vector<T>::const_iterator end() const;

    protected:
        /**********************************************************************
        【函数名称】 InnerGet
        【函数功能】 无条件获取元素值。
        【参数】 
            index: 要获取的下标。
        【返回值】 
            指定位置元素的常引用。
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        const T& InnerGet(size_t index) const override;
        /**********************************************************************
        【函数名称】 InnerSet
        【函数功能】 无条件设置元素值。
        【参数】 
            index: 要设置的下标。
            value: 要设置的值。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void InnerSet(size_t index, const T& value) override;
        /**********************************************************************
        【函数名称】 InnerAdd
        【函数功能】 无条件添加元素。
        【参数】 
            value: 要添加的值。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void InnerAdd(const T& value) override;
        /**********************************************************************
        【函数名称】 InnerRemove
        【函数功能】 无条件删除元素。
        【参数】 
            index: 要删除的下标。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void InnerRemove(size_t index) override;
        /**********************************************************************
        【函数名称】 InnerInsert
        【函数功能】 无条件插入元素。
        【参数】 
            index: 要插入位置的下标。
            element: 新的元素。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void InnerInsert(size_t index, const T& element) override;

    private:
        vector<T> m_Elements;
};

}

}

#include "DynamicSet.tpp"