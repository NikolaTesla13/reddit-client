#pragma once

class ConfigMenu
{
public:
	static void Callback(Walnut::Application* app);

	static const std::vector<std::string> popularSubreddits;
	static char searchSubreddit[1024];
	static std::unordered_map<std::string, bool> options;
};
