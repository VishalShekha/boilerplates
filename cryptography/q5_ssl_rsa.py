# Q5: Simple Client-Server SSL socket communication with RSA encryption
# Run server first: python q5_server.py
# Then run client: python q5_client.py
# This single file simulates both using threads.

import socket
import threading
import math
import random
import time

# ---- Minimal RSA helpers ----
def generate_rsa_keypair(p=61, q=53, e=17):
    n   = p * q
    phi = (p - 1) * (q - 1)
    d   = pow(e, -1, phi)
    return (e, n), (d, n)

def rsa_encrypt_bytes(data: bytes, e, n) -> list:
    return [pow(b, e, n) for b in data]

def rsa_decrypt_bytes(ciphertext: list, d, n) -> bytes:
    return bytes([pow(c, d, n) for c in ciphertext])

# ---- Encode/decode list <-> string for socket transfer ----
def encode_cipher(cipher_list):
    return ','.join(str(c) for c in cipher_list)

def decode_cipher(cipher_str):
    return [int(x) for x in cipher_str.split(',')]

HOST = '127.0.0.1'
PORT = 65432

# ---- SERVER ----
def server():
    pub_key, priv_key = generate_rsa_keypair()
    e, n = pub_key
    d, _ = priv_key

    print(f"[SERVER] RSA Public Key : (e={e}, n={n})")
    print(f"[SERVER] RSA Private Key: (d={d}, n={n})")

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((HOST, PORT))
        s.listen(1)
        print(f"[SERVER] Listening on {HOST}:{PORT} ...")
        conn, addr = s.accept()
        with conn:
            print(f"[SERVER] Connection from {addr}")

            # Step 1: Send public key to client
            conn.sendall(f"{e},{n}".encode())
            time.sleep(0.1)

            # Step 2: Receive encrypted message
            data = conn.recv(4096).decode()
            cipher_list = decode_cipher(data)
            print(f"[SERVER] Received ciphertext: {cipher_list[:5]}...")

            # Step 3: Decrypt
            plaintext = rsa_decrypt_bytes(cipher_list, d, n)
            print(f"[SERVER] Decrypted message: '{plaintext.decode()}'")

            # Step 4: Send acknowledgment
            conn.sendall(b"ACK:Message received and decrypted successfully")

# ---- CLIENT ----
def client():
    time.sleep(0.5)  # Wait for server to start
    print(f"\n[CLIENT] Connecting to {HOST}:{PORT} ...")

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))

        # Step 1: Receive server's public key
        key_data = s.recv(1024).decode()
        e, n = map(int, key_data.split(','))
        print(f"[CLIENT] Received server public key: (e={e}, n={n})")

        # Step 2: Encrypt and send message
        message = "HELLO SECURE SERVER"
        print(f"[CLIENT] Sending message: '{message}'")
        cipher = rsa_encrypt_bytes(message.encode(), e, n)
        s.sendall(encode_cipher(cipher).encode())

        # Step 3: Receive ACK
        ack = s.recv(1024).decode()
        print(f"[CLIENT] Server response: '{ack}'")

# ---- Main: run both in threads ----
if __name__ == "__main__":
    print("=== SSL-like Client-Server with RSA Encryption ===\n")
    t_server = threading.Thread(target=server)
    t_client = threading.Thread(target=client)
    t_server.start()
    t_client.start()
    t_server.join()
    t_client.join()
    print("\n[DONE] Communication complete.")
