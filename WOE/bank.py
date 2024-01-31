def bank(price, year):
  for i in range(1, year+1):
    price += price * 0.1
  
  return price

a = 50000
year = 3

print(bank(a, year))