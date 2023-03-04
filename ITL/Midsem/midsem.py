inpstr = input('Enter the string: ')
lst = []
for i in range(len(inpstr)):
	if len(lst)==0:
		lst.append(inpstr[i])
	elif (lst[len(lst)-1] == '(' and inpstr[i] ==')') or (lst[len(lst)-1] == '[' and inpstr[i] ==']') or (lst[len(lst)-1] == '{' and inpstr[i] =='}'):
		lst.pop()
	else:
		lst.append(inpstr[i])

if len(lst) == 0:
	print('Balanced')
else:
	print('Unbalanced')
