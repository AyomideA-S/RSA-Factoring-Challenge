#!/usr/bin/python3
import sys
import math

def isPrime(x):
	if x <= 1:
		return 0
	primes = [2, 3]
	if x in [2, 3]:
		return (1)
	elif x % 2 == 0:
		return (0)
	for i in range(5, (x // 2) + 1, 2):
		if math.sqrt(i) not in primes:
			for n in range(1, len(primes)):
				if i % primes[n] == 0:
					break
				if n == len(primes) - 1:
					primes.append(i)
	if math.sqrt(x) in primes:
		return (0)
	return next((0 for n in primes if x % n == 0), 1)

def isprime(x):
	if x <= 1:
		return 0
	if x in [2, 3]:
		return (1)
	if x % 2 == 0 or x % 3 == 0:
		return (0)
	for i in range(5, int(math.sqrt(x)) + 1):
		if x % i == 0 or x % (i + 2) == 0:
			return (0)
		i += 6
	return (1)

if len(sys.argv) > 1:
	with open(sys.argv[1], 'r') as rsa:
		while (n := rsa.readline().strip()):
			if n != ''and not n:
				break
			n = int(n)
			for i in range(2, int(math.sqrt(n)) + 1):
				if n % i == 0:
					p = n // i
					q = i
					if isprime(p) and isprime(q):
						print("{:d}={:d}*{:d}".format(n, p, q))
						break
