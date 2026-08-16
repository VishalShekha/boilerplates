# Q1: Simplified DES (S-DES) Encryption and Decryption
# Plaintext: 11010111, K1: 01101100, K2: 11010010

# Permutation tables (1-indexed, converted to 0-indexed)
IP   = [1, 5, 2, 0, 3, 7, 4, 6]   # IP  = (2 6 3 1 4 8 5 7)
IP_INV = [3, 0, 2, 4, 6, 1, 7, 5] # IP-1= (4 1 3 5 7 2 8 6)
EP   = [3, 0, 1, 2, 1, 2, 3, 0]   # EP  = (4 1 2 3 2 3 4 1)
P4   = [1, 3, 2, 0]               # P4  = (2 4 3 1)

S0 = [[1,0,3,2],[3,2,1,0],[0,2,1,3],[3,1,3,2]]
S1 = [[0,1,2,3],[2,0,1,3],[3,0,1,0],[2,1,0,3]]

def permute(bits, table):
    return [bits[i] for i in table]

def xor(a, b):
    return [x ^ y for x, y in zip(a, b)]

def sbox_lookup(bits4, sbox):
    row = (bits4[0] << 1) | bits4[3]
    col = (bits4[1] << 1) | bits4[2]
    val = sbox[row][col]
    return [(val >> 1) & 1, val & 1]

def fk(bits8, subkey):
    L, R = bits8[:4], bits8[4:]
    expanded = permute(R, EP)            # Expand R to 8 bits
    xored = xor(expanded, subkey)        # XOR with subkey
    left4, right4 = xored[:4], xored[4:]
    s0out = sbox_lookup(left4, S0)
    s1out = sbox_lookup(right4, S1)
    p4out = permute(s0out + s1out, P4)
    new_L = xor(L, p4out)
    return new_L + R

def sw(bits8):
    return bits8[4:] + bits8[:4]

def str_to_bits(s):
    return [int(c) for c in s]

def bits_to_str(bits):
    return ''.join(str(b) for b in bits)

def sdes_encrypt(plaintext_bits, k1, k2):
    print("=== ENCRYPTION ===")
    after_ip = permute(plaintext_bits, IP)
    print(f"After IP:      {bits_to_str(after_ip)}")
    after_fk1 = fk(after_ip, k1)
    print(f"After fK1:     {bits_to_str(after_fk1)}")
    after_sw = sw(after_fk1)
    print(f"After SW:      {bits_to_str(after_sw)}")
    after_fk2 = fk(after_sw, k2)
    print(f"After fK2:     {bits_to_str(after_fk2)}")
    ciphertext = permute(after_fk2, IP_INV)
    print(f"Ciphertext:    {bits_to_str(ciphertext)}")
    return ciphertext

def sdes_decrypt(ciphertext_bits, k1, k2):
    print("\n=== DECRYPTION (use K2 then K1) ===")
    after_ip = permute(ciphertext_bits, IP)
    print(f"After IP:      {bits_to_str(after_ip)}")
    after_fk2 = fk(after_ip, k2)
    print(f"After fK2:     {bits_to_str(after_fk2)}")
    after_sw = sw(after_fk2)
    print(f"After SW:      {bits_to_str(after_sw)}")
    after_fk1 = fk(after_sw, k1)
    print(f"After fK1:     {bits_to_str(after_fk1)}")
    plaintext = permute(after_fk1, IP_INV)
    print(f"Plaintext:     {bits_to_str(plaintext)}")
    return plaintext

# Input
plaintext = str_to_bits("11010111")
K1        = str_to_bits("01101100")
K2        = str_to_bits("11010010")

print(f"Plaintext: {bits_to_str(plaintext)}")
print(f"K1:        {bits_to_str(K1)}")
print(f"K2:        {bits_to_str(K2)}\n")

ciphertext = sdes_encrypt(plaintext, K1, K2)
decrypted  = sdes_decrypt(ciphertext, K1, K2)

print(f"\nOriginal plaintext : {bits_to_str(plaintext)}")
print(f"Encrypted ciphertext: {bits_to_str(ciphertext)}")
print(f"Decrypted plaintext : {bits_to_str(decrypted)}")
