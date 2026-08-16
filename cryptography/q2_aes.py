# Q2: AES ShiftRows and MixColumns - find position (4,2)
# Plaintext: 87EC4A8CF26EC3D84D4C46959790E7A6

def hex_to_state(hex_str):
    """Convert 32-char hex string to 4x4 state matrix (column-major)."""
    bytes_list = [int(hex_str[i:i+2], 16) for i in range(0, 32, 2)]
    state = [[0]*4 for _ in range(4)]
    for col in range(4):
        for row in range(4):
            state[row][col] = bytes_list[col*4 + row]
    return state

def print_state(state, label):
    print(f"\n{label}:")
    print("     Col0  Col1  Col2  Col3")
    for r in range(4):
        row_hex = '  '.join(f'{state[r][c]:02X}' for c in range(4))
        print(f"Row{r+1}:  {row_hex}")

def shift_rows(state):
    new_state = [row[:] for row in state]
    for r in range(1, 4):
        new_state[r] = state[r][r:] + state[r][:r]
    return new_state

def gmul(a, b):
    """Galois Field (2^8) multiplication."""
    p = 0
    for _ in range(8):
        if b & 1:
            p ^= a
        high = a & 0x80
        a = (a << 1) & 0xFF
        if high:
            a ^= 0x1B
        b >>= 1
    return p

def mix_single_column(col):
    s0, s1, s2, s3 = col
    r0 = gmul(0x02, s0) ^ gmul(0x03, s1) ^ s2 ^ s3
    r1 = s0 ^ gmul(0x02, s1) ^ gmul(0x03, s2) ^ s3
    r2 = s0 ^ s1 ^ gmul(0x02, s2) ^ gmul(0x03, s3)
    r3 = gmul(0x03, s0) ^ s1 ^ s2 ^ gmul(0x02, s3)
    return [r0, r1, r2, r3]

def mix_columns(state):
    new_state = [[0]*4 for _ in range(4)]
    for c in range(4):
        col = [state[r][c] for r in range(4)]
        mixed = mix_single_column(col)
        for r in range(4):
            new_state[r][c] = mixed[r]
    return new_state

# Main
plaintext_hex = "87EC4A8CF26EC3D84D4C46959790E7A6"
state = hex_to_state(plaintext_hex)

print("AES ShiftRows and MixColumns")
print(f"Plaintext: {plaintext_hex}")
print_state(state, "Initial State")

after_shift = shift_rows(state)
print_state(after_shift, "After ShiftRows")

after_mix = mix_columns(after_shift)
print_state(after_mix, "After MixColumns")

# Position (4,2) means row 4, col 2 -> index [3][1]
val = after_mix[3][1]
print(f"\nPosition (4,2) [row=4, col=2] after MixColumns: {val:02X}")
