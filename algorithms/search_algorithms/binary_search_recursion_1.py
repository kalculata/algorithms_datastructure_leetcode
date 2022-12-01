def binarySearch(list, target, first, last):
  """
	Returns the index position of the target if found, else returns None
	"""
  if len(list) == 0:
    return None
  
  midpoint = (first + last) // 2
  
  if list[midpoint] == target:
    return midpoint
  elif list[midpoint] > target:
    return binarySearch(list, target, first, midpoint - 1)
  elif list[midpoint] < target:
    return binarySearch(list, target, midpoint + 1, last)
  
  return None
		