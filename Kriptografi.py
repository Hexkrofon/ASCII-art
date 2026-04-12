def _normalize_key(text: str, key: str) -> str:
	"""Extend the key to match the length of the text letters only."""
	filtered_key = [c for c in key if c.isalpha()]
	if not filtered_key:
		raise ValueError("Kunci harus berisi setidaknya satu huruf.")

	normalized = []
	key_index = 0
	key_len = len(filtered_key)

	for char in text:
		if char.isalpha():
			normalized.append(filtered_key[key_index % key_len])
			key_index += 1
		else:
			normalized.append(char)

	return "".join(normalized)


def _shift_char(char: str, key_char: str, encrypt: bool = True) -> str:
	"""Shift a single alphabetic character by the key character."""
	if not char.isalpha():
		return char

	base = ord("A") if char.isupper() else ord("a")
	shift_base = ord("A") if key_char.isupper() else ord("a")
	shift = ord(key_char) - shift_base
	if not encrypt:
		shift = -shift

	return chr((ord(char) - base + shift) % 26 + base)


def encrypt_vigenere(plaintext: str, key: str) -> str:
	"""Encrypt text using the Vigenere cipher."""
	extended_key = _normalize_key(plaintext, key)
	result = []
	for p_char, k_char in zip(plaintext, extended_key):
		result.append(_shift_char(p_char, k_char, encrypt=True))
	return "".join(result)


def decrypt_vigenere(ciphertext: str, key: str) -> str:
	"""Decrypt text using the Vigenere cipher."""
	extended_key = _normalize_key(ciphertext, key)
	result = []
	for c_char, k_char in zip(ciphertext, extended_key):
		result.append(_shift_char(c_char, k_char, encrypt=False))
	return "".join(result)


def main() -> None:
	print("=== Program Vigenere Cipher ===")
	print("1. Enkripsi")
	print("2. Deskripsi")
	print("3. Keluar")
	pilihan = input("Pilih menu (1/2/3): ").strip()

	if pilihan == "1":
		teks = input("Masukkan teks asli: ")
		kunci = input("Masukkan kunci: ")
		try:
			hasil = encrypt_vigenere(teks, kunci)
			print(f"Hasil Enkripsi: {hasil}")
		except ValueError as err:
			print(f"Error: {err}")
	elif pilihan == "2":
		teks = input("Masukkan teks terenkripsi: ")
		kunci = input("Masukkan kunci: ")
		try:
			hasil = decrypt_vigenere(teks, kunci)
			print(f"Hasil Deskripsi: {hasil}")
		except ValueError as err:
			print(f"Error: {err}")
	elif pilihan == "3":
		print("Keluar dari program.")
	else:
		print("Pilihan tidak valid. Jalankan kembali program dan pilih 1, 2, atau 3.")


if __name__ == "__main__":
	main()
