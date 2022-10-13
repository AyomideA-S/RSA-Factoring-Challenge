#!/usr/bin/python3
import sys

if len(sys.argv) > 1:
	test = open(sys.argv[1], 'r')

while (n := test.readline().strip()):
	if n != ''and not n:
		break
	n = int(n)
	for i in range(2, n // 2):
		if n % i == 0:
			print("{:d}={:d}*{:d}".format(n, n // i, i))
			break
test.close()
