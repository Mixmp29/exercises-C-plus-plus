def is_prime(val):
  for i in range(2, 10):
    if val % i == 0 and val != i:
      return False
  
  return True

for i in range(0, 1000+1):
  if is_prime(i):
    print(i)