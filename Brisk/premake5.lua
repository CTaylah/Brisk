project "Brisk"
    kind "StaticLib"
    language "C++"
    cppdialect  "C++17"

    targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}" 
    location "%{wks.location}/build/%{prj.name}/"

    includedirs {"include/", "include/glad", "include/glfw", "include/imgui",
                 "src"    
                }

    files {
        "src/**.cpp",
        "src/**.h",
        "src/**.c",
        "vendor/**.c",
        "vendor/**.cpp",
        }

    links {
        --glfw and its dependencies
        "glfw3", "GL", "X11", "Xrandr", "pthread", "Xi",
        "spdlog"
    
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
