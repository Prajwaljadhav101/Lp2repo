import csv

def load_rule(file_path):
    rules=[];
    with open(file_path,'r') as csvFile:
        reader=csv.DictReader(csvFile)
        for row in reader:
            rules.append(row)
    return rules
    

def expert_system(flight,rules):
    for rule in rules:
        d1=rule['condition']
    
        if(flight==d1):
            print(rule['condition'])
            return rule['consequences']
    return "no flight";
    
rule=load_rule('sample.csv')
city=input("enter city");
print(expert_system(city,rule))