#include <ElVis/ElVisCore/Application/Application.h>

namespace Core
{
	Application* Application::s_instance = new Application();


	Application::Application()
	{
		Initialize();
	}

	Application::~Application()
	{

	}

	void Application::Initialize()
	{
		
	}

}