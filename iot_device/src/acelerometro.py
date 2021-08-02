import time
import Adafruit_ADXL345

accel = Adafruit_ADXL345.ADXL345()

def coleta_dados_adxl345():

    i = 0
    eixo_x = []
    eixo_y = []
    eixo_z = []

    while i < 5:
        x, y, z = accel.read()
        eixo_x.append(x)
        eixo_y.append(y)
        eixo_z.append(z)
        i += 1
        time.sleep(0.5)

    return eixo_x, eixo_y, eixo_z

def analisa_dados(lista_x, lista_y, lista_z):

    soma_x, soma_y, soma_z = 0, 0, 0

    for valor_x in lista_x:
        soma_x += valor_x

    for valor_y in lista_y:
        soma_y += valor_y

    for valor_z in lista_z:
        soma_z += valor_z

    lista_medias = [soma_x / float(len(lista_x)), soma_y / float(len(lista_y)), soma_z / float(len(lista_z))]

    if lista_medias[0] > 15 or lista_medias[1] > 15 or lista_medias[2] > 15:
        return "Acordado"
    else:
        return "Dormindo"

def salva_status_paciente():
    eixo_x, eixo_y, eixo_z = coleta_dados_adxl345()
    status = analisa_dados(eixo_x, eixo_y, eixo_z)
    time.sleep(0.5)
    return status

