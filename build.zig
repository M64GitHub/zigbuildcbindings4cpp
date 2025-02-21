// build.zig
const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Step 1: Create shared library from C++ SID code and wrapper
    const sid_lib = b.addSharedLibrary(.{
        .name = "sid",
        .target = target,
        .optimize = optimize,
    });
    sid_lib.linkLibCpp();
    sid_lib.addIncludePath(b.path("."));
    sid_lib.addCSourceFiles(.{
        .files = &.{
            "sid.cpp",
            "sid_wrapper.cpp",
        },
        .flags = &.{ "-x", "c++", "-std=c++17" },
    });

    // Step 2: Build the Zig executable and link with SID library
    const exe = b.addExecutable(.{
        .name = "zig_sid_demo",
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
    });
    exe.linkLibrary(sid_lib);
    exe.linkSystemLibrary("stdc++");
    exe.addIncludePath(b.path("."));

    b.installArtifact(exe);

    // Step 3: Run step
    const run_cmd = b.addRunArtifact(exe);
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the Zig SID demo");
    run_step.dependOn(&run_cmd.step);
}
