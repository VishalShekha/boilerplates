# Q4: Diffie-Hellman Key Exchange + Man-in-the-Middle Attack
# q=41, alpha=6, XA=9, XB=17, XM1=7 (towards Bala), XM2=12 (towards Arun)

q     = 41   # prime
alpha = 6    # primitive root
XA    = 9    # Arun's private key
XB    = 17   # Bala's private key
XM1   = 7    # Kiran's private key towards Bala
XM2   = 12   # Kiran's private key towards Arun

print("=" * 50)
print("Diffie-Hellman Key Exchange")
print(f"Prime q={q}, Primitive root α={alpha}")
print("=" * 50)

# Normal DH (no attack)
YA = pow(alpha, XA, q)
YB = pow(alpha, XB, q)

print(f"\n[Normal Exchange]")
print(f"Arun's public key  YA = α^XA mod q = {alpha}^{XA} mod {q} = {YA}")
print(f"Bala's public key  YB = α^XB mod q = {alpha}^{XB} mod {q} = {YB}")

K_Arun = pow(YB, XA, q)
K_Bala = pow(YA, XB, q)
print(f"\nShared secret (Arun computes) = YB^XA mod q = {YB}^{XA} mod {q} = {K_Arun}")
print(f"Shared secret (Bala computes) = YA^XB mod q = {YA}^{XB} mod {q} = {K_Bala}")
print(f"Shared secret key = {K_Arun}")

# Man-in-the-Middle attack
print("\n" + "=" * 50)
print("Man-in-the-Middle Attack by Kiran")
print("=" * 50)

YM1 = pow(alpha, XM1, q)  # Kiran's public key towards Bala
YM2 = pow(alpha, XM2, q)  # Kiran's public key towards Arun

print(f"\nKiran's public key YM1 (towards Bala) = α^XM1 mod q = {alpha}^{XM1} mod {q} = {YM1}")
print(f"Kiran's public key YM2 (towards Arun) = α^XM2 mod q = {alpha}^{XM2} mod {q} = {YM2}")

# Arun <-> Kiran shared key
K_Arun_Kiran = pow(YM2, XA, q)   # Arun computes with Kiran's fake key
K_Kiran_Arun = pow(YA,  XM2, q)  # Kiran computes with Arun's real key

print(f"\n[Arun ↔ Kiran]")
print(f"Arun computes  = YM2^XA  mod q = {YM2}^{XA} mod {q}  = {K_Arun_Kiran}")
print(f"Kiran computes = YA^XM2  mod q = {YA}^{XM2} mod {q} = {K_Kiran_Arun}")
print(f"Shared key (Arun & Kiran) = {K_Arun_Kiran}")

# Bala <-> Kiran shared key
K_Bala_Kiran = pow(YM1, XB, q)   # Bala computes with Kiran's fake key
K_Kiran_Bala = pow(YB,  XM1, q)  # Kiran computes with Bala's real key

print(f"\n[Bala ↔ Kiran]")
print(f"Bala computes  = YM1^XB  mod q = {YM1}^{XB} mod {q}  = {K_Bala_Kiran}")
print(f"Kiran computes = YB^XM1  mod q = {YB}^{XM1} mod {q} = {K_Kiran_Bala}")
print(f"Shared key (Bala & Kiran) = {K_Bala_Kiran}")

print(f"\n[Summary]")
print(f"Normal shared key (Arun & Bala): {K_Arun}")
print(f"MITM - Key between Arun & Kiran: {K_Arun_Kiran}")
print(f"MITM - Key between Bala & Kiran: {K_Bala_Kiran}")
