import csv
import random
def findContinuous(rows):
    length = len(rows[0])
    for row in rows:
        if (len(row) != length):
            print(rows.index(row))
    cont=[True] * length
    for col in range(0,length):
        for row in rows:
            try:
                val=float(row[col])
            except ValueError:
                cont[col]=False
                break
    return cont

def findDiscrete(rows,cont):
    length = len(rows[0])
    discrete=[False] * length
    for col in range(length):
        if cont[col]:
            continue
        vals=[]
        for row in rows:
            val = row[col]
            if val not in vals:
                vals.append(val)
        vals.sort()
        discrete[col]=vals
    return discrete

def main():
    trainingPerc = argv[2]
    seed = argv[3]
    datafile=argv[1]
    with open(datafile,"r",encoding="utf-8") as file:
        reader=csv.reader(file)
        rows=list(reader)
    length = len(rows)
    indices = list(range(length))
    random.seed(seed)
    random.shuffle(indices)
    trainingElement = (length * trainingPerc) // 1
    cont = findContinuous(rows)
    discrete = findDiscrete(rows,cont)
    for col in range(len(rows[0])):
        if cont[col]:
            continue
        for row in range(len(rows)):
            rows[row][col]=discrete[col].index(rows[row][col])
    datafile_train=datafile.split('.')[0] + '_train.csv'
    datafile_test=datafile.split('.')[0] + '_test.csv'
    with open(datafile_train,mode='w') as dftr, open(datafile_test,mode='w') as dfte: #datafile_edit
        dftr_writer=csv.writer(dftr,delimiter=',',lineterminator='\n')
        dfte_writer=csv.writer(dfte,delimiter=',',lineterminator='\n')
        for i in range(length):
            if i > trainingElement:
                dfte_writer.writerow(rows[i])
            else:
                dftr_writer.writerow(rows[i])


main()
