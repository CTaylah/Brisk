project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect  "C++17"

    targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}" 
    location "%{wks.location}/build/%{prj.name}/"

    includedirs 
    {
        "%{wks.location}/Brisk/include/",
        "%{wks.location}/Brisk/include/glad/",
        "%{wks.location}/Brisk/include/glfw/"

    }

    files { "**.h", "**.hpp", "**.c", "**.cpp"}
    

    links {
        "Brisk", 
        --glfw and its dependencies
        "glfw3", "GL", "X11", "Xrandr", "pthread", "Xi",
        "spdlog",
    
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"



