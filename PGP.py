from Crypto import Random
from Crypto.PublicKey import RSA
from Crypto.Cipher import AES
import base64
import hashlib


BS = 16
# for padding and unpadding raw data before and After encryption and description
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS)
unpad = lambda s: s[:-ord(s[len(s)-1:])]

class AESCipher:
	
	def __init__(self, key):
	
		self.cipher = AES.new(key)
	def encrypt(self, data):
	
		raw = pad(data)
		return base64.b64encode(self.cipher.encrypt(raw))
	def decrypt(self, data):
	
		enc = base64.b64decode(data)
		return unpad(self.cipher.decrypt(enc))

class PGP:

	def __init__(self, own_key, opp_key):
		self.own_key = own_key
		self.opp_key = opp_key

	def encrypt(self, text):
		key = Random.new().read(BS)
		aes = AESCipher(key)
		cipher = self.opp_key.encrypt(key, 32)
		cipher = "".join(cipher)
		md5 = hashlib.md5()
		md5.update(text)
		hash_txt = md5.hexdigest()
		sign_hash_text = self.own_key.sign(hash_txt, 32)
		sign_hash_text = str(sign_hash_text[0])
		sign_len = len(sign_hash_text)
		enc_text = aes.encrypt(text+sign_hash_text+str(sign_len))
		return enc_text + cipher
	
	def decrypt(self, cipher):
		enc_text = cipher[:-128]
		cipher = cipher[-128:]
		key = self.own_key.decrypt(cipher)
		# validate key length
		assert(len(key) == BS)
		aes = AESCipher(key)
		enc_text = aes.decrypt(enc_text)
		sign_len = int(enc_text[-3:])
		enc_text = enc_text[:-3]

		text, sign_hash_text = enc_text[:-sign_len], enc_text[-sign_len:]
		md5 = hashlib.md5()
		md5.update(text)
		is_authenticatd = self.opp_key.verify(md5.hexdigest(), (long(sign_hash_text),))
		if is_authenticatd == False:
			raise ValueError("Msg Signing Failed to authenticate.")
		return text

if __name__=='__main__':
	own_pr_key = RSA.generate(1024, Random.new().read)
	own_pub_key = own_pr_key.publickey()

	opp_pr_key = RSA.generate(1024, Random.new().read)
	opp_pub_key = opp_pr_key.publickey()

	own_pgp = PGP(own_pr_key, opp_pub_key)
	opp_pgp = PGP(opp_pr_key, own_pub_key)

	text = "Hello Friends"
	cipher = own_pgp.encrypt(text)
	decipher = opp_pgp.decrypt(cipher)
	# Checking text is equal to decipher after decrypting
	assert (text == decipher)
