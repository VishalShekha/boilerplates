# Q7: MD5 Hashing Algorithm Step-by-Step
# Message: SECURE123
# Initial: A=0x67452301, B=0xEFCDAB89, C=0x98BADCFE, D=0x10325476

import struct

# --- Constants ---
T = [int(abs(__import__('math').sin(i + 1)) * (2**32)) & 0xFFFFFFFF for i in range(64)]

SHIFTS = [
    7,12,17,22, 7,12,17,22, 7,12,17,22, 7,12,17,22,  # Round 1
    5, 9,14,20, 5, 9,14,20, 5, 9,14,20, 5, 9,14,20,  # Round 2
    4,11,16,23, 4,11,16,23, 4,11,16,23, 4,11,16,23,  # Round 3
    6,10,15,21, 6,10,15,21, 6,10,15,21, 6,10,15,21,  # Round 4
]

def left_rotate(x, n):
    return ((x << n) | (x >> (32 - n))) & 0xFFFFFFFF

def md5(message: bytes) -> str:
    # --- Step (a): Message padding and length append ---
    orig_len_bits = len(message) * 8
    message += b'\x80'
    while len(message) % 64 != 56:
        message += b'\x00'
    message += struct.pack('<Q', orig_len_bits)

    print("=== Step (a): Padding ===")
    print(f"Padded message length: {len(message)} bytes ({len(message)*8} bits)")
    print(f"Padded hex (first 64 bytes): {message[:64].hex()}")

    # --- Step (b): Divide into 512-bit blocks ---
    print("\n=== Step (b): 512-bit Blocks ===")
    blocks = [message[i:i+64] for i in range(0, len(message), 64)]
    print(f"Number of 512-bit blocks: {len(blocks)}")

    # --- Initial buffer values ---
    A0 = 0x67452301
    B0 = 0xEFCDAB89
    C0 = 0x98BADCFE
    D0 = 0x10325476

    AA, BB, CC, DD = A0, B0, C0, D0

    # --- Step (c): 4 Rounds ---
    for blk_num, block in enumerate(blocks):
        M = list(struct.unpack('<16I', block))
        a, b, c, d = AA, BB, CC, DD

        print(f"\n=== Step (c): Block {blk_num+1} - 4 Rounds ===")
        print(f"Initial: A={a:08X}  B={b:08X}  C={c:08X}  D={d:08X}")

        for i in range(64):
            if i < 16:
                F = (b & c) | (~b & d)
                g = i
                func_name = "F"
            elif i < 32:
                F = (d & b) | (~d & c)
                g = (5 * i + 1) % 16
                func_name = "G"
            elif i < 48:
                F = b ^ c ^ d
                g = (3 * i + 5) % 16
                func_name = "H"
            else:
                F = c ^ (b | ~d)
                g = (7 * i) % 16
                func_name = "I"

            F &= 0xFFFFFFFF
            temp = (a + F + M[g] + T[i]) & 0xFFFFFFFF
            temp = left_rotate(temp, SHIFTS[i])
            temp = (b + temp) & 0xFFFFFFFF
            a, b, c, d = d, temp, b, c

            if i in [15, 31, 47, 63]:
                rnd = i // 16 + 1
                print(f"  After Round {rnd} ({func_name}): A={a:08X}  B={b:08X}  C={c:08X}  D={d:08X}")

        AA = (AA + a) & 0xFFFFFFFF
        BB = (BB + b) & 0xFFFFFFFF
        CC = (CC + c) & 0xFFFFFFFF
        DD = (DD + d) & 0xFFFFFFFF

    # Final digest (little-endian)
    digest = struct.pack('<4I', AA, BB, CC, DD).hex()
    return digest

# Main
message_str = "SECURE123"
message_bytes = message_str.encode('ascii')

print("MD5 Hashing")
print(f"Message (ASCII): {message_str}")
print(f"Message hex: {message_bytes.hex()}")
print(f"Message bits: {len(message_bytes)*8}\n")

result = md5(message_bytes)
print(f"\n=== Final MD5 Hash ===")
print(f"MD5('{message_str}') = {result}")
