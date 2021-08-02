import time
import ds18b20
import dataehora
import db_scripts
import sensor_max30100
import ttp223
import display_oled

def main():

    db_scripts.deleta_tabela()
    db_scripts.cria_tabela()

    sist_ligado = ttp223.verifica_estado_sistema()

    if (sist_ligado):
        display_oled.imprime_msg_ligando()

    while (sist_ligado):
        sist_ligado = ttp223.verifica_estado_sistema()
        #print("Sistema ligado...")
        dados = coleta_dados()
        db_scripts.insere_dados(dados)
        temp_media = db_scripts.salva_temp_media()
        menor_temp, maior_temp = db_scripts.menor_e_maior_valor_temp()
        datahora, temp_atual, bpm, spo2, status_paciente = db_scripts.leitura_dados()
        #display_oled.carrega_layout_padrao()
        time.sleep(0.2)
        display_oled.carrega_layout_padrao()
        display_oled.atualiza_valores(datahora, temp_atual, menor_temp, maior_temp, spo2, bpm, status_paciente)
        #print(datahora, temp_atual, temp_media, bpm, spo2, status_paciente, menor_temp, maior_temp)

        time.sleep(1)

    display_oled.imprime_msg_desligando()
    #print("Sistema desligado...")
    time.sleep(1)
    main()

def coleta_dados():
    lista_dados = [dataehora.salva_dataehora(), ds18b20.salva_temp(), sensor_max30100.salva_bpm(),
                   sensor_max30100.salva_spo2(), "Acordado"]
    return lista_dados

if __name__ == '__main__':
    main()
