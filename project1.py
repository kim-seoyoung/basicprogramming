#!/usr/bin/env python
# coding: utf-8




import sys

if len(sys.argv) == 2:
    file = open(sys.argv[1], 'r')
    contents = file.read()
    file.close()
else:
    file = open('students.txt', 'r')
    contents = file.read()
    file.close()


def grade(x):
    if dic[x][3] >= 90:
        y = 'A'
    elif dic[x][3] >= 80:
        y = 'B'
    elif dic[x][3] >= 70:
        y = 'C'
    elif dic[x][3] >= 60:
        y = 'D'
    else:
        y = 'F'

    return y





con = contents.split('\n')
con.remove('')
cont = []
dic = {}

for i in range(5):
    cont += con[i].split('\t')

for i in range(5):
    dic[cont[4 * i]] = [cont[4 * i + j] for j in range(1, 4)]
    dic[cont[4 * i]].append((int(dic[cont[4 * i]][1]) + int(dic[cont[4 * i]][2])) / 2)
    dic[cont[4 * i]].append(grade(cont[4*i]))

keys = sorted(dic, key=lambda k: int(dic[k][3]), reverse=True)
cols = ['Student', 'Name', 'Miderm', 'Final', 'Average', 'Grade']
print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(*cols), '\n', '---' * 21)
for k in keys:
    print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(k, *dic[k]))







def show():
    keys = sorted(dic, key=lambda k: int(dic[k][3]), reverse=True)
    print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(*cols), '\n', '---' * 21)
    for k in keys:
        print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(k, *dic[k]))




def changescore():
    ID = input('student ID:')

    if ID in list(dic.keys()):
        term = input('Mid/Final?')
        if term == 'mid':
            new = input('Input new score')
            if 0 <= int(new) <= 100:
                print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(*cols), '\n', '---' * 21)
                print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(ID, *dic[ID]))
                print('Score changed')
                dic[ID][1] = new
                dic[ID][3] = (int(dic[ID][1]) + int(dic[ID][2])) / 2
                dic[ID][4] = grade(ID)
                print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(ID, *dic[ID]))
        elif term == 'final':
            new = input('Input new score')
            if 0 <= int(new) <= 100:
                print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(*cols), '\n', '---' * 21)
                print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(ID, *dic[ID]))
                print('Score changed')
                dic[ID][2] = new
                dic[ID][3] = (int(dic[ID][1]) + int(dic[ID][2])) / 2
                dic[ID][4] = grade(ID)
                print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(ID, *dic[ID]))

    else:
        print('NO SUCH PERSON')




def search():
    ID = input('student ID:')

    if ID in keys:
        print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(*cols), '\n', '-' * 63)
        print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(ID, *dic[ID]))
    else:
        print('NO SUCH PERSON')





def searchgrade():
    grade = input('Grade to search:')
    stu = len(list(dic.keys()))

    if grade == 'A' or grade == 'B' or grade == 'C' or grade == 'D' or grade == 'F':

        for ID in list(dic.keys()):
            if dic[ID][4] != grade:
                stu -= 1
        if stu == 0:
            print('NO RESULTS.')
        else:
            print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(*cols), '\n', '---' * 21)
            for ID in list(dic.keys()):
                if dic[ID][4] == grade:
                    print('{:>10} {:>14} {:^8} {:^8} {:^8} {:^8}'.format(ID, *dic[ID]))





def add():
    ID = input('Student ID:')

    if ID in list(dic.keys()):
        print('ALREADY EXISTS.')
    else:
        name = input('Name:')
        midscore = input('Midterm Score:')
        finscore = input('Final Score:')
        dic[ID] = [name, midscore, finscore, (int(midscore) + int(finscore)) / 2]
        dic[ID].append(grade(ID))
        print('Student added.')




def remove():
    if list(dic.keys()) == []:
        print('List is empty.')
    else:
        ID = input('Student ID:')
        if ID in list(dic.keys()):
            del dic[ID]
            print('Student removed')
        else:
            print('NO SUCH PERSON')





def quit():
    yn = input('Save data?[yes/no]')

    if yn == 'yes':
        new_contents = ''
        for ID in list(dic.keys()):
            new_contents += ID
            new_contents += '\t' + dic[ID][0]
            new_contents += '\t' + dic[ID][1]
            new_contents += '\t' + dic[ID][2] + '\n'

        na = input('File name:')
        new_file = open(na, 'w')
        new_file.write(new_contents)
        new_file.close()


com_list = ['show()', 'search()', 'changescore()', 'searchgrade()', 'add()', 'remove()', 'quit()']

while True:
    com = input('# ').lower() + '()'
    if com == 'quit()':
        eval(com)
        break
    elif com in com_list:
        eval(com)
