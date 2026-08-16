# Q3: RSA Encryption and Decryption
# p=61, q=53, e=17, message="SECUREMAIL"

import math

def rsa_keygen(p, q, e):
    n = p * q
    phi = (p - 1) * (q - 1)
    assert math.gcd(e, phi) == 1, "e and phi(n) must be coprime"
    d = pow(e, -1, phi)
    return (e, n), (d, n), phi

def rsa_encrypt(plaintext, e, n):
    return [pow(m, e, n) for m in plaintext]

def rsa_decrypt(ciphertext, d, n):
    return [pow(c, d, n) for c in ciphertext]

# Parameters
p, q, e = 61, 53, 17
message = "SECUREMAIL"

# Encode message: A=65, B=66, ...
m_nums = [ord(c) for c in message]

# Key generation
pub_key, priv_key, phi = rsa_keygen(p, q, e)
e_key, n = pub_key
d_key, _ = priv_key

print("=== RSA Key Generation ===")
print(f"p = {p}, q = {q}")
print(f"n = p × q = {n}")
print(f"φ(n) = (p-1)(q-1) = {phi}")
print(f"Public key  (e, n) = ({e_key}, {n})")
print(f"Private key (d, n) = ({d_key}, {n})")

print(f"\n=== Message: '{message}' ===")
print(f"ASCII values: {m_nums}")

# Encrypt
ciphertext = rsa_encrypt(m_nums, e_key, n)
print(f"\n=== Encryption (C = M^e mod n) ===")
for char, m, c in zip(message, m_nums, ciphertext):
    print(f"  '{char}' (M={m:3d}): C = {m}^{e} mod {n} = {c}")

# Decrypt
decrypted = rsa_decrypt(ciphertext, d_key, n)
decrypted_msg = ''.join(chr(m) for m in decrypted)
print(f"\n=== Decryption (M = C^d mod n) ===")
for char, c, m in zip(message, ciphertext, decrypted):
    print(f"  C={c:5d}: M = {c}^{d_key} mod {n} = {m} -> '{chr(m)}'")

print(f"\nOriginal message : {message}")
print(f"Decrypted message: {decrypted_msg}")
print(f"Match: {message == decrypted_msg}")
