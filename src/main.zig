const std = @import("std");

const SID = opaque {}; // Opaque type for SID from C

// Import C functions from the wrapper (using ?*SID for nullable pointers)
extern fn SID_create(name: [*:0]const u8) ?*SID;
extern fn SID_destroy(sid: *SID) void;
extern fn SID_playNote(sid: *SID, note: c_int) void;
extern fn SID_getName(sid: *SID) [*:0]const u8;

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();

    // Create SID instance (nullable check)
    const sid = SID_create("MyZigSID");
    if (sid == null) {
        try stdout.print("Failed to create SID instance.\\n", .{});
        return;
    }

    // Get name
    const name = SID_getName(sid.?); // Use sid.? to dereference safely
    try stdout.print("SID instance name: {s}\\n", .{name});

    // Play a note
    SID_playNote(sid.?, 42);

    // Destroy SID instance
    SID_destroy(sid.?);
}
