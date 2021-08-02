import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)

pino_ttp223 = 26
pino_ligasistema = 27
pino_buzzer_teste = 19
sistema_ligado = False

GPIO.setup(pino_ttp223, GPIO.IN)
GPIO.setup(pino_ligasistema, GPIO.OUT)

def verifica_estado_sistema():

    if (GPIO.input(pino_ttp223) == True) and not sistema_ligado: #1a verificacao para ligar o sistema;
        #print("Toque detectado")
        sleep(3)
        if GPIO.input(pino_ttp223) == True:
            global sistema_ligado
            sistema_ligado = not sistema_ligado
            #print("Ligando sistema...")
            GPIO.output(pino_ligasistema, 1)
            return True
        else:
            GPIO.output(pino_ligasistema, 0)
            #print("Sistema nao iniciado, aguarde aviso de sistema ligado para soltar o dedo")
            return False

    elif (GPIO.input(pino_ttp223) == False) and sistema_ligado: #1a verificacao para desligar o sistema;
        #print("Toque detectado")
        sleep(2)
        if GPIO.input(pino_ttp223) == False:
            global sistema_ligado
            sistema_ligado = not sistema_ligado
            #print("Desligando sistema...")
            GPIO.output(pino_ligasistema, 0)
            return False
        else:
            #print("Sistema nao foi desligado, aguarde aviso de sistema desligado para soltar o dedo")
            GPIO.output(pino_ligasistema, 1)
            return True

    elif (GPIO.input(pino_ttp223) == True) and sistema_ligado: #verificacao para manter o estado HIGH do sistema;
        #print("Mantendo o sistema ligado...")
        GPIO.output(pino_ligasistema, 1)
        return True

    else: #verificacao para manter o estado LOW do sistema;
        #print("Mantendo o sistema desligado...")
        GPIO.output(pino_ligasistema, 0)
        return False

    sleep(0.1)
