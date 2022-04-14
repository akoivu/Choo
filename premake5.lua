workspace "Choo"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Choo"
	location "Choo"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CHOO_PLATFORM_WINDOWS",
			"CHOO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CHOO_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "CHOO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CHOO_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Choo/vendor/spdlog/include",
		"Choo/src"
	}

	links
	{
		"Choo"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CHOO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHOO_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "CHOO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CHOO_DIST"
		optimize "On"