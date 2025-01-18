x = input("Enter your query : ")
l = ['red', 'white', 'blue', 1, 2, 3]
l = [str(x) for x in l]
if x in l:
	print('Yes')
else:
	print('No')