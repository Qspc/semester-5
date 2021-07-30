print ("input :")
angka1 = input("")
#setiap input yang masuk dibuat kapital semua
angka1 = angka1.upper()

#jika input merupakan bidikmisi
if angka1 == "BIDIKMISI":
	print ("output " + "Anda mendapatkan golongan UKT 1")
	
#jika input merupakan bukan bidikmisi
elif angka1 == "TIDAK BIDIKMISI":
	angka2 = input("")
	angka2 = int(angka2)
	if angka2 > 10000000:
		print ("output " + "Anda mendapatkan golongan UKT 5")
	elif angka2 <= 10000000 and angka2 > 7000000:
		print ("output " + "Anda mendapatkan golongan UKT 4")
	elif angka2 <= 7000000 and angka2 > 4000000:
		print ("output " + "Anda mendapatkan golongan UKT 3")
	elif angka2 <= 4000000:
		print ("output " + "Anda mendapatkan golongan UKT 2")

#jika input bukan merupakan keduanya
else:
	print ("INPUT TIDAK DITEMUKAN")
