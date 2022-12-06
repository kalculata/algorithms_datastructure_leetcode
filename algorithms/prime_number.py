def is_prime(x):
  if x == 1:
    return False
  
  i = 2
  while i*i <= x:
    if x % i == 0:
      return False
    i += 1
  return True

def get_primes(a, b):
  N = b
  i = 2

  primes = [1]*N
  primes[0] = 0
  primes[1] = 0

  while i*i <= N:
    if primes[i] == 0:
      i += 1
      continue

    j=2*i
    while j < N:
      primes[j] = 0
      j += i
    i += 1
  
  results = []
  for i in range(1, N):
    if primes[i] == 1:
      results.append(i)
  
  first = 0
  last  = len(results)

  while first <= last:
    midpoint = (first + last) // 2

    if results[midpoint] < a:
      first = midpoint + 1
    elif results[midpoint] > a:
      last = midpoint - 1 
  
  return results[midpoint:]

print(get_primes(800000, 1000000))

