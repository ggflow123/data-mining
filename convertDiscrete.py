import csv
import random
import sys
def findContinuous(rows):
    length = len(rows[0])
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
    datafile=sys.argv[1]
    with open(datafile,"r",encoding="utf-8") as file:
        reader=csv.reader(file)
        rows=list(reader)
    cont = findContinuous(rows)
    discrete = findDiscrete(rows,cont)
    for col in range(len(rows[0])):
        if cont[col]:
            continue
        for row in range(len(rows)):
            rows[row][col]=discrete[col].index(rows[row][col])
    datafile_edit=datafile.split('.')[0] + '_edit.csv'
    with open(datafile_edit,mode='w') as dfe: #datafile_edit
        dfe_writer=csv.writer(dfe,delimiter=',',lineterminator='\n')
        dfe_writer.writerows(rows)


if __name__=="__main__":
    main()
