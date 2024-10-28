from cryptography.fernet import Fernet
import base64
import hashlib

# Convierte una clave personalizada en un formato compatible con Fernet (32 bytes, Base64)
def generate_fernet_key(custom_key):
    # Usa SHA-256 para asegurar que la clave sea de 32 bytes
    key = hashlib.sha256(custom_key.encode()).digest()
    return base64.urlsafe_b64encode(key)

# Encripta un mensaje con la clave personalizada usando Fernet
def encrypt_message(key, message):
    fernet = Fernet(key)
    encrypted_message = fernet.encrypt(message.encode())
    return encrypted_message.decode('utf-8')

# Desencripta un mensaje con la clave personalizada usando Fernet
def decrypt_message(key, encrypted_message):
    fernet = Fernet(key)
    decrypted_message = fernet.decrypt(encrypted_message.encode()).decode('utf-8')
    return decrypted_message

# Ejemplo de uso
custom_key = input("Introduce una clave personalizada: ")  # Introduce la clave que deseas
key = generate_fernet_key(custom_key)
print(f"Clave generada (Base64): {key.decode('utf-8')}")

message = "Este es un mensaje secreto"
print(f"Mensaje original: {message}")

# Encripta el mensaje
encrypted_message = encrypt_message(key, message)
print(f"Mensaje encriptado: {encrypted_message}")

# Desencripta el mensaje
decrypted_message = decrypt_message(key, encrypted_message)
print(f"Mensaje desencriptado: {decrypted_message}")