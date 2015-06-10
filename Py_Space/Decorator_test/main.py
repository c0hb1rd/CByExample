maxi = lambda x, y: x if x > y else y
num1, num2 = 0, 0

num1 = raw_input('Enter the num1: ')
num2 = raw_input('Enter the num2: ')

def s():
	print 'this is a test'

def log(f):
	def fn(*args, **kw):
		print '\nCall: ' + f.__name__ + '()'
		print 'The maximun num is:'
		return f(*args, **kw)
	return fn

def f(n1, n2):
	return maxi(n1, n2)

print f(num1, num2)


@log
def f(n1, n2):
	return maxi(n1, n2)

print f(num1, num2)

