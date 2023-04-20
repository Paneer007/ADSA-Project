import csv
import names
import random
import string

NumberOfUsers = 100
NumberOfRelations = 2500
NumberOfInterest_LowerLimit = 5
NumberOfInterest_HigherLimit = 10
noOfUserList = list(range(1, NumberOfUsers+1))


# csv fields
userFields = ['id', 'name', 'region', 'age', 'institution', 'password']
relationFields = ['id', 'person1', 'person2']
hashtagsFields = ['id', 'value', 'userid']
celebFields = ['id', 'account']

# csv names
user_filename = "./data/seeds/user.csv"
relation_filename = "./data/seeds/relation.csv"
hashtags_filename = "./data/seeds/hashtags.csv"
celeb_filename = "./data/seeds/celebs.csv"

# user data params
regionList = ["Andhra Pradesh",
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

# hashtags params
hashtagsList = [
    "ThrowbackThursday",
    "FlashbackFriday",
    "MotivationMonday",
    "TransformationTuesday",
    "WisdomWednesday",
    "SelfieSunday",
    "SundayFunday",
    "MondayBlues",
    "TGIF",
    "FOMO",
    "OOTD",
    "FitnessMotivation",
    "Foodie",
    "Travelgram",
    "Instagood",
    "PicOfTheDay",
    "TBT",
    "FBF",
    "WCW",
    "MCM",
    "WomenCrushWednesday",
    "ManCrushMonday",
    "BlackLivesMatter",
    "MeToo",
    "LoveWins",
    "Pride",
    "ClimateStrike",
    "Vote",
    "COVID19",
    "StayHome",
    "MaskUp",
    "VaccinesWork",
    "ShopSmall",
    "SupportLocal",
    "GiveBack",
    "DoGood",
    "KindnessMatters",
    "Grateful",
    "Blessed",
    "Goals",
    "BTS",
    "HarryStyles",
    "Adele",
    "TaylorSwift",
    "Drake",
    "Beyonce",
    "Kardashians",
    "GameOfThrones",
    "StrangerThings",
    "TheCrown",
    "TigerKing",
    "Hamilton",
    "DisneyPlus",
    "NetflixAndChill",
    "Podcast",
    "Bookstagram",
    "Art",
    "Fashion",
    "InteriorDesign",
    "DIY",
    "Gardening",
    "PetsOfInstagram",
    "Nature",
    "Sunset",
    "Cityscape",
    "Adventure",
    "Wanderlust",
    "BeachLife",
    "RoadTrip",
    "Camping",
    "Sustainability",
    "FairTrade",
    "Organic",
    "FarmToTable",
    "Vegan",
    "GlutenFree",
    "PlantBased",
    "Keto",
    "Paleo",
    "IntermittentFasting",
    "FitnessJourney",
    "WorkoutMotivation",
    "Yoga",
    "Meditation",
    "HealthyEating",
    "Mindfulness",
    "Entrepreneur",
    "Leadership",
    "Innovation",
    "Marketing",
    "DigitalMarketing",
    "ContentMarketing",
    "SocialMediaMarketing",
    "SEO",
    "EmailMarketing",
    "BrandBuilding",
    "CustomerExperience",
    "CustomerService",
    "SmallBusiness",
    "Startup",
    "RemoteWork",
    "Productivity"
]


# Attribute Params
institutionsList = [
    "Harvard University",
    "Stanford University",
    "Massachusetts Institute of Technology (MIT)",
    "California Institute of Technology (Caltech)",
    "Princeton University",
    "University of Cambridge",
    "University of Oxford",
    "Yale University",
    "Columbia University",
    "University of Chicago",
    "Amazon",
    "Apple",
    "Google",
    "Microsoft",
    "Facebook",
    "Intel",
    "Oracle",
    "IBM",
    "Cisco Systems",
    "Dell Technologies",
    "HP Inc.",
    "Hewlett Packard Enterprise",
    "Lenovo",
    "NVIDIA",
    "Tesla",
    "Qualcomm",
    "AMD",
    "PayPal",
    "Salesforce",
    "Twitter",
    "Uber",
    "Airbnb",
    "Lyft",
    "Netflix",
    "Snap",
    "Square",
    "Zoom Video Communications",
    "Slack Technologies",
    "Atlassian",
    "Dropbox",
    "Workday",
    "DocuSign",
    "Adobe",
    "Autodesk",
    "Salesforce",
    "ServiceNow",
    "Splunk",
    "Twilio",
    "Zillow Group",
    "Akamai Technologies",
    "Analog Devices",
    "Applied Materials",
    "ASML",
    "Broadcom",
    "Cadence Design Systems",
    "Cisco Systems",
    "Dell Technologies",
    "Ericsson",
    "Fortinet",
    "Hewlett Packard Enterprise",
    "Keysight Technologies",
    "Micron Technology",
    "NXP Semiconductors",
    "ON Semiconductor",
    "Qorvo",
    "Seagate Technology",
    "Silicon Laboratories",
    "Skyworks Solutions",
    "Synopsys",
    "Teradyne",
    "Texas Instruments",
    "Western Digital",
    "Xilinx",
    "Qualtrics",
    "ServiceNow",
    "Snowflake",
    "Unity Technologies",
    "Zscaler",
    "SquareSpace",
    "GitHub",
    "Datadog",
    "MongoDB",
    "PagerDuty",
    "Atlassian",
    "Box",
    "AppDynamics",
    "Dynatrace",
    "New Relic",
    "Cloudflare",
    "Okta",
    "Splunk",
    "Tenable",
    "Twilio",
    "Zoom Video Communications",
    "Elastic",
    "JFrog",
    "PagerDuty",
    "CrowdStrike",
    "Fastly",
    "Palantir Technologies",
    "UiPath",
    "Darktrace"
]

CelebsList = [
    'instagram',
    'cristiano',
    'therock',
    'kyliejenner',
    'kimkardashian',
    'leomessi',
    'beyonce',
    'justinbieber',
    'kendalljenner',
    'natgeo',
    'neymarjr',
    'arianagrande',
    'taylorswift',
    'jlo',
    'nike',
    'khloekardashian',
    'mileycyrus',
    'katyperry',
    'kourtneykardash',
    'ddlovato',
    'virat.kohli',
    'fcbarcelona',
    'theellenshow',
    'zendaya',
    'nickiminaj',
    'badgalriri',
    '9gag',
    'shakira',
    'realmadrid',
    'nasa',
    'deepikapadukone',
    'chrisbrownofficial',
    'nba',
    'champagnepapi',
    'shawnmendes',
    'victoriassecret',
    'billieeilish',
    'emmawatson',
    'kevinhart4real',
    'selenagomez',
    'gigihadid',
    'jamesrodriguez10',
    'ronaldo',
    'lelepons',
    'jamescharles',
    'davidbeckham',
    'hudabeauty',
    'caradelevingne',
    'blakelively',
    'kourtneykardashian',
    'real__pcy',
    'anushkasharma',
    'zacefron',
    'chanelofficial',
    'blonded',
    'garethbale11',
    'ronaldinho',
    'twhiddleston',
    'k.mbappe',
    'milliebobbybrown',
    'ladygaga',
    'robertdowneyjr',
    'marvelstudios',
    'iamzlatanibrahimovic',
    'bellahadid',
    'maluma',
    'iamcardib',
    'willsmith',
    'aliaabhatt',
    'emmastone',
    'johnnydepp',
    'daddyyankee',
    'natashanorris',
    'zidane',
    'snoopdogg',
    'priyankachopra',
    'krisjenner',
    'leonardodicaprio',
    'jasonstatham',
    'rogerfederer',
    'danbilzerian',
    'emrata',
    'zayn',
    'realmadridwomen',
    'virginieviard',
    'britneyspears',
    'luisfonsi',
    'mileycyrus',
    'kaka',
    'paulpogba',
    'tylerperry',
    'gisele',
    'dualipa',
    'jessicaalba',
    'danielwellington',
    'taeyeon_ss',
    'jenniferaniston',
    'salmahayek',
    'djkhaled',
    'lucyhale',
    'maluma',
    'harrystyles',
    'blackpinkofficial',
    'adele',
    'maddieziegler',
    'margotro'
]

ageList = list(range(18, 65))


# User Array
users = []

# Relation Array
relations = []

# HashTag Array
hashtags = []

# Celeb Array
celebarr = []

# Support Functions

'''
    Generate Users
'''


def GenerateUsers():
    for i in range(NumberOfUsers):
        name = names.get_first_name()
        age = random.choice(ageList)
        region = random.choice(regionList)
        institute = random.choice(institutionsList)
        password = "password"
        users.append([i+1, name, age, region, institute, password])
    return


'''
    GenerateRelation()
'''


def GenerateRelation():
    for i in range(NumberOfRelations):
        index = random.choice(noOfUserList)
        otherIndex = random.choice(noOfUserList)
        relations.append([i+1, index, otherIndex])
    return


def GenerateInterest():
    count = 1
    for i in users:
        number_of_interest = random.randint(
            NumberOfInterest_LowerLimit, NumberOfInterest_HigherLimit)
        for x in range(number_of_interest):
            HashTag = random.choice(hashtagsList)
            hashtags.append([count, HashTag, i[0]])
            count += 1


def GenerateCelebs():
    count = 1
    celeb_sample = random.sample(CelebsList, 10)
    for i in celeb_sample:
        celebarr.append([count, i])
        count += 1
    print(celebarr)


def GenerateUserCSV():
    with open(user_filename, "w") as userfile:
        csvwriter = csv.writer(userfile)
        csvwriter.writerow(userFields)
        csvwriter.writerows(users)
    return


def GenerateRelationCSV():
    with open(relation_filename, "w") as relational:
        csvwriter = csv.writer(relational)
        csvwriter.writerow(relationFields)
        csvwriter.writerows(relations)
    return


def GenerateUserInterestCSV():
    with open(hashtags_filename, "w") as hashtagsContext:
        csvwriter = csv.writer(hashtagsContext)
        csvwriter.writerow(hashtagsFields)
        csvwriter.writerows(hashtags)


def GenerateCelebsCSV():
    with open(celeb_filename, "w") as celebsContext:
        celebcontext = csv.writer(celebsContext)
        celebcontext.writerow(celebFields)
        celebcontext.writerows(celebarr)


def generateCSV():
    GenerateCelebs()
    GenerateUsers()
    GenerateRelation()
    GenerateInterest()
    GenerateCelebsCSV()
    GenerateUserCSV()
    GenerateRelationCSV()
    GenerateUserInterestCSV()
    return


generateCSV()
