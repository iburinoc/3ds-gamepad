cc_library(
    name = "gamepad",
    srcs = glob([
        "*.cpp",
        "*.h",
    ]),
    copts = [
        "-Iexternal/common/frame",
        "-I/usr/include/libevdev-1.0",
    ],
    linkopts = ["-levdev"],
    visibility = ["//visibility:public"],
    deps = [
        "@common//frame",
    ],
)
