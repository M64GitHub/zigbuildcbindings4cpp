const std = @import("std");
const c = @cImport({
    @cInclude("sid_wrapper.h");
});

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();

    const sid = c.SID_create("MyZigSID");
    if (sid == null) {
        try stdout.print("Failed to create SID instance.\\n", .{});
        return;
    }

    const name = c.SID_getName(sid.?);
    try stdout.print("SID instance name: {s}\\n", .{name});

    c.SID_playNote(sid.?, 42);
    c.SID_destroy(sid.?);
}
