print ("input :")
angka1 = input("")

#karena input berbentuk string maka harus dikonversi menjadi integer terlebih dahulu
angka1 = int(angka1)
print ("output :")

#jika harganya kurang dari 30000
if angka1 <= 30000:
	print('total harga yang harus dikeluarkan {0}'.format(angka1))
	
#jika harga lebih dari 30000 dan kurang dari 50000
elif angka1 > 30000 and angka1 <= 50000:
	angka2 = angka1*22/100
	angka2 = int(angka2)
	angka1 -= angka2
	print('total harga yang harus dikeluarkan {0}'.format(angka1))

#jika harga lebih dari 50000
else:
	angka2 = angka1*27/100
	angka2 = int(angka2)
	angka1 -= angka2	
	print('total harga yang harus dikeluarkan {0}'.format(angka1))

