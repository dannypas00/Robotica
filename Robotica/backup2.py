import speech_recognition as sr
sr.__version__



r1 = sr.Recognizer()
r2 = sr.Recognizer()
r3 = sr.Recognizer()

# Pakt je microfoon als input en luistert, waarna hij hem door de google speech haalt.
with sr.Microphone() as source:
    #print('speak now')
    audio = r3.listen(source)
    try:
       get = r2.recognize_google(audio)
       #print("Command was: " + (get))
    except sr.UnknownValueError:
       print('error')
    except sr.RequestError as e:
       print('failed'.format(e))

print(get)

#if get == 'Drive forward':
    #Hier komt dan de code die hij moet aanroepen om vooruit te rijden.
    #print('Well done!')
