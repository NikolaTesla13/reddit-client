#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"

#include "ConfigMenu.h"
#include "PrimaryLayer.h"

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Reddit";
	spec.Width = 1280;
	spec.Height = 720;

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<PrimaryLayer>();
	app->SetMenubarCallback([app]() { ConfigMenu::Callback(app); });
	return app;
}