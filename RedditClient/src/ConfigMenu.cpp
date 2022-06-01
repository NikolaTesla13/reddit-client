#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>

#include "imgui.h"
#include "Walnut/Application.h"
#include "ConfigMenu.h"

const std::vector<std::string> ConfigMenu::popularSubreddits = { "r/news", "r/holup", "r/memes", "r/Damnthatsinteresting", "r/nextfuckinglevel" };
char ConfigMenu::searchSubreddit[1024] = "\0";
std::unordered_map<std::string, bool> ConfigMenu::options = {
	{"showSpoilers", false},
	{"showNSFW", false},
	{"isCompactView", true},
	{"hideUpvotes", false},
	{"showRewards", false},
	{"autoplay", true},
};

void ConfigMenu::Callback(Walnut::Application* app)
{
	if (ImGui::BeginMenu("File"))
	{
		ImGui::MenuItem("About");
		ImGui::MenuItem("Open Source licenses");
		if (ImGui::MenuItem("Exit"))
		{
			app->Close();
		}
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Subreddits"))
	{
		ImGui::Text("Popular");
		ImGui::Separator();

		for (auto subreddit : popularSubreddits)
		{
			ImGui::MenuItem(subreddit.c_str());
		}

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::Text("Search:");
		ImGui::SameLine();
		ImGui::InputText(" ", searchSubreddit, 1024);
		if(ImGui::Button("Submit")) {
			std::cout << searchSubreddit << '\n';
		}

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Sort By"))
	{
		ImGui::MenuItem("New");
		ImGui::MenuItem("Hot");
		ImGui::MenuItem("Top");
		ImGui::MenuItem("Rising");

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Filter"))
	{
		ImGui::Checkbox("Show spoilers", &options["showSpoilers"]);
		ImGui::Checkbox("Show NSFW", &options["showNSFW"]);

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::Checkbox("Compact view", &options["isCompactView"]);
		ImGui::Checkbox("Hide upvotes", &options["hideUpvotes"]);
		ImGui::Checkbox("Show rewards", &options["showRewards"]);
		ImGui::Checkbox("Autoplay videos", &options["autoplay"]);

		ImGui::EndMenu();
	}

}