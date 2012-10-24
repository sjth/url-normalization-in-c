solution "main"
configurations {"Debug","Release"}

project "main"
kind "ConsoleApp"
language "C++"

files {
   "main.cpp",
   "cleanurl.c",
      }

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }
