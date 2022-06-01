-- premake5.lua
workspace "RedditClient"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "RedditClient"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "RedditClient"