def linearSearch(list, target):
	"""
	Returns the index position of the target if found, else returns None
	"""
	for i in range(0, len(list)):
		if list[i] == target:
			return i
	return None