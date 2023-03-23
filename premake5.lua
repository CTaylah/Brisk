workspace "Brisk"
    configurations { "Debug", "Release" }
    libdirs {"Brisk/vendor/**"}
    includedirs {"Brisk/src"} 

    -- filter{ "configurations:Debug" }
    --   buildoptions {"-g"}

  --  buildoptions { "-fPIE" }

include "Brisk"
include "Sandbox"