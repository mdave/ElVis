#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Boost includes
#include <boost/shared_ptr.hpp>

// cout redirect helper include
#include <ElVis/Gui/DebugStream.h>

namespace ElVis
{
class MainWindowPrivate;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = 0);
	~MainWindow();

private:
	void initialize();
	virtual void closeEvent (QCloseEvent* event);

	boost::shared_ptr< MainWindowPrivate > m_private;
	boost::shared_ptr< DebugStream > m_debug_stream;
};

}// end namespace ElVis
#endif // MAINWINDOW_H
