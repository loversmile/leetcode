def spiralOrder(matrix):
		res = []
		while matrix:
			res += matrix.pop(0)
			print matrix
			matrix = list(zip(*matrix))[::-1]
			print matrix
		return res


lis = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
a = [1,2,3,4]
b = [5,6,7,8]
c = [9,10,11,12]
zipp = zip(a,b,c)
print zipp
print zip(*zipp)
spiralOrder(lis)
