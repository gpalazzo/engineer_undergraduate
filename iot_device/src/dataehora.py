import pytz
from datetime import datetime

def salva_dataehora():

    naive_data = datetime.now()
    utc = pytz.timezone('UTC')
    aware_date = utc.localize(naive_data)
    brt_timezone = pytz.timezone('America/Sao_Paulo')
    brt_date = aware_date.astimezone(brt_timezone)

    data_hora_db = brt_date.strftime("%Y-%m-%d %H:%M:%S")

    return data_hora_db
