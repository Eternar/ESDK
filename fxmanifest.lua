fx_version "cerulean"
games { "gta5", "rdr3" }
rdr3_warning "I acknowledge that this is a prerelease build of RedM, and I am aware my resources *will* become incompatible once RedM ships."

name "ESDK"
author "Eternar (https://eternar.dev)"
description "Lua SDK for the cfx.re platfrom"
url "https://github.com/Eternar"
version "1.0"

lua54 "yes"
use_experimental_fxv2_oal "yes"

files {
    "Import.lua",

    "Shared/**.lua",
    "Client/**.lua"
}
