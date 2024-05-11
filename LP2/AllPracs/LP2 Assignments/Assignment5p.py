import re
import random
class MyClass:
    
    def __init__(self):
        self.responses = {
        "greetings":['Hello','Hi'],
        "screen":['Replacement at shop', 'We offer a wide variety at shop'],
        "battery" : ['New battery installation at service center', ' Visit service center for a new battery'],
        "cover":['To buy a new cover visit nearest shop', ' Visit shop to buy accessories'],
        "default" : ['Kindly reframe','I did not understand'],
    }

    def systemResponse(self, request):
        # request = request.lower()
        if re.search(r"\b(?:hello|hi)\b", request):
            return random.choice(self.responses['greetings'])
        elif re.search(r"\b(?:screen|broken)\b", request):
            return random.choice(self.responses['screen'])
        elif re.search(r"\b(?:battery|charging)\b", request):
            return random.choice(self.responses['battery'])
        elif re.search(r"\b(?:guard|cover)\b", request):
            return random.choice(self.responses['cover'])
        else:
            return random.choice(self.responses['default'])

c = MyClass()    
print("Welcome to Customer Service")
while(True):
    req = input("How may I help you? (Type 'exit' to Exit)")
    req = req.lower()
    if (req=="exit"):
        break
    res = c.systemResponse(req)
    print(res)

print("Thank You for using!")
    