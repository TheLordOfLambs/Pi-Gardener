# -*- coding: utf-8 -*-

########################## Modules Import #####################################

import os      # blibliothèque permettant l'interaction système
import serial  # bibliothèque permettant la communication série
import time    # pour le délai d'attente entre les messages

###############################################################################


############################### Functions #####################################

def Arduino(nbre) : # Fonction de communication avec l'arduino
    
    ser = serial.Serial('/dev/ttyUSB0', 9600) # ls /dev/tty* to know where your Arduino is connected
    nbre = str(nbre)
    ser.write(nbre.encode())
    time.sleep(2)   # on attend un peu, pour que l'Arduino soit prêt.
    
    code = ser.readline().decode() # on converti le binaire en str
    liste = code.split()         # on nettoie notre chaine 
    valeur = liste[0]
    return valeur



def shutdown() :
    
    os.system("sudo shutdown -P now")


###############################################################################

######################## Network initialization ###############################

i = 0
print("Network initialization ...")

while i < 5 :
    ser = serial.Serial('/dev/ttyUSB0', 9600) 
    ser.write('9'.encode())                   # We send initialization sequence
    i = i+1
    time.sleep(1)

time.sleep(5)

##############################################################################

###############################################################################

volume_pot = 1.2       # Pot volume (liter)
debit_pompe = 1/920    # Pump debit (liter/sec)
humidite_ideale = 75  # Perfect soil moisture

###############################################################################

temperature = float(Arduino(1))
print('Température : ',temperature,'°C')
humidite_air = float(Arduino(2))
print("Humidité de l'air : ",humidite_air,"%")
humidite_sol = float(Arduino(3))
print("Humidité du sol : ",humidite_sol,"%")
luminosite = float(Arduino(4))
print("Luminosité : ",luminosite)


if abs(humidite_ideale - humidite_sol) > 10 :
    
    debit = 100*debit_pompe
    temps_arrosage = int((volume_pot * abs(humidite_ideale - humidite_sol))/(debit))
    print("le temps d'arrosage est de ",temps_arrosage,"s")
    Arduino(5) # indique à l'arduino qu'on va lancer la séquence d'arrosage
    print("Démarrage de la séquence d'arrosage ...")
    Arduino(temps_arrosage)   # indique à l'arduino le temps d'arrosage nécessaire
    

###############################################################################

###############################################################################
time.sleep(temps_arrosage + 5)

shutdown()
