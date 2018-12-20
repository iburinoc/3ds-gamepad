cc_library(
    name = "gamepad",
    srcs = glob([
        "*.cpp",
        "*.h",
    ]),
    copts = [
        "-Iexternal/common/frame",
    ],
    linkopts = ["-DEFAULTLIB:ws2_32.lib"],
    visibility = ["//visibility:public"],
    deps = [
        "@common//frame",
        "//vjoy",
    ],
)