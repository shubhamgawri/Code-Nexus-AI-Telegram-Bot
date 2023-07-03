def Merge(dict_1, dict_2):
	result = dict_1 | dict_2
	return result
	
# Driver code
dict_1 = {'Shubham': 15, 'Sahil': 10, 'Riya' : 12 }
dict_2 = {'Rohit': 18,'Pratham': 20,'Mahesh' : 16 , 'Krish': 11}
dict_3 = Merge(dict_1, dict_2)
print(dict_3)