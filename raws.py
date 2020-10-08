from time import clock
from random import randint
NUMBER_ALGOS = 3
LIST_SIZE = 200


def time_fn(to_call,param):
	start = clock()
	result = to_call(param)
	d_time = clock()-start;
	return d_time,result

def areEqual(a,b):
	return True if a==b else False

def run_test(to_test,test_with):
	time,value = time_fn(to_test,test_with)
	return [time,"OK"] if value==t_sorted else [time,"FAIL"]

def isort(to_sort):
	i=0
	while i <= len(to_sort)-1:
		hole = i;
		item = to_sort[i]
		while hole > 0 and to_sort[hole-1]  > item:
			to_sort[hole] = to_sort[hole-1]
			hole-=1
		to_sort[hole] = item
		i+=1
	return to_sort

def selection_sort(to_sort):
	i = 0
	while i< len(to_sort):
		lowest = i
		item = to_sort[lowest]
		j=i+1
		while j < len(to_sort):
			if item > to_sort[j]:
				lowest = j
				item = to_sort[j]
			j+=1

		if lowest != i:
			to_sort[j],to_sort[i] = to_sort[i],lowest
		i+=1
	return to_sort

"""
Simple implementation of Shell sort using Ciura gaps
to_sort - list of numbers to be sorted
"""
def shell_sort(to_sort):
	gaps = [701,301,132,57,23,10,4,1]
	for gap in gaps:
		i = gap
		while i <= len(to_sort)-1:
			hole = to_sort[i]
			j = i
			while j>=gap and to_sort[j-gap] > hole:
				to_sort[j] = to_sort[j-gap]
				j-=gap
			to_sort[j] = hole
			i+=gap
	return to_sort

print("Testing ", NUMBER_ALGOS, " sorting algorithms with a ", LIST_SIZE, " element list...",sep="")
print("Generating and sorting test values...")
test = [randint(-100,100) for i in range(LIST_SIZE)]
t_sorted = shell_sort(test)
#The tests
print("Insertion sort: ", run_test(isort,test), sep="")
