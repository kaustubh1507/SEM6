class MyClass:
    def __init__(self):
        self.symptoms = ['Fever','Cough','Bleeding','Sneezing', 'Low platelets']
        self.diseases ={
            "Viral":['Fever','Cough', 'Sneezing'],
            "Typhoid":['Cough'],
            "Dengue": ['Fever','Low platelets'],
            "Ebola":['Fever','Cough','Bleeding'],
        }

    def getSymptoms(self):
        ls = []
        for symptom in self.symptoms:
            res = input(f"Do you have {symptom}? (y/n) : ")
            if(res.lower()=='y'):
                ls.append(symptom)
        return ls
    
    def predictDisease(self):
        possibleDisease = []
        userSymptom = self.getSymptoms()
        for disease, symptoms in self.diseases.items():
            if any (symptom in userSymptom for symptom in symptoms):
                possibleDisease.append(disease)
        print(possibleDisease)

c = MyClass()
c.predictDisease()