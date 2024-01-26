import headset
from headset import Headset
import serial
import time
import threading

def getCredentials():
    file = open('pass.txt', 'r')

    credentials = {}

    credentials["token"] = file.readline().strip().replace('token: ', '')

    credentials["id"] = file.readline().strip().replace('id: ', '')

    credentials["profile_name"] = file.readline().strip().replace('profile_name: ', '')

    file.close()
    return credentials


def my_callback(data):
    ser = serial.Serial('COM3', 9600)  # replace 'COM3' with the port where your Arduino is connected
    time.sleep(2)  # wait for the serial connection to initializ    e

    ser.write(data)  # send data to the Arduino

if __name__ == "__main__":
    credentials = getCredentials()

    client_id = credentials["id"]
    client_secret = credentials["token"]
    profile_name = credentials["profile_name"]

    try:
        headset = Headset(client_id, client_secret, callback=my_callback)
        headset.start(profile_name, "EPOCX-E5020776")
        print("Headset connected")
        headset.subscribe_data(['com'])
    except KeyboardInterrupt:
        print("Interrupted by user, stopping...")
    finally:
        print("Program stopped.")


    
