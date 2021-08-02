import Adafruit_SSD1306
from PIL import Image, ImageDraw, ImageFont
from time import sleep

RST = 24

disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)
disp.begin()
width = disp.width
height = disp.height

disp.clear()
disp.display()

image1 = Image.new('1', (width, height))
font = ImageFont.load_default()
draw = ImageDraw.Draw(image1)
draw.rectangle((0, 0, width, height), outline=0, fill=0)

def carrega_layout_padrao():
    disp.clear()
    draw.rectangle((0, 0, width, height), outline=0, fill=0)

    draw.text((0, 24), "T:", font=font, fill=255)
    #draw.text((11, 15), temp_atual, font=font, fill=255)
    draw.text((42, 24), "C", font=font, fill=255)

    draw.text((67, 15), "L", font=font, fill=255)
    draw.text((101, 15), "H", font=font, fill=255)
    draw.text((50, 24), "(", font=font, fill=255)
    #draw.text((55, 15), temp_min, font=font, fill=255)
    draw.text((84, 24), "/", font=font, fill=255)
    #draw.text((90, 15), temp_max, font=font, fill=255)
    draw.text((119, 24), ")", font=font, fill=255)

    draw.text((0, 34), "SpO2:", font=font, fill=255)
    #draw.text((29, 25), spo2, font=font, fill=255)
    draw.text((42, 34), "%", font=font, fill=255)
    draw.text((0, 44), "BPM:", font=font, fill=255)
    #draw.text((23, 35), bpm, font=font, fill=255)
    draw.text((0, 54), "Status:", font=font, fill=255)
    #draw.text((41, 45), status_paciente, font=font, fill=255)
    disp.image(image1)
    disp.display()

def imprime_msg_ligando():
    disp.clear()
    draw.rectangle((0, 15, width, height), outline=0, fill=0)
    msg = "Ligando..."
    draw.text((0, 0), msg, font=font, fill=255)
    disp.image(image1)
    disp.display()
    sleep(1)
    msg = "Configurando..."
    draw.text((0, 25), msg, font=font, fill=255)
    disp.image(image1)
    disp.display()

def imprime_msg_desligando():
    disp.clear()
    draw.rectangle((0, 0, width, height), outline=0, fill=0)
    msg = "Desligado..."
    draw.text((0, 0), msg, font=font, fill=255)
    disp.image(image1)
    disp.display()

def atualiza_valores(datahora, temp_atual, temp_min, temp_max, spo2, bpm, status_paciente):

    datahora = str(datahora)
    temp_atual = str(temp_atual)
    temp_min = str(temp_min)
    temp_max = str(temp_max)
    spo2 = str(spo2)
    bpm = str(bpm)

    draw.text((0, 0), datahora, font=font, fill=255)
    draw.text((11, 24), temp_atual, font=font, fill=255)
    draw.text((55, 24), temp_min, font=font, fill=255)
    draw.text((90, 24), temp_max, font=font, fill=255)
    draw.text((29, 34), spo2, font=font, fill=255)
    draw.text((23, 44), bpm, font=font, fill=255)
    draw.text((41, 54), status_paciente, font=font, fill=255)

    disp.image(image1)
    disp.display()
