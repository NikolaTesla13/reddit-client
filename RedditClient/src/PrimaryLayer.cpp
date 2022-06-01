#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <functional>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "imgui.h"
#include "Walnut/Application.h"
#include "PrimaryLayer.h"

void PrimaryLayer::OnUIRender()
{
	ShowWelcomeScreen();
}

void PrimaryLayer::ShowWelcomeScreen()
{
	ImGui::Begin("Welcome");

	ImGui::Text("Reddit client");

	ImGui::End();

	ImGui::ShowDemoWindow();
}