//Interface Include
#include <ElVis/ElVisGUI/MainWindow.h>

// Automatically generated UI file
#include "ui_mainwindow.h"

#include <ElVis/ElVisCore/Application/Application.h>
#include <ElVis/Core/Timer.h>

namespace ElVis
{

class MainWindowPrivate
{
public:
	Ui::MainWindow m_ui;
};

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
	m_private(new MainWindowPrivate)
{
	m_private->m_ui.setupUi(this);
	this->initialize();

	Core::Application::Instance();
}

MainWindow::~MainWindow()
{
}

// This event is called when the application close has been signaled.
void MainWindow::closeEvent(QCloseEvent* event)
{
}

void MainWindow::initialize()
{
	// redirect the output to the qtextedit window
	m_debug_stream = boost::shared_ptr<DebugStream>(new DebugStream(std::cout, m_private->m_ui.outputTextEdit));
}

}