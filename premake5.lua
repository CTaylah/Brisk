workspace "Brisk"
    configurations { "Debug", "Release" }
    libdirs {"Brisk/vendor/**"}
    includedirs {"Brisk/src"} 
    architecture "x86_64"

    filter "system:linux"
        links {"GL", "X11", "Xrandr", "pthread", "Xi"}
 

   

include "Brisk"
include "Sandbox"