def binarySearch(list, target):
	"""
	Returns the index position of the target if found, else returns None
	"""
	first = 0
	last = len(list) - 1

	while first <= last:
		midpoint = (first + last) // 2

		if list[midpoint] == target:
			return midpoint
		elif list[midpoint] > target:
			last = midpoint - 1
		elif list[midpoint] < target:
			first = midpoint + 1