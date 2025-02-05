/*************************************************************************
【文件名】 ImporterBase.hpp
【功能模块和目的】 ImporterBase 类定义了一个抽象的导入器。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#pragma once

#include <cstddef>
#include <fstream>
#include <string>
#include "../Core/Model.hpp"
using namespace std;
using namespace C3w;

namespace C3w {

namespace Storage {

/*************************************************************************
【类名】 ImporterBase
【功能】 定义一个抽象的导入器。
【接口说明】 导入指定的文件。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/
template <size_t N>
class ImporterBase {
    public:
        // 操作

        // 考虑子类实现，传引用作为参数而非直接返回 Model<N>。
        /**********************************************************************
        【函数名称】 Import
        【函数功能】 导入指定文件到模型中。
        【参数】 
            path: 文件所在路径。
            model: 模型的可变引用。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        void Import(string path, Model<N>& model) const;

        // 虚析构函数
        virtual ~ImporterBase() = default;

    protected:
        /**********************************************************************
        【函数名称】 InnerImport
        【函数功能】 导入指定文件流到模型中。
        【参数】 
            stream: 已经打开的文件流。
            model: 模型的可变引用。
        【返回值】 无
        【开发者及日期】 赵一彤 2024/7/24
        **********************************************************************/
        virtual void InnerImport(ifstream& stream, Model<N>& model) const = 0;
};

}

}

#include "ImporterBase.tpp"