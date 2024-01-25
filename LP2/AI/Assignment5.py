# Install the ChatterBot library
# pip install chatterbot

from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer

# Create a chatbot instance
bot = ChatBot('BasicBot')

# Create a new trainer for the chatbot
trainer = ChatterBotCorpusTrainer(bot)

# Train the chatbot on English language data
trainer.train('chatterbot.corpus.english')

# Define a function to interact with the chatbot
def chat_with_bot():
    print("Hello! I'm your basic chatbot. You can start chatting with me. Type 'exit' to end the conversation.")

    while True:
        user_input = input("You: ")
        
        if user_input.lower() == 'exit':
            print("Goodbye!")
            break
        
        response = bot.get_response(user_input)
        print(f"Bot: {response}")

# Start the chat
chat_with_bot()
