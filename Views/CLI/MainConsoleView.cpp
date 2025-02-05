/*************************************************************************
【文件名】 MainConsoleView.cpp
【功能模块和目的】 为 MainConsoleView.hpp 文件提供实现。
【开发者及日期】 赵一彤 2024/7/24
*************************************************************************/

#include <functional>
#include <memory>
#include <iostream>
#include "ConsoleViewBase.hpp"
#include "LinesConsoleView.hpp"
#include "FacesConsoleView.hpp"
#include "../../Controllers/ControllerBase.hpp"
#include "MainConsoleView.hpp"
using namespace std;
using namespace C3w::Controllers;

namespace C3w {

namespace Views {

namespace Cli {

/**********************************************************************
【函数名称】 构造函数
【函数功能】 使用控制器与标准输入/输出流初始化 ConsoleViewBase 类型实例。
【参数】
    controller: 控制器指针。
【返回值】 无
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
MainConsoleView::MainConsoleView(shared_ptr<ControllerBase> controller):
    MainConsoleView(controller, cin, cout) {}

/**********************************************************************
【函数名称】 构造函数
【函数功能】 使用控制器与指定输入/输出流初始化 ConsoleViewBase 类型实例。
【参数】
    controller: 控制器指针。
    input: 输入流。
    output: 输出流。
【返回值】 无
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
MainConsoleView::MainConsoleView(
    shared_ptr<ControllerBase> controller, 
    istream& input, 
    ostream& output
): ConsoleViewBase(controller, input, output) {
    m_Prompt = "#> ";
    RegisterCommand(
        "stat", 
        bind(&MainConsoleView::CommandShowStatistics, this), 
        "Display model statistics."
    );
    RegisterCommand(
        "save", 
        bind(&MainConsoleView::CommandSaveModel, this), 
        "Save loaded model."
    );
    RegisterCommand(
        "lines",
        bind(&MainConsoleView::CommandLinesView, this),
        "Enter Line3D context."
    );
    RegisterCommand(
        "faces",
        bind(&MainConsoleView::CommandFacesView, this),
        "Enter Face3D context."
    );
}

/**********************************************************************
【函数名称】 Display
【函数功能】 向用户展示此视图。
【参数】 无
【返回值】 无
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
void MainConsoleView::Display() const {
    auto path = Ask("Enter model path: ", true);
    auto result = static_cast<Result>(m_pController->LoadModel(path));
    if (result != Result::OK) {
        Output << Palette::FG_RED;
        Output << "error: " << ResultToString(result); 
        Output << Palette::CLEAR << endl;
        return;
    }
    Output << Palette::FG_GREEN;
    Output << "Successfully loaded model '" << m_pController->GetName() << "'.";
    Output << Palette::CLEAR << endl;
    ConsoleViewBase::Display();
}

/**********************************************************************
【函数名称】 CommandLinesView
【函数功能】 实现 lines 命令。
【参数】 无
【返回值】
    命令发生的错误。
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
ConsoleViewBase::Result MainConsoleView::CommandLinesView() const {
    LinesConsoleView(m_pController).Display();
    return Result::OK;
}

/**********************************************************************
【函数名称】 CommandFacesView
【函数功能】 实现 faces 命令。
【参数】 无
【返回值】
    命令发生的错误。
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
ConsoleViewBase::Result MainConsoleView::CommandFacesView() const {
    FacesConsoleView(m_pController).Display();
    return Result::OK;
}

/**********************************************************************
【函数名称】 CommandShowStatistics
【函数功能】 实现 stat 命令。
【参数】 无
【返回值】
    命令发生的错误。
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
ConsoleViewBase::Result MainConsoleView::CommandShowStatistics() const {
    auto stat = m_pController->GetStatistics();
    
    Output << Palette::FG_PURPLE << "Statistics:" << Palette::CLEAR << endl;
    Output << Palette::FG_PURPLE << "  Total Point Count:";
    Output << Palette::CLEAR << "\t";
    Output << stat.TotalPointCount << std::endl;
    Output << Palette::FG_PURPLE << "  Total Line Count:";
    Output << Palette::CLEAR << "\t";
    Output << stat.TotalLineCount << std::endl;
    Output << Palette::FG_PURPLE << "  Total Line Length:";
    Output << Palette::CLEAR << "\t";
    Output << stat.TotalLineLength << std::endl;
    Output << Palette::FG_PURPLE << "  Total Face Count:";
    Output << Palette::CLEAR << "\t";
    Output << stat.TotalFaceCount << std::endl;
    Output << Palette::FG_PURPLE << "  Total Face Area:";
    Output << Palette::CLEAR << "\t";
    Output << stat.TotalFaceArea << std::endl;
    Output << Palette::FG_PURPLE << "  Bounding Box Volume:";
    Output << Palette::CLEAR << "\t";
    Output << stat.BoundingBoxVolume << std::endl;

    return Result::OK;
}

/**********************************************************************
【函数名称】 CommandSaveModel
【函数功能】 实现 save 命令。
【参数】 无
【返回值】
    命令发生的错误。
【开发者及日期】 赵一彤 2024/7/24
**********************************************************************/
ConsoleViewBase::Result MainConsoleView::CommandSaveModel() const {
    Output << Palette::FG_GRAY;
    Output << "(Enter nothing to use original file name)";
    Output << Palette::CLEAR << std::endl;
    std::string fileName = Ask("Save to: ", true);
    auto result = static_cast<Result>(m_pController->SaveModel(fileName));
    if (result == Result::OK) {
        Output << Palette::FG_GREEN;
        Output << "Successfully saved model '" << m_pController->GetName();
        Output << "'." << Palette::CLEAR << endl;
    }
    return result;
}

}

}

}