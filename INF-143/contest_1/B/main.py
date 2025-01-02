def combinationUtil(arr, n, r, index, data, i):

	if index == r:
		for j in range(r):
			print(chr(data[j]), end = "")
		print()
		return

	if i >= n:
		return

	data[index] = arr[i]
	combinationUtil(arr, n, r, index + 1, data, i + 1)
	combinationUtil(arr, n, r, index, data, i + 1)

def printcombination(arr, n, r):

	data = list(range(r))

	combinationUtil(arr, n, r, 0, data, 0)

n, k = map(int, input().split())

arr = list()


for i in range(97, n + 97):
	arr.append(i)

printcombination(arr, n, k)