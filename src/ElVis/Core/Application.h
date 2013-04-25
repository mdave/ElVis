#ifndef ELVIS_CORE_APPLICATION_H
#define ELVIS_CORE_APPLICATION_H

#include <boost/shared_ptr.hpp>

#include <ElVis/Core/ElVisDeclspec.h>

namespace ElVis
{

class Application
{
public:
	ELVIS_EXPORT static Application* Instance() { return s_application; }

	// -- Singleton Constructor/Destructor --
private:
	ELVIS_EXPORT Application();
	ELVIS_EXPORT ~Application();

	static Application* s_application;
};

}

#endif