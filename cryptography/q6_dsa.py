# Q6: DSA Digital Signature - Create and Verify
# p=23, q=11, g=4, x=3 (private), k=2, Message="AUTH", H(m)=9

p = 23   # large prime
q = 11   # prime divisor of (p-1)
g = 4    # generator
x = 3    # sender's private key
k = 2    # random per-message value
Hm = 9   # H(m) = hash of message "AUTH"
message = "AUTH"

print("=" * 50)
print("DSA Digital Signature")
print("=" * 50)
print(f"Parameters: p={p}, q={q}, g={g}")
print(f"Private key x={x}, per-message k={k}")
print(f"Message='{message}', H(m)={Hm}")

# Public key
y = pow(g, x, p)
print(f"\n[Key Generation]")
print(f"Public key y = g^x mod p = {g}^{x} mod {p} = {y}")

# --- Signature Generation ---
print(f"\n[Signature Generation]")

# r = (g^k mod p) mod q
r = pow(g, k, p) % q
print(f"r = (g^k mod p) mod q = ({g}^{k} mod {p}) mod {q} = {pow(g,k,p)} mod {q} = {r}")

# s = k^-1 * (H(m) + x*r) mod q
k_inv = pow(k, -1, q)
s = (k_inv * (Hm + x * r)) % q
print(f"k^-1 mod q = {k}^-1 mod {q} = {k_inv}")
print(f"s = k^-1 * (H(m) + x*r) mod q")
print(f"s = {k_inv} * ({Hm} + {x}*{r}) mod {q}")
print(f"s = {k_inv} * {Hm + x*r} mod {q} = {(k_inv * (Hm + x*r))} mod {q} = {s}")
print(f"\nSignature: (r={r}, s={s})")

# --- Signature Verification ---
print(f"\n[Signature Verification]")
w = pow(s, -1, q)
print(f"w = s^-1 mod q = {s}^-1 mod {q} = {w}")

u1 = (Hm * w) % q
u2 = (r * w) % q
print(f"u1 = H(m)*w mod q = {Hm}*{w} mod {q} = {u1}")
print(f"u2 = r*w mod q    = {r}*{w} mod {q} = {u2}")

v = (pow(g, u1, p) * pow(y, u2, p)) % p % q
print(f"v = (g^u1 * y^u2 mod p) mod q")
print(f"v = ({g}^{u1} * {y}^{u2} mod {p}) mod {q}")
gu1 = pow(g, u1, p)
yu2 = pow(y, u2, p)
print(f"  = ({gu1} * {yu2} mod {p}) mod {q}")
print(f"  = {(gu1 * yu2) % p} mod {q} = {v}")

print(f"\nv = {v}, r = {r}")
if v == r:
    print("✓ Signature is VALID — v == r")
else:
    print("✗ Signature is INVALID — v != r")
