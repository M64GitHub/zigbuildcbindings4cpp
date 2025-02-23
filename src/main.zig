const std = @import("std");
const c = @cImport({
    @cInclude("resid_wrapper.h");
});

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();

    const resid = c.ReSID_create("MyZIGSID");
    if (resid == null) {
        try stdout.print("Failed to create SID instance.\n", .{});
        return;
    }

    c.ReSID_setDBGOutput(resid, true);
    _ = c.ReSID_setChipModel(resid, "MOS6581");

    const name = c.ReSID_getName(resid);
    try stdout.print("SID instance name: {s}\n", .{name});

    c.ReSID_destroy(resid);
}
