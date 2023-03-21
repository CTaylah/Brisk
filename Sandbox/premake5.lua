project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect  "C++17"

    targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}" 
    location "%{wks.location}/build/%{prj.name}/"

    includedirs 
    {
        "%{wks.location}/Brisk/include/"

    }

    files { "**.h", "**.hpp", "**.c", "**.cpp"}
    
    links {"Brisk"}

