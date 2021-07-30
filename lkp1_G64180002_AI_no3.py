print ("input :")
berat = input("")
#format input dibuat integer terlebih dahulu
berat = int(berat)
#format input dibuat float terlebih dahulu
tinggi = input("")
tinggi = float(tinggi)
#tinggi dibuat dalam satuan meter
tinggi /= 100
jumlah = float(berat/(tinggi*tinggi))

print ("output :")
if jumlah < 18.5:
	print ("Below Normal height")
elif jumlah >= 18.5 and jumlah < 25:
	print ("Normal Weight")
elif jumlah >= 25 and jumlah < 30:
	print ("overweight")
elif jumlah >= 30 and jumlah < 35:
	print ("Class I Obesity")
elif jumlah >= 35 and jumlah < 40:
	print ("Class II Obesity")
elif jumlah >= 40:
	print ("Class III Obesity")

#soal No A = Normal Weight
#Soal No B = overweight
#Soal No C = Class I Obesity
#Soal No D = Below Normal Height


