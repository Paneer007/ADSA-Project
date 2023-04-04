import csv
import names
import random

NumberOfUsers = 30

NumberOfRelations = 120

# csv fields
userFields=['id','name','region','age']
relationFields=['id','person1','person2']

# csv names
user_filename="./data/seeds/user.csv"
relation_filename="./data/seeds/relation.csv"


# user data params
regionList = [ "Andhra Pradesh",
        "Arunachal Pradesh",
        "Assam",
        "Bihar",
        "Chhattisgarh",
        "Goa",
        "Gujarat",
        "Haryana",
        "Himachal Pradesh",
        "Jammu and Kashmir",
        "Jharkhand",
        "Karnataka",
        "Kerala",
        "Madhya Pradesh",
        "Maharashtra",
        "Manipur",
        "Meghalaya",
        "Mizoram",
        "Nagaland",
        "Odisha",
        "Punjab",
        "Rajasthan",
        "Sikkim",
        "Tamil Nadu",
        "Telangana",
        "Tripura",
        "Uttarakhand",
        "Uttar Pradesh",
        "West Bengal",
        "Andaman and Nicobar Islands",
        "Chandigarh",
        "Dadra and Nagar Haveli",
        "Daman and Diu",
        "Delhi",
        "Lakshadweep",
        "Puducherry"]

ageList=list(range(18,65))
noOfUserList = list(range(1,NumberOfUsers+1))

# relation data params


# User Array
users=[]

# Relation Array
relations=[]


# Support Functions

'''
    Generate Users
'''
def GenerateUsers():
    for i in range(NumberOfUsers):
        name = names.get_first_name()
        age = random.choice(ageList)
        region = random.choice(regionList)
        users.append([i+1, name, age,region])
    return

'''
    GenerateRelation()
'''
def GenerateRelation():
    for i in range(NumberOfRelations):
        index = random.choice(noOfUserList)
        otherIndex= random.choice(noOfUserList)
        relations.append([i+1,index,otherIndex])
    return

def GenerateUserCSV():
    with open(user_filename,"w") as userfile:
        csvwriter = csv.writer(userfile) 
        csvwriter.writerow(userFields) 
        csvwriter.writerows(users)
    return

def GenerateRelationCSV():
    with open(relation_filename,"w") as relational:
        csvwriter = csv.writer(relational) 
        csvwriter.writerow(relationFields) 
        csvwriter.writerows(relations)
    return


def generateCSV():
    GenerateUsers()
    GenerateRelation()
    GenerateUserCSV()
    GenerateRelationCSV()
    return

generateCSV()