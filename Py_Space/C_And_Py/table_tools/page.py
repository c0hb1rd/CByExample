def Html_table(D):
	def table(name, score):
		return '<tr><td>%s</td><td>%s</td></tr>' % (name, score)
	l = []
	for n, s in D.iteritems():
		l.append(table(n, s))
	th = '<tr><th>name</th><th>score</th></tr>'
	print '<table border="1">'
	print th
	print '\n'.join(l)
	print '</table>'

D = {}
Ran = raw_input()
Ran = int(Ran)
name = ''
score = ''
name, score = raw_input(), raw_input()
D[name] = score
for i in range(1, Ran):
	name, score = raw_input(), raw_input()
	D[name] = score

Html_table(D)
