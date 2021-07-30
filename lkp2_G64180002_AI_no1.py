#mahasiswa reguler

def nilai(uts,uas,praktikum,*keaktifan):

	uts *= 0.3
	uas *= 0.35
	praktikum *= 0.3

	i = 0
	rata = 0
	for nil in keaktifan:
		rata += nil
		i += 1

	rata /= i
	rata *= 0.05

	total = uts + uas + praktikum + rata
	print('hasilnya = %f' %total)

nilai(86,78,82,80,81,81)
