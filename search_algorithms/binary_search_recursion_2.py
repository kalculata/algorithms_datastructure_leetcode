def binarySearch(list, target):
  """
	Returns the index position of the target if found, else returns None
	"""
  if len(list) == 0:
    return False
  else:
    midpoint = len(list) // 2
    
    if list[midpoint] == target:
      return True
    elif list[midpoint] > target:
      return binarySearch(list[:midpoint], target)
    elif list[midpoint] < target:
      return binarySearch(list[midpoint+1:], target)
		