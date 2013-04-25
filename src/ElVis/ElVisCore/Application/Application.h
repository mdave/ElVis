#ifndef ELVIS_CORE_APPLICATION_H
#define ELVIS_CORE_APPLICATION_H

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/function.hpp>

#include <queue>

#include <ElVis/ElVisCore/EventHandler/EventHandler.h>

namespace Core
{

class Application : public EventHandler, public boost::noncopyable
{
public:
	static Application* Instance() { return s_instance; }

private:
	Application();
	~Application();

	void Initialize();

	boost::mutex m_instance_mutex;
	static Application* s_instance;
};

}

#endif