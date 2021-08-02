import sqlite3

def cria_tabela():

    try:
        cnn = sqlite3.connect('dados.db')
        cursor = cnn.cursor()
        sql_code = """CREATE TABLE tbl_dados(
                   id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
                   data DATE,
                   temp DOUBLE,
                   spo2 INTEGER,
                   hr INTEGER,
                   status VARCHAR(8));"""
        cursor.execute(sql_code)
    except sqlite3.Error:
        print("Tabela ja existe.")

    cnn.close()

def insere_dados(dados):
    cnn = sqlite3.connect('dados.db')
    cursor = cnn.cursor()

    sql_code = """INSERT INTO tbl_dados (data, temp, spo2, hr, status) 
                  VALUES (?, ?, ?, ?, ?);"""

    cursor.execute(sql_code, dados)

    cnn.commit()
    cnn.close()

def salva_temp_media():

    cnn = sqlite3.connect('dados.db')
    cursor = cnn.cursor()

    sql_code = """SELECT avg(temp) 
                  FROM tbl_dados;"""

    cursor.execute(sql_code)
    temp_media = cursor.fetchone()
    temp_media = float(temp_media[0])
    return temp_media


def leitura_dados():
    '''
    Para pegar linha a linha de dados, basta usar:
    for linha in cursor.fetchall():
        print(linha)
    '''
    cnn = sqlite3.connect('dados.db')
    cursor = cnn.cursor()

    sql_code = """SELECT * 
                  FROM tbl_dados;"""

    cursor.execute(sql_code)
    dados = cursor.fetchall().pop()
    datahora = dados[1]
    spo2 = dados[3]
    bpm = dados[4]
    status_paciente = dados[5]
    status_paciente = str(status_paciente)
    datahora = str(datahora)
    temp_atual = dados[2]

    return datahora, temp_atual, bpm, spo2, status_paciente

def deleta_tabela():

    cnn = sqlite3.connect('dados.db')
    cursor = cnn.cursor()

    sql_code = "DROP TABLE IF EXISTS tbl_dados;"
    cursor.execute(sql_code)

def menor_e_maior_valor_temp():

    cnn = sqlite3.connect('dados.db')
    cursor = cnn.cursor()

    sql_code = """SELECT min(temp), max(temp)
                  FROM tbl_dados;"""

    cursor.execute(sql_code)

    temperaturas = cursor.fetchone()
    menor_temp = float(temperaturas[0])
    maior_temp = float(temperaturas[1])

    return menor_temp, maior_temp
