symptoms = ['Fever', 'Cough', 'Headache', 'Sore throat']
diseases = {
    'Common Cold': ['Fever', 'Cough', 'Headache', 'Sore throat'],
    'Flu': ['Fever', 'Cough', 'Headache'],
    'Strep Throat': ['Fever', 'Sore throat'],
    'Migraine': ['Headache']
}

def getUserInput():
    userSymptoms=[]
    for symptom in symptoms:
        response = input(f"Do you have {symptom}? (y/n)")
        if response.lower()=='y':
            userSymptoms.append(symptom)
    return userSymptoms

def diagnose():
    userSymptoms = getUserInput()
    possibleDiseases=[]

    for disease, symptom in diseases.items():
        if any (symptom in userSymptoms for symptom in symptom):
            possibleDiseases.append(disease)
        
    if possibleDiseases:
        print("Possible Diseases : ")
        for disease in possibleDiseases:
            print(" "+disease)
    else:
        print("No matching disease found.")

if __name__=="__main__":
    diagnose()