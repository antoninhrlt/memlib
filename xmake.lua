-- This file is part of "memlib"
-- Under the MIT License
-- Copyright (c) 2022 Antonin Hérault

add_rules("mode.debug", "mode.release")

add_includedirs("inc/")

target("memlib")
    set_kind("shared")
    add_files("src/*.c")
    
    if is_mode("debug") then
        add_defines("DEBUG")
    else
        add_cflags("-nostdlib")
    end

-- Command : `xmake build test && xmake run test`
target("test")
    set_kind("binary")
    add_files("tests/<test_you_want>.c") -- to change locally, never remotely
    add_deps("memlib")
