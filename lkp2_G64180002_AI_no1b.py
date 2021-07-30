#mahasiswa alih jenis

def nilai(uts,uas,praktikum,*keaktifan,**matrik):

	uts *= 0.25
	uas *= 0.25
	praktikum *= 0.2

	i = 0
	j = 0
	rata = 0
	rata2 = 0
	for nil in keaktifan:
		rata += nil
		i += 1

	rata /= i
	rata *= 0.05

	for mat in matrik:
		rata2 += matrik[mat]
	
	rata2 *= 0.25
	
	total = uts + uas + praktikum + rata + rata2
	print('hasilnya = %f' %total)

nilai(77,65,88,75,81,80,matrik=82)
