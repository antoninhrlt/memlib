-- This file is part of "memlib"
-- Under the MIT License
-- Copyright (c) 2022 Antonin Hérault

add_rules("mode.debug", "mode.release")

target("memlib")
    set_kind("shared")
    add_files("src/*.c")
    if is_mode("debug") then
        add_defines("DEBUG")
    end
