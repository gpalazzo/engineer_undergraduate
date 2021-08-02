import requests
from time import sleep

TOKEN = "my_token"
DEVICE_LABEL = "DrAssist"
VARIABLE_LABEL_1 = "temperatura"
VARIABLE_LABEL_2 = "temperatura-media"
VARIABLE_LABEL_3 = "bpm"
VARIABLE_LABEL_4 = "spo2"
VARIABLE_LABEL_5 = "status-paciente"

def build_payload(temp_atual, temp_media, bpm, spo2, status_paciente):
    # Creates two random values for sending data
    payload = {
        VARIABLE_LABEL_1: temp_atual,
        VARIABLE_LABEL_2: temp_media,
        VARIABLE_LABEL_3: bpm,
        VARIABLE_LABEL_4: spo2,
        VARIABLE_LABEL_5: status_paciente}

    return payload


def post_request(payload):
    # Creates the headers for the HTTP requests
    url = "http://industrial.api.ubidots.com/api/v1.6/"
    url = "{}devices/{}".format(url, DEVICE_LABEL)
    headers = {"X-Auth-Token": TOKEN, "Content-Type": "application/json"}

    # Makes the HTTP requests
    status = 400
    attempts = 0
    while status >= 400 and attempts <= 5:
        req = requests.post(url=url, headers=headers, json=payload)
        status = req.status_code
        attempts += 1
        sleep(1)

    # Processes results
    if status >= 400:
        print("[ERROR] Could not send data after 5 attempts, please check\
            your token credentials and internet connection")
        return False

    print("[INFO] request made properly, your device is updated")
    return True
